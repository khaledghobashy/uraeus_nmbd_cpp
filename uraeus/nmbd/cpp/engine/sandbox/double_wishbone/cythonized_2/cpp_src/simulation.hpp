#pragma once

#include <numeric>
#include "uraeus/solvers/solvers.hpp"
#include "double_wishbone_direct_acting.hpp"

//typedef std::function<double(double)> FUNC;

typedef double (*FUNC)(double);

class Simulation
{

public:
    Simulation();

public:
    Topology Model; // = Topology("");
    Configuration& Config = Model.config;// = Model.config;
    Solver<Topology> Soln; // =  Solver<Topology>(model);

public:
    void Solve(double simTime, double steps);
    void ConstructConfiguration(std::string fileName);
    void SaveResults(std::string location, std::string name, int level);

public:
    void set_UF_mcr_wheel_lock_func(FUNC func);
    void set_UF_mcl_wheel_lock_func(FUNC func);

    void set_UF_mcr_wheel_travel_func(FUNC func);
    void set_UF_mcl_wheel_travel_func(FUNC func);
    
};
