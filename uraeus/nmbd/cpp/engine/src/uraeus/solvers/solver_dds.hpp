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

#include "eigen/Eigen/SparseLU"
#include "eigen/Eigen/SparseQR"

// Local Libraries Includes.
#include "helpers.hpp"
#include "utilities.hpp"


// csv file formatter to export Eigen matricies as comma separated value text.
const static Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, 
                                       Eigen::DontAlignCols, 
                                       ", ", ", ", "", "", "", ",");


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
    SparseBlock JacobianMod;
    SparseBlock MassMatrix;

    T model {"", q, qd, qdd, lgr};

    MatrixAssembler JacobianAssembler {model.jac_rows, model.jac_cols, (model.n - model.nc)};
    MatrixAssembler MassAssembler {model.mas_cols, model.mas_cols};
    
    Eigen::SparseMatrix<double, Eigen::RowMajor> LeftMatrix  {model.n + model.nc, model.n};
    Eigen::SparseMatrix<double, Eigen::RowMajor> RightMatrix {model.n + model.nc, model.nc};
    Eigen::SparseMatrix<double, Eigen::ColMajor> CoeffMatrix {model.n + model.nc, model.n + model.nc};

    Eigen::VectorXd NE_EOM_rhs{model.n + model.nc};
    Eigen::PermutationMatrix<T::n, T::n, int> CoordinatesPermutation{model.n};
    
    Eigen::VectorXd StateVectorD0;
    Eigen::VectorXd StateVectorD1;
    
    double t;
    double step_size;
    double dof;
    Eigen::VectorXd time_array;

    std::vector<Eigen::VectorXd> pos_history;
    std::vector<Eigen::VectorXd> vel_history;
    std::vector<Eigen::VectorXd> acc_history;
    std::vector<Eigen::VectorXd> lgr_history;
    std::vector<Eigen::VectorXd> rct_history;

    Eigen::SparseLU<SparseBlock> LUSolver;
    Eigen::SparseQR<SparseBlock, Eigen::COLAMDOrdering<int>> QRSolver;

    std::vector<Eigen::Index> coord_indices;
    std::vector<Eigen::Triplet<double>> extra_triplets;



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

    void solve_constraints();
    void Solve();

    void ExportResultsCSV(std::string location, std::string name, int id);
    void ExportReactionsResults(std::string location, std::string name);
    void ExportLagrangeMultipliers(std::string location, std::string name);

    void partition_system_coordinates();
    void ConstructCoeffMatrix();
    void SolveNE_EOM();

    Eigen::VectorXd SSODE(double t, double h);
    void AdvanceTimeStep(double t, double h)
     
    //void GetIndependentStates(Eigen::Ref<Eigen::VectorXd> q, Eigen::Ref<Eigen::VectorXd> qi);


private:
    std::map<int, std::vector<Eigen::VectorXd>*> results;
    std::map<int, std::string> results_names;

};


void get_indices(Eigen::VectorXi indices, 
                 std::vector<Eigen::Triplet<double>>& extra_triplets, 
                 int dof)
{
    Eigen::Index index;

    for (int i = 0; i < dof; i++)
    {
        indices.maxCoeff(&index);

        std::cout << "coordinate index = " << index << "\n";
        std::cout << indices(index) << index << 1 << "\n";

        auto triplet = Eigen::Triplet<double>(indices(index), index, 1);
        extra_triplets.emplace_back(triplet);
        coord_indices[i] = index;

        indices(index) = 0;
    }
}

// ============================================================================ 
//                         Dynamics METHODS IMPLEMENTATION
// ============================================================================

template<class T>
void Solver<T>::AdvanceTimeStep(double t, double h)
{

}

template<class T>
Eigen::VectorXd Solver<T>::SSODE(double t, double h)
{
    set_time(t);

    auto& y1 = (CoordinatesPermutation * q).segment(model.nc, dof)
    auto& y2 = (CoordinatesPermutation * qd).segment(model.nc, dof)

    q += (qd * h) + (0.5 * qdd * (h*h));

    int i = 0;
    for (const auto& index : coord_indices)
    {
        q(index) = y1(i);
        i++;
    };

    solve_constraints();

    Eigen::VectorXd vel_rhs(model.n);
    auto vel_rhs_nc = eval_vel_eq();
    vel_rhs << -vel_rhs_nc, y2;

    qd = LUSolver.solve(vel_rhs);

    ConstructCoeffMatrix();
    SolveNE_EOM();

    auto& y3 = (CoordinatesPermutation * qdd).segment(model.nc, dof);

    StateVectorD1 << y2, y3;

    return StateVectorD1;

};


template<class T>
void Solver<T>::partition_system_coordinates()
{
    QRSolver.compute(Jacobian);

    auto q_dummy = Eigen::VectorXd::LinSpaced(28, 0, 28-1);

    CoordinatesPermutation = QRSolver.colsPermutation();
    auto& indices = CoordinatesPermutation.indices();
    
    std::cout << "System rank : " << QRSolver.rank() << "\n";
    std::cout << "q : \n" << q_dummy << "\n";
    std::cout << "CoordinatesPermutation * q : \n" << CoordinatesPermutation * q_dummy << "\n";
    //std::cout << "Permutation Matrix Shape : " << P.rows() << ", " << P.cols() << "\n";
    //std::cout << "Permutation Matrix : \n" << P << "\n";
    //std::cout << "Permutation Matrix Indices : \n" << QRSolver.colsPermutation().indices() << "\n";
    
    std::cout << "Calling get_indices\n";
    get_indices(indices, extra_triplets, 1);

    std::cout << "Calling JacobianAssembler.AssembleTripletList(model.jac_eq)\n";
    JacobianAssembler.AssembleTripletList(model.jac_eq);

    std::cout << "Calling JacobianAssembler.Assemble(JacobianMod, extra_triplets)\n";
    JacobianAssembler.Assemble(JacobianMod, extra_triplets);

    std::cout << "JacMod : \n" << JacobianMod.innerVectors(1,3) << "\n";

    Eigen::VectorXd b(model.n);
    b << eval_pos_eq();
    std::cout << "Poseq : \n" << b << "\n";

    LUSolver.compute(JacobianMod);
    LUSolver.solve(-b);

    ConstructCoeffMatrix();
    SolveNE_EOM();

    std::cout << "Permuted Coordinates = \n" << (CoordinatesPermutation * q).segment(model.nc, dof) << "\n";
    std::cout << "Permuted Velocities = \n" << (CoordinatesPermutation * qd).segment(model.nc, dof) << "\n";
    std::cout << "Permuted Accelerations = \n" << (CoordinatesPermutation * qdd).segment(model.nc, dof) << "\n";
};
 
template<class T>
void Solver<T>::ConstructCoeffMatrix()
{
    std::cout << "Calling eval_mas_eq \n";
    eval_mas_eq();
    std::cout << "Calling eval_jac_eq \n";
    eval_jac_eq();

    std::cout << "Calling LeftMatrix.innerVectors(0, model.n) = MassMatrix \n";
    LeftMatrix.innerVectors(0, model.n) = MassMatrix;
    std::cout << "Calling LeftMatrix.innerVectors(model.n, model.n + model.nc) = Jacobian \n";
    LeftMatrix.innerVectors(model.n, model.nc) = Jacobian;

    std::cout << "Calling RightMatrix.innerVectors(0, model.n) = Jacobian.transpose() \n";
    RightMatrix.innerVectors(0, model.n) = Jacobian.transpose();

    std::cout << "Calling CoeffMatrix.innerVectors(0, model.n) = LeftMatrix \n";
    CoeffMatrix.innerVectors(0, model.n) = LeftMatrix;
    std::cout << "Calling CoeffMatrix.innerVectors(model.n, model.n + model.nc) = RightMatrix \n";
    CoeffMatrix.innerVectors(model.n, model.nc) = RightMatrix;

    CoeffMatrix.makeCompressed();

    std::cout << "CoeffMatrix : \n" << CoeffMatrix << "\n";

}

template<class T>
void Solver<T>::SolveNE_EOM()
{
    NE_EOM_rhs << eval_frc_eq(), -eval_acc_eq();

    LUSolver.compute(CoeffMatrix);
    auto x = LUSolver.solve(NE_EOM_rhs);

    qdd = x.segment(0, model.n);
    lgr = x.segment(model.n, model.nc);

    std::cout << "x = \n" << x << "\n";
    std::cout << "qdd = \n" << qdd << "\n";
    std::cout << "lgr = \n" << lgr << "\n";

}


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
        JacobianMod(T::n, T::n),
        MassMatrix(T::n, T::n)
{
    dof = model.n - model.nc;
    extra_triplets.reserve(dof);

    StateVectorD0(2 * dof);
    StateVectorD1(2 * dof);

    results_names[0] = "_pos";
    results_names[1] = "_vel";
    results_names[2] = "_acc";
    results_names[3] = "_lgr";
    results_names[4] = "_rct";
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
    qd = Eigen::VectorXd::Zero(model.n);
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
    JacobianAssembler.AssembleTripletList(model.jac_eq);
    JacobianAssembler.Assemble(Jacobian);
};

template<class T>
void Solver<T>::eval_mas_eq()
{   
    model.mas_eq.clear();
    model.eval_mas_eq();
    MassAssembler.AssembleTripletList(model.mas_eq);
    MassAssembler.Assemble(MassMatrix);
    //SparseAssembler(MassMatrix, mas_cols, mas_cols, model.mas_eq);
};

template<class T>
void Solver<T>::eval_rct_eq()
{   
    model.eval_reactions(Jacobian);    
};

template<class T>
void Solver<T>::solve_lgr_multipliers()
{
    eval_mas_eq();
    Eigen::VectorXd ext_frc = eval_frc_eq();
    Eigen::VectorXd inertia = MassMatrix * qdd;
    Eigen::VectorXd rhs = ext_frc - inertia;
    LUSolver.compute(Jacobian.transpose());
    lgr = LUSolver.solve(rhs);
    //std::cout << (MassMatrix * qdd).transpose() << "\n\n";
    //std::cout << eval_frc_eq().transpose() << "\n\n";
};

template<class T>
void Solver<T>::solve_constraints()
{    
    //std::cout << "Evaluating Pos_Eq " << "\n";
    auto&& b = eval_pos_eq();
    //std::cout << "Evaluating Jac_Eq " << "\n";
    eval_jac_eq();
    //std::cout << "Computing Matrix A " << "\n";
    LUSolver.compute(Jacobian);

    //std::cout << "Solving for Vector b " << "\n";
    Eigen::VectorXd error = LUSolver.solve(-b);

    //std::cout << "Entring While Loop " << "\n";
    int itr = 0;
    while (error.norm() >= 1e-5)
    {
        //std::cout << "Error e = " << error.norm() << "\n";
        q += error;
        b = eval_pos_eq();
        error = LUSolver.solve(-b);

        if (itr%5 == 0 && itr!=0)
        {
            eval_jac_eq();
            LUSolver.compute(Jacobian);
            error = LUSolver.solve(-b);
        };

        if (itr>50)
        {
            std::cout << "ITERATIONS EXCEEDED!! " << itr << "\n" ;
            break;
        };

        itr++;
    };
    
    eval_jac_eq();
    LUSolver.compute(Jacobian);
};


template<class T>
void Solver<T>::Solve()
{
    std::cout << "Starting Solver ..." << "\n";
    //Eigen::SparseLU<SparseBlock> LUSolver;
    
    auto& dt = step_size;
    auto samples = time_array.size();

    pos_history.reserve(samples);
    vel_history.reserve(samples);
    acc_history.reserve(samples);
    lgr_history.reserve(samples);
    rct_history.reserve(samples);
    
    //Eigen::VectorXd guess(model.n);

    //std::cout << "Computing Jacobian" << "\n";
    eval_jac_eq();
    //std::cout << "Factorizing Jacobian" << "\n";
    LUSolver.compute(Jacobian);

    //std::cout << "Solving for Velocity" << "\n";
    qd = LUSolver.solve(-eval_vel_eq());
    
    //std::cout << "Solving for Accelerations" << "\n";
    qdd = LUSolver.solve(-eval_acc_eq());

    solve_lgr_multipliers();
    eval_rct_eq();

    pos_history.emplace_back(q);
    vel_history.emplace_back(qd);
    acc_history.emplace_back(qdd);
    lgr_history.emplace_back(lgr);
    rct_history.emplace_back(model.rct_eq);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end;

    std::cout << "\nRunning System Kinematic Analysis: " << "\n";
    for (size_t i = 1; i < samples; i++)
    {
        print_progress(begin, samples, i);

        t = time_array(i) ;
        set_time(t) ;

        q += (qd * dt) + (0.5 * qdd * (dt*dt));

        solve_constraints();

        qd  = LUSolver.solve(-eval_vel_eq());
        qdd = LUSolver.solve(-eval_acc_eq());

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
    std::cout << "Finished Solver ... \n";

};


template<class T>
void Solver<T>::ExportResultsCSV(std::string location, std::string name, int id)
{
    // declaring and initializing the needed variables
    auto& data = *(results[id]);
    std::ofstream results_file;

    std::map<int, std::string> ordered_indicies;
    for (auto& x : model.indicies_map) { ordered_indicies[x.second] = x.first; };

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
    results_file.open (location + name + results_names[id] + ".csv");
    
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
void Solver<T>::ExportLagrangeMultipliers(std::string location, std::string name)
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

