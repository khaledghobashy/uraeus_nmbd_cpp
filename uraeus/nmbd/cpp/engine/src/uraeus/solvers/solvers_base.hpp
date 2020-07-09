/*
============================================================================
                            uraeus.nmbd.cpp
============================================================================

Use of this source code is governed by a BSD-style license that can be found
in the LICENSE file at the top level of the distribution.

Authors:
    - Khaled Ghobashy


============================================================================
                                Summary
============================================================================

*/

#pragma once

// Standard Library Includes.
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

// Local Libraries Includes.
#include "sparse_assembler.hpp"
#include "utilities.hpp"



// ============================================================================ 
//                         Solver Template Class
// ============================================================================

// csv file formatter to export Eigen matricies as comma separated value text.
static const Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, 
                                       Eigen::DontAlignCols, 
                                       ", ", ", ", "", "", "", ",");


// Declaring and Implementing the Solver class as a template class.
// Type T should be any Topology class type.
template <class T>
class BaseSolver
{
public:
    Eigen::VectorXd q;
    Eigen::VectorXd qd;
    Eigen::VectorXd qdd;
    Eigen::VectorXd lgr;

    SparseBlock Jacobian;
    SparseBlock MassMatrix;

    T model {"", q, qd, qdd, lgr};

    MatrixAssembler JacobianAssembler {model.jac_rows, model.jac_cols};
    MatrixAssembler MassAssembler {model.mas_cols, model.mas_cols};
    
    double t;
    double step_size;
    Eigen::VectorXd time_array;

    Eigen::SparseLU<SparseBlock> LUSolver;

public:
    std::map<int, std::vector<Eigen::VectorXd>*> results;
    std::map<int, std::string> results_names;
    
    std::vector<Eigen::VectorXd> pos_history;
    std::vector<Eigen::VectorXd> vel_history;
    std::vector<Eigen::VectorXd> acc_history;
    std::vector<Eigen::VectorXd> lgr_history;
    std::vector<Eigen::VectorXd> rct_history;

    std::vector<std::string> CoordinatesNames;

public:

    BaseSolver();

    virtual void Solve();
    
    void Initialize();
    void SetTimeArray(const double& duration, const double& spacing);
    void ExportStates(std::string location, std::string name);
    void ExportReactions(std::string location, std::string name);
    void ExportLagrangeMultipliers(std::string location, std::string name);    

public:

    virtual void SolveConstraints();

    void SetTime(double& t);

    Eigen::VectorXd eval_pos_eq();
    Eigen::VectorXd eval_vel_eq();
    Eigen::VectorXd eval_acc_eq();
    Eigen::VectorXd eval_frc_eq();

    void eval_rct_eq();
    void eval_jac_eq();
    void eval_mas_eq();

    void ResetStates();
    void UpdateHistories();
    void ConstructCoordinatesNames();
    void ExportState(std::string location, std::string name, int id);

};


// ============================================================================ 
//                         CLASS METHODS IMPLEMENTATION
// ============================================================================
template<class T>
BaseSolver<T>::BaseSolver()
    :
        q(T::n),
        qd(T::n),
        qdd(T::n),
        lgr(T::nc),
        Jacobian(T::nc, T::n),
        MassMatrix(T::n, T::n)
{
    results_names[0] = "_pos";
    results_names[1] = "_vel";
    results_names[2] = "_acc";
    results_names[3] = "_lgr";
    results_names[4] = "_rct";
};

// ============================================================================ 
//                              Helper Methods
// ============================================================================

template<class T>
void BaseSolver<T>::Initialize()
{
    model.initialize();
    qd = Eigen::VectorXd::Zero(model.n);
    ConstructCoordinatesNames();
};

template<class T>
void BaseSolver<T>::ConstructCoordinatesNames()
{
    std::map<int, std::string> ordered_indicies;
    for (const auto& x : model.indicies_map) { ordered_indicies[x.second] = x.first; };
    
    const std::vector<std::string> coordinates{"x", "y", "z", "e0", "e1", "e2", "e3"};
    
    for (const auto& x : ordered_indicies)
    {
        const auto& body_name = x.second;
        for (const auto& coordinate : coordinates)
        {
          CoordinatesNames.emplace_back(body_name + "." + coordinate);
        };
    };
};

template<class T>
void BaseSolver<T>::SetTimeArray(const double& duration, const double& spacing)
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
void BaseSolver<T>::SetTime(double& t)
{
    model.t = t;
};


template<class T>
void BaseSolver<T>::UpdateHistories()
{
    pos_history.emplace_back(q);
    vel_history.emplace_back(qd);
    acc_history.emplace_back(qdd);
    lgr_history.emplace_back(lgr);
    rct_history.emplace_back(model.rct_eq);
};

template<class T>
void BaseSolver<T>::ResetStates()
{
    if (pos_history.size() > 0)
    {
        q  = pos_history[0];
        qd = vel_history[0];

        pos_history.clear();
        vel_history.clear();
        acc_history.clear();
        lgr_history.clear();
        rct_history.clear();
    };

};

// ============================================================================ 
//                         System Equations Evaluators
// ============================================================================


template<class T>
Eigen::VectorXd BaseSolver<T>::eval_pos_eq()
{   
    model.eval_pos_eq();
    return model.pos_eq;
};

template<class T>
Eigen::VectorXd BaseSolver<T>::eval_vel_eq()
{   
    model.eval_vel_eq();
    return model.vel_eq;
};

template<class T>
Eigen::VectorXd BaseSolver<T>::eval_acc_eq()
{   
    model.eval_acc_eq();
    return model.acc_eq;
};

template<class T>
Eigen::VectorXd BaseSolver<T>::eval_frc_eq()
{   
    model.eval_frc_eq();
    return model.frc_eq;
};

template<class T>
void BaseSolver<T>::eval_jac_eq()
{   
    model.eval_jac_eq();
    JacobianAssembler.AssembleTripletList(model.jac_eq);
    JacobianAssembler.Assemble(Jacobian);
};

template<class T>
void BaseSolver<T>::eval_mas_eq()
{   
    model.eval_mas_eq();
    MassAssembler.AssembleTripletList(model.mas_eq);
    MassAssembler.Assemble(MassMatrix);
};

template<class T>
void BaseSolver<T>::eval_rct_eq()
{   
    model.eval_reactions(Jacobian);    
};


// ============================================================================ 
//                    Position Constraints Iterative Solver
// ============================================================================


template<class T>
void BaseSolver<T>::SolveConstraints()
{
    
};

// ============================================================================ 
//                              Simulation Loop
// ============================================================================

template<class T>
void BaseSolver<T>::Solve()
{

};

// ============================================================================ 
//                          Results Export Methods
// ============================================================================

template<class T>
void BaseSolver<T>::ExportStates(std::string location, std::string name)
{
    ExportState(location, name, 0);
    ExportState(location, name, 1);
    ExportState(location, name, 2);
};

template<class T>
void BaseSolver<T>::ExportState(std::string location, std::string name, int id)
{
    // declaring and initializing the needed variables
    const auto& data = *(results[id]);
    std::ofstream results_file;

    // Creating the system indicies string to be used as the fisrt line
    // in the .csv file
    std::string indicies = "";
    for (const auto& coordinate : CoordinatesNames)
    {
        indicies += coordinate + "," ;
    };

    // Opening the file as a .csv file.
    std::string fileFullname = location + name + results_names[id] + ".csv";
    results_file.open (fileFullname);
    
    // Inserting the first line to be the indicies of the system.
    results_file << ", " + indicies + "time\n";

    // Looping over the results and writing each line to the .csv file.
    int i = 0;
    for (const auto& x : data)
    {
        results_file << std::to_string(i) + ", ";
        results_file << x.transpose().format(CSVFormat) ;
        results_file << std::to_string(time_array(i)) + "\n";
        i += 1;
    };

    results_file.close();
    std::cout << "\n" << results_names[id] << " results saved as : " << fileFullname << "\n";
    
};

template<class T>
void BaseSolver<T>::ExportReactions(std::string location, std::string name)
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
    results_file.open (location + name + results_names[4] + ".csv");
    
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
void BaseSolver<T>::ExportLagrangeMultipliers(std::string location, std::string name)
{
    // declaring and initializing the needed variables
    //std::cout << "Getting reactions Data!\n\n";
    auto& data = *(results[3]);
    std::ofstream results_file;


    // Opening the file as a .csv file.
    results_file.open (location + name + results_names[3] + ".csv");
    
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

