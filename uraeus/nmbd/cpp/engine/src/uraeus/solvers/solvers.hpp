#pragma once

// Standard Library Includes.
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

// Local Libraries Includes.
#include "helpers.hpp"
#include "utilities.hpp"


// Declaring and Implementing the Solver class as a template class.
// Type T should be any Topology class type.
template <class T>
class Solver
{
public:
    T* model_ptr; // Intial pointer to the model object.

    double t;
    double step_size;
    Eigen::VectorXd time_array;

    std::vector<Eigen::VectorXd> pos_history;
    std::vector<Eigen::VectorXd> vel_history;
    std::vector<Eigen::VectorXd> acc_history;

    SparseBlock Jacobian;
    std::vector<int> jac_rows;
    std::vector<int> jac_cols;

    Eigen::VectorXd q;

public:

    Solver(){};

    Solver(T& model)
    {
        model_ptr = &model;
        Jacobian.resize(model.nc, model.n);

        for (size_t i = 0; i < model.jac_rows.size(); i++)
        {
            jac_rows.push_back(int(model.jac_rows(i)));
            jac_cols.push_back(int(model.jac_cols(i)));        
        }

        results_names[0] = "Positions";
        results_names[1] = "Velocities";
        results_names[2] = "Accelerations";
    };

    void set_time(double& t);
    void set_time_array(const double& duration, const double& spacing);

    Eigen::VectorXd eval_pos_eq();
    Eigen::VectorXd eval_vel_eq();
    Eigen::VectorXd eval_acc_eq();
    SparseBlock eval_jac_eq();

    void set_gen_coordinates(Eigen::VectorXd& q);
    void set_gen_velocities(Eigen::VectorXd& qd);
    void set_gen_accelerations(Eigen::VectorXd& qdd);

    void solve_constraints(Eigen::VectorXd& guess);
    void Solve();

    void ExportResultsCSV(std::string location, std::string name, int id);

private:
    std::map<int, std::vector<Eigen::VectorXd>*> results;
    std::map<int, std::string> results_names;

};


/** 
 * CLASS METHODS IMPLEMENTATION
 * ============================
*/

template<class T>
void Solver<T>::set_time(double& t)
{
    model_ptr-> t = t;
};

template<class T>
void Solver<T>::set_time_array(const double& duration, const double& spacing)
{
    if (duration > spacing)
    {   
        auto steps = duration/spacing;
        time_array = Eigen::VectorXd::LinSpaced(steps, 0, duration);
        step_size = spacing;
    }
    else if (duration < spacing)
    {
        time_array = Eigen::VectorXd::LinSpaced(spacing, 0, duration);
        step_size = duration/spacing;
    }
};

template<class T>
void Solver<T>::set_gen_coordinates(Eigen::VectorXd &q)
{   
    model_ptr->set_gen_coordinates(q);
};

template<class T>
void Solver<T>::set_gen_velocities(Eigen::VectorXd &qd)
{   
    model_ptr->set_gen_velocities(qd);
};

template<class T>
void Solver<T>::set_gen_accelerations(Eigen::VectorXd &qdd)
{   
    model_ptr->set_gen_accelerations(qdd);
};


template<class T>
Eigen::VectorXd Solver<T>::eval_pos_eq()
{   
    model_ptr->eval_pos_eq();
    return model_ptr->pos_eq;
};

template<class T>
Eigen::VectorXd Solver<T>::eval_vel_eq()
{   
    model_ptr->eval_vel_eq();
    return model_ptr->vel_eq;
};

template<class T>
Eigen::VectorXd Solver<T>::eval_acc_eq()
{   
    model_ptr->eval_acc_eq();
    return model_ptr->acc_eq;
};


template<class T>
SparseBlock Solver<T>::eval_jac_eq()
{   
    model_ptr->eval_jac_eq();
    SparseAssembler(Jacobian, jac_rows, jac_cols, model_ptr->jac_eq);
    return Jacobian;
};


template<class T>
void Solver<T>::solve_constraints(Eigen::VectorXd &guess)
{
    auto& model = *this-> model_ptr;
    
    // Creating a SparseSolver object.
    //std::cout << "Declaring SparseLU" << "\n";
    Eigen::SparseLU<SparseBlock> SparseSolver;

    //std::cout << "Setting Guess" << "\n";
    //std::cout << guess << "\n";
    set_gen_coordinates(guess);
    //std::cout << "Evaluating Pos_Eq " << "\n";
    auto b = eval_pos_eq();
    //std::cout << "Evaluating Jac_Eq " << "\n";
    auto A = eval_jac_eq();
    //std::cout << "Computing Matrix A " << "\n";
    SparseSolver.compute(A);

    //std::cout << "Solving for Vector b " << "\n";
    Eigen::VectorXd error = SparseSolver.solve(-b);

    //std::cout << "Entring While Loop " << "\n";
    int itr = 0;
    while (error.norm() >= 1e-5)
    {
        //std::cout << "Error e = " << error.norm() << "\n";
        guess += error;
        set_gen_coordinates(guess);
        b = eval_pos_eq();
        error = SparseSolver.solve(-b);

        if (itr%5 == 0 && itr!=0)
        {
            A = eval_jac_eq();
            SparseSolver.compute(A);
            error = SparseSolver.solve(-b);
        };

        if (itr>50)
        {
            std::cout << "ITERATIONS EXCEEDED!! => " << itr << "\n" ;
            break;
        };

        itr++;
    };
    
    this-> q = guess;
    SparseSolver.compute(eval_jac_eq());
};


template<class T>
void Solver<T>::Solve()
{
    std::cout << "Starting Solver ..." << "\n";
    Eigen::SparseLU<SparseBlock> SparseSolver;
    
    auto& dt = step_size;
    double t = 0;
    auto samples = time_array.size();
    
    //std::cout << "Setting Initial Position History" << "\n";
    pos_history.emplace_back(model_ptr-> q0);

    Eigen::VectorXd v0, vi, a0, ai, guess;

    pos_history.reserve(samples);
    vel_history.reserve(samples);
    acc_history.reserve(samples);

    //std::cout << "Computing Jacobian" << "\n";
    auto A = eval_jac_eq();
    SparseSolver.compute(A);

    //std::cout << "Solving for Velocity" << "\n";
    v0 = SparseSolver.solve(-eval_vel_eq());
    //std::cout << "Setting Generalized Velocities" << "\n";
    set_gen_velocities(v0);
    //std::cout << "Storing Generalized Velocities" << "\n";
    vel_history.emplace_back(v0);
    
    //std::cout << "Solving for Accelerations" << "\n";
    a0 = SparseSolver.solve(-eval_acc_eq());
    acc_history.emplace_back(a0);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end;

    //std::cout << "\nRunning System Kinematic Analysis: " << "\n";
    for (size_t i = 1; i < samples; i++)
    {
        print_progress(begin, samples, i);

        t = time_array(i) ;
        set_time(t) ;

        guess = pos_history[i-1]
              + vel_history[i-1] * dt
              + 0.5 * acc_history[i-1] * pow(dt, 2);

        solve_constraints(guess);
        set_gen_coordinates(q);

        vi = SparseSolver.solve(-eval_vel_eq());
        set_gen_velocities(vi);

        ai = SparseSolver.solve(-eval_acc_eq());
        
        pos_history.emplace_back(q);
        vel_history.emplace_back(vi);
        acc_history.emplace_back(ai);
    };

    results[0] = &pos_history;
    results[1] = &vel_history;
    results[2] = &acc_history;

    std::cout << "\n";
    std::cout << "Finished Solver ..." << "\n";

};


const static Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", ", ", "", "", "", ",");

template<class T>
void Solver<T>::ExportResultsCSV(std::string location, std::string name, int id)
{
    // declaring and initializing the needed variables
    auto& data = *(results[id]);
    auto& model = *model_ptr;
    std::ofstream results_file;

    std::map<int, std::string> ordered_indicies;
    for (auto x : model.indicies_map)
    {
        ordered_indicies[x.second] = x.first;
    };

    // Creating the system indicies string to be used as the fisrt line
    // in the .csv file
    std::string indicies = "";
    std::vector<std::string> coordinates{"x", "y", "z", "e0", "e1", "e2", "e3"};
    for (auto x : ordered_indicies)
    {
        auto body_name = x.second;
        for (auto& coordinate : coordinates)
        {
          indicies += body_name + "." + coordinate + "," ;
        };
    };

    // Opening the file as a .csv file.
    results_file.open (location + name + ".csv");
    
    // Inserting the first line to be the indicies of the system.
    results_file << ", " + indicies + "time\n";

    // Looping over the results and writing each line to the .csv file.
    int i = 0;
    for (auto x : data)
    {
        results_file << std::to_string(i) + ", ";
        results_file << x.transpose().format(CSVFormat) ;
        results_file << std::to_string(time_array(i)) + "\n";
        i += 1;
    };

    results_file.close();
    std::cout << "\n" << name << " results saved as : " << location + name + ".csv" << "\n";
    
};

