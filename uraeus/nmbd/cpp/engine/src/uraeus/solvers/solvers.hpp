#pragma once

// Standard Library Includes.
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

// Local Libraries Includes.
#include "helpers.hpp"
#include "utilities.hpp"

const static Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", ", ", "", "", "", ",");


// Declaring and Implementing the Solver class as a template class.
// Type T should be any Topology class type.
template <class T>
class Solver
{
public:
    Eigen::VectorXd q;
    Eigen::VectorXd qd;
    Eigen::VectorXd qdd;
    Eigen::VectorXd lgr;

    SparseBlock Jacobian;
    SparseBlock MassMatrix;

    T model;
    
    double t;
    double step_size;
    Eigen::VectorXd time_array;

    std::vector<Eigen::VectorXd> pos_history;
    std::vector<Eigen::VectorXd> vel_history;
    std::vector<Eigen::VectorXd> acc_history;
    std::vector<Eigen::VectorXd> lgr_history;
    std::vector<Eigen::VectorXd> rct_history;

    std::vector<int> jac_rows;
    std::vector<int> jac_cols;
    std::vector<int> mas_cols;

    Eigen::SparseLU<SparseBlock> SparseSolver;

public:

    Solver();

    void set_time(double& t);
    void set_time_array(const double& duration, const double& spacing);
    
    void initialize();

    Eigen::VectorXd eval_pos_eq();
    Eigen::VectorXd eval_vel_eq();
    Eigen::VectorXd eval_acc_eq();
    Eigen::VectorXd eval_frc_eq();

    void eval_rct_eq();
    void eval_jac_eq();
    void eval_mas_eq();

    void solve_lgr_multipliers();

    void solve_constraints(Eigen::VectorXd& guess);
    void Solve();

    void ExportResultsCSV(std::string location, std::string name, int id);
    void ExportReactionsResults(std::string location, std::string name);
    void ExportLagrangeMultipliers(std::string location, std::string name);


private:
    std::map<int, std::vector<Eigen::VectorXd>*> results;
    std::map<int, std::string> results_names;

};


// ============================================================================ 
//                         CLASS METHODS IMPLEMENTATION
// ============================================================================
template<class T>
Solver<T>::Solver()
    :
        q(T::n),
        qd(T::n),
        qdd(T::n),
        lgr(T::nc),
        Jacobian(T::nc, T::n),
        MassMatrix(T::n, T::n),
        model("", q, qd, qdd, lgr)
{
    //Jacobian.resize(model.nc, model.n);
    //MassMatrix.resize(model.n, model.n);

    results_names[0] = "Positions";
    results_names[1] = "Velocities";
    results_names[2] = "Accelerations";
    results_names[3] = "LagrnageMultipliers";
    results_names[4] = "Constraints";
};


template<class T>
void Solver<T>::set_time(double& t)
{
    model.t = t;
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
void Solver<T>::initialize()
{
    model.initialize();
    for (size_t i = 0; i < model.jac_rows.size(); i++)
        {
            jac_rows.push_back(int(model.jac_rows(i)));
            jac_cols.push_back(int(model.jac_cols(i)));        
        }
    
    for (size_t i = 0; i < model.mas_cols.size(); i++)
        {
            mas_cols.push_back(int(model.mas_cols(i)));
        }

};


template<class T>
Eigen::VectorXd Solver<T>::eval_pos_eq()
{   
    model.eval_pos_eq();
    return model.pos_eq;
};

template<class T>
Eigen::VectorXd Solver<T>::eval_vel_eq()
{   
    model.eval_vel_eq();
    return model.vel_eq;
};

template<class T>
Eigen::VectorXd Solver<T>::eval_acc_eq()
{   
    model.eval_acc_eq();
    return model.acc_eq;
};

template<class T>
Eigen::VectorXd Solver<T>::eval_frc_eq()
{   
    model.eval_frc_eq();
    return model.frc_eq;
};

template<class T>
void Solver<T>::eval_jac_eq()
{   
    model.eval_jac_eq();    
    SparseAssembler(Jacobian, jac_rows, jac_cols, model.jac_eq);
};

template<class T>
void Solver<T>::eval_rct_eq()
{   
    model.eval_reactions(Jacobian);    
};

template<class T>
void Solver<T>::eval_mas_eq()
{   
    model.eval_mas_eq();    
    SparseAssembler(MassMatrix, mas_cols, mas_cols, model.mas_eq);
};


template<class T>
void Solver<T>::solve_lgr_multipliers()
{
    eval_mas_eq();
    Eigen::VectorXd ext_frc = eval_frc_eq();
    Eigen::VectorXd inertia = MassMatrix * qdd;
    Eigen::VectorXd&& rhs = ext_frc - inertia;
    SparseSolver.compute(Jacobian.transpose());
    lgr << SparseSolver.solve(rhs);
    //std::cout << (MassMatrix * qdd).transpose() << "\n\n";
    //std::cout << eval_frc_eq().transpose() << "\n\n";
};

template<class T>
void Solver<T>::solve_constraints(Eigen::VectorXd &guess)
{    
    // Creating a SparseSolver object.
    //std::cout << "Declaring SparseLU" << "\n";
    //Eigen::SparseLU<SparseBlock> SparseSolver;

    //std::cout << "Setting Guess" << "\n";
    //std::cout << guess << "\n";
    q << guess;
    //std::cout << "Evaluating Pos_Eq " << "\n";
    auto&& b = eval_pos_eq();
    //std::cout << "Evaluating Jac_Eq " << "\n";
    eval_jac_eq();
    //std::cout << "Computing Matrix A " << "\n";
    SparseSolver.compute(Jacobian);

    //std::cout << "Solving for Vector b " << "\n";
    Eigen::VectorXd&& error = SparseSolver.solve(-b);

    //std::cout << "Entring While Loop " << "\n";
    int itr = 0;
    while (error.norm() >= 1e-5)
    {
        //std::cout << "Error e = " << error.norm() << "\n";
        guess += error;
        q << guess;
        b = eval_pos_eq();
        error = SparseSolver.solve(-b);

        if (itr%5 == 0 && itr!=0)
        {
            eval_jac_eq();
            SparseSolver.compute(Jacobian);
            error = SparseSolver.solve(-b);
        };

        if (itr>50)
        {
            std::cout << "ITERATIONS EXCEEDED!! => " << itr << "\n" ;
            break;
        };

        itr++;
    };
    
    q << guess;
    eval_jac_eq();
    SparseSolver.compute(Jacobian);
};


template<class T>
void Solver<T>::Solve()
{
    std::cout << "Starting Solver ..." << "\n";
    //Eigen::SparseLU<SparseBlock> SparseSolver;
    
    auto& dt = step_size;
    double t = 0;
    auto samples = time_array.size();
    
    //std::cout << "Setting Initial Position History" << "\n";
    pos_history.emplace_back(q);

    Eigen::VectorXd guess(model.n);

    pos_history.reserve(samples);
    vel_history.reserve(samples);
    acc_history.reserve(samples);

    //std::cout << "Computing Jacobian" << "\n";
    eval_jac_eq();
    //std::cout << "Jacobian =  \n" << A << "\n";
    //std::cout << "Factorizing Jacobian" << "\n";
    SparseSolver.compute(Jacobian);

    //std::cout << "Solving for Velocity" << "\n";
    qd << SparseSolver.solve(-eval_vel_eq());
    //std::cout << "Storing Generalized Velocities" << "\n";
    vel_history.emplace_back(qd);
    
    //std::cout << "Solving for Accelerations" << "\n";
    qdd << SparseSolver.solve(-eval_acc_eq());
    acc_history.emplace_back(qdd);

    solve_lgr_multipliers();
    eval_rct_eq();
    lgr_history.emplace_back(lgr);
    rct_history.emplace_back(model.rct_eq);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end;

    //std::cout << "\nRunning System Kinematic Analysis: " << "\n";
    for (size_t i = 1; i < samples; i++)
    {
        print_progress(begin, samples, i);

        t = time_array(i) ;
        set_time(t) ;

        guess = q + (qd * dt) + (0.5 * qdd * pow(dt, 2));

        solve_constraints(guess);

        qd  << SparseSolver.solve(-eval_vel_eq());
        qdd << SparseSolver.solve(-eval_acc_eq());

        solve_lgr_multipliers();
        eval_rct_eq();
        
        pos_history.emplace_back(q);
        vel_history.emplace_back(qd);
        acc_history.emplace_back(qdd);
        lgr_history.emplace_back(lgr);
        rct_history.emplace_back(model.rct_eq);

    };

    results[0] = &pos_history;
    results[1] = &vel_history;
    results[2] = &acc_history;
    results[3] = &lgr_history;
    results[4] = &rct_history;

    std::cout << "\n";
    std::cout << "Finished Solver ..." << "\n";

};


template<class T>
void Solver<T>::ExportResultsCSV(std::string location, std::string name, int id)
{
    // declaring and initializing the needed variables
    auto& data = *(results[id]);
    std::ofstream results_file;

    std::map<int, std::string> ordered_indicies;
    for (auto& x : model.indicies_map)
    {
        ordered_indicies[x.second] = x.first;
    };

    // Creating the system indicies string to be used as the fisrt line
    // in the .csv file
    std::string indicies = "";
    std::vector<std::string> coordinates{"x", "y", "z", "e0", "e1", "e2", "e3"};
    for (auto& x : ordered_indicies)
    {
        auto& body_name = x.second;
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
    for (auto& x : data)
    {
        results_file << std::to_string(i) + ", ";
        results_file << x.transpose().format(CSVFormat) ;
        results_file << std::to_string(time_array(i)) + "\n";
        i += 1;
    };

    results_file.close();
    std::cout << "\n" << name << " results saved as : " << location + name + ".csv" << "\n";
    
};

template<class T>
void Solver<T>::ExportReactionsResults(std::string location, std::string name)
{
    // declaring and initializing the needed variables
    //std::cout << "Getting reactions Data!\n\n";
    auto& data = *(results[4]);
    std::ofstream results_file;

    //std::cout << "Setting reactions' indecies!\n\n";
    // Creating the system indicies string to be used as the fisrt line
    // in the .csv file
    std::string indicies = "";
    std::vector<std::string> coordinates{"x", "y", "z"};
    for (const auto& joint_name : model.joints_names)
    {
        for (const auto& coordinate : coordinates)
        {
          indicies += "F_" + joint_name + "." + coordinate + "," ;
        };

        for (const auto& coordinate : coordinates)
        {
          indicies += "T_" + joint_name + "." + coordinate + "," ;
        };    
    };

    // Opening the file as a .csv file.
    results_file.open (location + name + ".csv");
    
    // Inserting the first line to be the indicies of the system.
    results_file << "," + indicies + "time\n";

    //std::cout << "Looping over the results and writing each line to the .csv file.!\n\n";
    // Looping over the results and writing each line to the .csv file.
    int i = 0;
    for (auto& x : data)
    {
        results_file << std::to_string(i) + ", ";
        results_file << x.transpose().format(CSVFormat) ;
        results_file << std::to_string(time_array(i)) + "\n";
        i += 1;
    };

    results_file.close();
    std::cout << "\n" << name << " results saved as : " << location + name + ".csv" << "\n";
    
};

template<class T>
void Solver<T>::ExportLagrangeMultipliers(std::string location, std::string name)
{
    // declaring and initializing the needed variables
    //std::cout << "Getting reactions Data!\n\n";
    auto& data = *(results[3]);
    std::ofstream results_file;


    // Opening the file as a .csv file.
    results_file.open (location + name + ".csv");
    
    //std::cout << "Looping over the results and writing each line to the .csv file.!\n\n";
    // Looping over the results and writing each line to the .csv file.
    int i = 0;
    for (auto& x : data)
    {
        results_file << std::to_string(i) + ", ";
        results_file << x.transpose().format(CSVFormat) ;
        results_file << std::to_string(time_array(i)) + "\n";
        i += 1;
    };

    results_file.close();
    std::cout << "\n" << name << " results saved as : " << location + name + ".csv" << "\n";
    
};

