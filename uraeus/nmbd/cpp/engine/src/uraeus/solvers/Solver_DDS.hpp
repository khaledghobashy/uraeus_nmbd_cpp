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

// Local Libraries Includes.
#include "solvers_base.hpp"
#include "sparse_assembler.hpp"
#include "utilities.hpp"
#include "integrators.hpp"


// ============================================================================ 
//                         Solver Template Class
// ============================================================================

namespace dds
{

// Declaring and Implementing the Solver class as a template class.
// Type T should be any Topology class type.
template <class T>
class Solver : public BaseSolver<T>
{
public:
    SparseBlock JacobianMod;

    MatrixAssembler JacobianAssembler {model.jac_rows, model.jac_cols, (model.n - model.nc)};
    
    Eigen::SparseMatrix<double, Eigen::RowMajor> LeftMatrix  {model.n + model.nc, model.n};
    Eigen::SparseMatrix<double, Eigen::RowMajor> RightMatrix {model.n + model.nc, model.nc};
    Eigen::SparseMatrix<double, Eigen::ColMajor> CoeffMatrix {model.n + model.nc, model.n + model.nc};
    Eigen::PermutationMatrix<T::n, T::n, int> CoordinatesPermutation{model.n};
    
    Eigen::VectorXd EOM_rhs{model.n + model.nc};
    Eigen::VectorXd StateVectorD0;
    Eigen::VectorXd StateVectorD1;

    Eigen::SparseLU<SparseBlock> LUSolver;
    Explicit_RK23<Solver<T>> integrator;
    
    int dof;

private:
    std::vector<Eigen::Index> coord_indices;
    std::vector<Eigen::Triplet<double>> extra_triplets;

public:

    Solver();
    void Solve();    
    Eigen::VectorXd SSODE(Eigen::VectorXd _StateVectorD0, double t, double h);

private:

    void eval_jac_eq();

    void SolveConstraints();
    void PartitionSystemCoordinates();
    void ExtractIndependentIndices(Eigen::VectorXi indices);
    void ConstructCoeffMatrix();
    void SolveEOM();
    void ConstructStateVectors();
    void AdvanceTimeStep();
    
};

// ============================================================================ 
//                         CLASS Constructors
// ============================================================================
template<class T>
Solver<T>::Solver()
    : BaseSolver(), JacobianMod(T::n, T::n)
{
    dof = model.n - model.nc;
    extra_triplets.reserve(dof);

    StateVectorD0.resize(2 * dof);
    StateVectorD1.resize(2 * dof);

    integrator.Initialize(dof);

};

// ============================================================================ 
//                         System Equations Evaluators
// ============================================================================

template<class T>
void Solver<T>::eval_jac_eq()
{   
    model.eval_jac_eq();
    JacobianAssembler.AssembleTripletList(model.jac_eq);
    JacobianAssembler.Assemble(Jacobian);
    JacobianAssembler.Assemble(JacobianMod, extra_triplets);
};


// ============================================================================ 
//                    Position Constraints Iterative Solver
// ============================================================================

template<class T>
void Solver<T>::SolveConstraints()
{    
   //std::cout << "Evaluating Pos_Eq " << "\n";
    Eigen::VectorXd b(model.n);
    b << eval_pos_eq(), Eigen::VectorXd::Zero(dof);
   //std::cout << "Evaluating Jac_Eq " << "\n";
    eval_jac_eq();
   //std::cout << "Computing Matrix A " << "\n";
    //std::cout << "JacobianMod = \n" << JacobianMod << "\n";
    LUSolver.compute(JacobianMod);
    //std::cout << LUSolver.logAbsDeterminant() << "\n";

   //std::cout << "Solving for Vector b " << "\n";
   //std::cout << "b = \n" << b << "\n";
    Eigen::VectorXd error = LUSolver.solve(-b);

   //std::cout << "error.norm() = " << error.norm() << "\n";
   //std::cout << "Entring While Loop " << "\n";
    int itr = 0;
    while (error.norm() >= 1e-5)
    {
       //std::cout << "Error e = " << error.norm() << "\n";
        q += error;
        b << eval_pos_eq(), Eigen::VectorXd::Zero(dof);
        error = LUSolver.solve(-b);

        if (itr%5 == 0 && itr!=0)
        {
            eval_jac_eq();
            LUSolver.compute(JacobianMod);
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
    LUSolver.compute(JacobianMod);
};

// ============================================================================ 
//                              Simulation Loop
// ============================================================================

template<class T>
void Solver<T>::Solve()
{
    std::cout << "Starting Dynamic Solver ..." << "\n";
    
    auto& dt = step_size;
    auto samples = time_array.size();
    
    integrator.h = dt;
    integrator.t = 0;

    ResetStates();

    pos_history.reserve(samples);
    vel_history.reserve(samples);
    acc_history.reserve(samples);
    lgr_history.reserve(samples);
    rct_history.reserve(samples);

    eval_jac_eq();
    PartitionSystemCoordinates();
    SolveConstraints();
    ConstructCoeffMatrix();
    SolveEOM();

    eval_rct_eq();
    UpdateHistories();

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end;

    std::cout << "\nRunning System Dynamic Analysis: " << "\n";
    for (size_t i = 1; i < samples; i++)
    {
        print_progress(begin, samples, i);

        PartitionSystemCoordinates();
        AdvanceTimeStep();

        eval_rct_eq();
        UpdateHistories();

    };

    results[0] = &pos_history;
    results[1] = &vel_history;
    results[2] = &acc_history;
    results[3] = &lgr_history;
    results[4] = &rct_history;

    std::cout << "\n";
    std::cout << "Finished Solver ... \n";

};

// ============================================================================ 
//                              Dynamics Methods
// ============================================================================

template<class T>
void Solver<T>::PartitionSystemCoordinates()
{
    Eigen::MatrixXd DenseJacobian = Eigen::MatrixXd(Jacobian);

    auto Decomposition = DenseJacobian.transpose().fullPivLu();

    CoordinatesPermutation = Decomposition.permutationP();
    auto& indices = CoordinatesPermutation.indices();
        
    ExtractIndependentIndices(indices);

};

template<class T>
void Solver<T>::ExtractIndependentIndices(Eigen::VectorXi indices)
{
    Eigen::Index index;

    coord_indices.clear();
    extra_triplets.clear();

    //std::cout << "dof = " << dof << "\n";

    for (int i = 0; i < dof; i++)
    {
        indices.maxCoeff(&index);

       //std::cout << "coordinate index = " << index << "\n";

        auto triplet = Eigen::Triplet<double>(indices(index), index, 1);
        extra_triplets.emplace_back(triplet);
        coord_indices.emplace_back(index);

        indices(index) = 0;
    }
}

template<class T>
void Solver<T>::AdvanceTimeStep()
{
    ConstructStateVectors();
    //std::cout << "Calling integrator.Advance(this, StateVectorD0, StateVectorD1) \n";
    integrator.Advance(this, StateVectorD0, StateVectorD1);
    //std::cout << "StateVectorD0 = integrator.y \n";
    //StateVectorD0 = integrator.y;
    SSODE(integrator.y, integrator.t, integrator.h);

}

 
template<class T>
void Solver<T>::ConstructStateVectors()
{
    const auto& y1 = (CoordinatesPermutation * q).segment(model.nc, dof);
    const auto& y2 = (CoordinatesPermutation * qd).segment(model.nc, dof);
    const auto& y3 = (CoordinatesPermutation * qdd).segment(model.nc, dof);

    StateVectorD0 << y1, y2;
    StateVectorD1 << y2, y3;

}

template<class T>
void Solver<T>::ConstructCoeffMatrix()
{
    //std::cout << "Calling eval_mas_eq \n";
    eval_mas_eq();

    //std::cout << "Calling LeftMatrix.innerVectors(0, model.n) = MassMatrix \n";
    LeftMatrix.innerVectors(0, model.n) = MassMatrix;
    //std::cout << "Calling LeftMatrix.innerVectors(model.n, model.n + model.nc) = Jacobian \n";
    LeftMatrix.innerVectors(model.n, model.nc) = Jacobian;

    //std::cout << "Calling RightMatrix.innerVectors(0, model.n) = Jacobian.transpose() \n";
    RightMatrix.innerVectors(0, model.n) = Jacobian.transpose();

    //std::cout << "Calling CoeffMatrix.innerVectors(0, model.n) = LeftMatrix \n";
    CoeffMatrix.innerVectors(0, model.n) = LeftMatrix;
    //std::cout << "Calling CoeffMatrix.innerVectors(model.n, model.n + model.nc) = RightMatrix \n";
    CoeffMatrix.innerVectors(model.n, model.nc) = RightMatrix;

    CoeffMatrix.makeCompressed();

    //std::cout << "CoeffMatrix = \n" << CoeffMatrix << "\n";
    //std::cout << "CoeffMatrix : DONE !!\n";

}

template<class T>
void Solver<T>::SolveEOM()
{
    //std::cout << "Filling EOM_rhs vector !!\n";
    EOM_rhs << eval_frc_eq(), -eval_acc_eq();

    //std::cout << "Calling LUSolver.compute(CoeffMatrix) !!\n";
    LUSolver.compute(CoeffMatrix);
    //std::cout << "LUSolver.info = \n" << LUSolver.info() << "\n";
    //std::cout << "Calling LUSolver.solve(EOM_rhs) !!\n";
    auto x = LUSolver.solve(EOM_rhs);

    //std::cout << "Calling qdd = x.segment(0, model.n) !!\n";
    qdd = x.segment(0, model.n);
    //std::cout << "Calling lgr = x.segment(model.n, model.nc) !!\n";
    lgr = x.segment(model.n, model.nc);

}

template<class T>
Eigen::VectorXd Solver<T>::SSODE(Eigen::VectorXd _StateVectorD0, double t, double h)
{
    const auto& y1 = _StateVectorD0.head(dof);
    const auto& y2 = _StateVectorD0.tail(dof);

    SetTime(t);

    q   = pos_history.back();
    qd  = vel_history.back();
    qdd = acc_history.back();

    q += (qd * h) + (0.5 * qdd * (h*h));

    int i = dof-1;
    for (const auto& index : coord_indices)
    {
        //std::cout << "q(index) = y1(i) \n";
        q(index) = y1(i);
        i--;
    };

    //std::cout << "SolveConstraints() \n";
    SolveConstraints();

    //std::cout << "vel_rhs << -vel_rhs_nc, y2; \n";
    Eigen::VectorXd vel_rhs(model.n);
    auto vel_rhs_nc = eval_vel_eq();
    vel_rhs << -vel_rhs_nc, y2;

    //std::cout << "qd = LUSolver.solve(vel_rhs) \n";
    qd = LUSolver.solve(vel_rhs);

    //std::cout << "ConstructCoeffMatrix() \n";
    ConstructCoeffMatrix();
    //std::cout << "SolveEOM() \n";
    SolveEOM();

    const auto& y3 = (CoordinatesPermutation * qdd).segment(model.nc, dof);

    StateVectorD1 << y2, y3;

    //std::cout << "\nStateVectorD0 = " << StateVectorD0.transpose() << "\n";
    //std::cout << "StateVectorD1 = " << StateVectorD1.transpose() << "\n\n";

    return StateVectorD1;

};

}; // namespace dds


