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
#include "solvers_base.hpp"
#include "sparse_assembler.hpp"
#include "utilities.hpp"


// ============================================================================ 
//                         Solver Template Class
// ============================================================================

namespace kds
{

// Declaring and Implementing the Solver class as a template class.
// Type T should be any Topology class type.
template <class T>
class Solver : public BaseSolver<T>
{
public:

    Solver();
    void Solve();

private:

    void SolveConstraints();
    void solve_lgr_multipliers();

};


// ============================================================================ 
//                         CLASS METHODS IMPLEMENTATION
// ============================================================================
template<class T>
Solver<T>::Solver()
    : BaseSolver<T>::BaseSolver()
{};

// ============================================================================ 
//                          Lagrange Multipliers Solver
// ============================================================================

template<class T>
void Solver<T>::solve_lgr_multipliers()
{
    this->eval_mas_eq();
    Eigen::VectorXd ext_frc = this->eval_frc_eq();
    Eigen::VectorXd inertia = this->MassMatrix * this->qdd;
    Eigen::VectorXd rhs = ext_frc - inertia;
    this->LUSolver.compute(this->Jacobian.transpose());
    this->lgr = this->LUSolver.solve(rhs);
};

// ============================================================================ 
//                    Position Constraints Iterative Solver
// ============================================================================


template<class T>
void Solver<T>::SolveConstraints()
{    
    // Creating a LUSolver object.

    //std::cout << "Evaluating Pos_Eq " << "\n";
    auto&& b = this->eval_pos_eq();
    //std::cout << "Evaluating Jac_Eq " << "\n";
    this->eval_jac_eq();
    //std::cout << "Computing Matrix A " << "\n";
    this->LUSolver.compute(this->Jacobian);

    //std::cout << "Solving for Vector b " << "\n";
    Eigen::VectorXd error = this->LUSolver.solve(-b);

    //std::cout << "Entring While Loop " << "\n";
    int itr = 0;
    while (error.norm() >= 1e-5)
    {
        //std::cout << "Error e = " << error.norm() << "\n";
        //guess += error;
        //q = guess;
        this->q += error;
        b = this->eval_pos_eq();
        error = this->LUSolver.solve(-b);

        if (itr%5 == 0 && itr!=0)
        {
            this->eval_jac_eq();
            this->LUSolver.compute(this->Jacobian);
            error = this->LUSolver.solve(-b);
        };

        if (itr>50)
        {
            std::cout << "ITERATIONS EXCEEDED!! " << itr << "\n" ;
            break;
        };

        itr++;
    };
    
    this->eval_jac_eq();
    this->LUSolver.compute(this->Jacobian);
};

// ============================================================================ 
//                              Simulation Loop
// ============================================================================

template<class T>
void Solver<T>::Solve()
{
    std::cout << "Starting Solver ..." << "\n";
    
    auto& dt = this->step_size;
    auto samples = this->time_array.size();

    this->ResetStates();

    this->pos_history.reserve(samples);
    this->vel_history.reserve(samples);
    this->acc_history.reserve(samples);
    this->lgr_history.reserve(samples);
    this->rct_history.reserve(samples);
    
    //std::cout << "Computing Jacobian" << "\n";
    this->eval_jac_eq();
    //std::cout << "Factorizing Jacobian" << "\n";
    this->LUSolver.compute(this->Jacobian);

    //std::cout << "Solving for Velocity" << "\n";
    this->qd = this->LUSolver.solve(-this->eval_vel_eq());
    
    //std::cout << "Solving for Accelerations" << "\n";
    this->qdd = this->LUSolver.solve(-this->eval_acc_eq());

    this->solve_lgr_multipliers();
    this->eval_rct_eq();

    this->UpdateHistories();

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end;

    std::cout << "\nRunning System Kinematic Analysis: " << "\n";
    for (size_t i = 1; i < samples; i++)
    {
        print_progress(begin, samples, i);

        this->t = this->time_array(i) ;
        this->SetTime(this->t) ;

        this->q += (this->qd * dt) + (0.5 * this->qdd * (dt*dt));

        this->SolveConstraints();

        this->qd  = this->LUSolver.solve(-this->eval_vel_eq());
        this->qdd = this->LUSolver.solve(-this->eval_acc_eq());

        this->solve_lgr_multipliers();
        this->eval_rct_eq();
        
        this->UpdateHistories();

    };

    this->results[0] = &this->pos_history;
    this->results[1] = &this->vel_history;
    this->results[2] = &this->acc_history;
    this->results[3] = &this->lgr_history;
    this->results[4] = &this->rct_history;

    std::cout << "\n";
    std::cout << "Finished Solver ... \n";

};

}; // namespace kds

