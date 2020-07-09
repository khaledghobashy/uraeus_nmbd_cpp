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
    : BaseSolver()
{};

// ============================================================================ 
//                          Lagrange Multipliers Solver
// ============================================================================

template<class T>
void Solver<T>::solve_lgr_multipliers()
{
    eval_mas_eq();
    Eigen::VectorXd ext_frc = eval_frc_eq();
    Eigen::VectorXd inertia = MassMatrix * qdd;
    Eigen::VectorXd rhs = ext_frc - inertia;
    LUSolver.compute(Jacobian.transpose());
    lgr = LUSolver.solve(rhs);
};

// ============================================================================ 
//                    Position Constraints Iterative Solver
// ============================================================================


template<class T>
void Solver<T>::SolveConstraints()
{    
    // Creating a LUSolver object.

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
        //guess += error;
        //q = guess;
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

// ============================================================================ 
//                              Simulation Loop
// ============================================================================

template<class T>
void Solver<T>::Solve()
{
    std::cout << "Starting Solver ..." << "\n";
    
    auto& dt = step_size;
    auto samples = time_array.size();

    ResetStates();

    pos_history.reserve(samples);
    vel_history.reserve(samples);
    acc_history.reserve(samples);
    lgr_history.reserve(samples);
    rct_history.reserve(samples);
    
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

    UpdateHistories();

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end;

    std::cout << "\nRunning System Kinematic Analysis: " << "\n";
    for (size_t i = 1; i < samples; i++)
    {
        print_progress(begin, samples, i);

        t = time_array(i) ;
        SetTime(t) ;

        q += (qd * dt) + (0.5 * qdd * (dt*dt));

        SolveConstraints();

        qd  = LUSolver.solve(-eval_vel_eq());
        qdd = LUSolver.solve(-eval_acc_eq());

        solve_lgr_multipliers();
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

}; // namespace kds

// ============================================================================ 
// ============================================================================
// ============================================================================
