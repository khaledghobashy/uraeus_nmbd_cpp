
#include "simulation.hpp"

Simulation::Simulation()
{
    std::cout << "Initiallizing Simulation" << std::endl;
    this->Model = Topology("");
};

void Simulation::ConstructConfiguration(std::string fileName)
{
    Config.constructFromJSON(fileName);
    std::cout << "\nConfiguration constructed from file!" << std::endl;
    Config.set_inital_configuration();
    std::cout << "\nConfiguration q = " << Config.q << std::endl;

    std::cout << "\nInitializing Model!" << std::endl;
    Model.initialize();
    std::cout << "\nSetting Gen-Coord!" << std::endl;
    Model.set_gen_coordinates(Config.q);

    std::cout << "\nINITIALIZING SOLVER!!" << std::endl;
    this->Soln = Solver<Topology>(this->Model);
    std::cout << "\nSolver.Model q = " << Soln.model_ptr->q0 << std::endl;


};


void Simulation::Solve(double simTime, double steps)
{
    std::cout << Config.UF_mcr_wheel_lock(0) << std::endl;
    std::cout << Config.UF_mcl_wheel_lock(0) << std::endl;
    std::cout << Config.UF_mcr_wheel_travel(0) << std::endl;
    std::cout << Config.UF_mcl_wheel_travel(0) << std::endl;

    Soln.set_time_array(simTime, steps);
    Soln.Solve();
    std::cout << "\n\nCxx Solver End!" << std::endl;
};

void Simulation::SaveResults(std::string location, std::string name, int level)
{
    std::cout << "\nCalling Simulation::SaveResults!" << std::endl;
    Soln.ExportResultsCSV(location, name, level);
};


void Simulation::set_UF_mcr_wheel_lock_func(FUNC func)
{
    Config.UF_mcr_wheel_lock = *func;
    std::cout << "Calling func set_UF_mcr_wheel_lock_func -> " << 
    Config.UF_mcr_wheel_lock(0) << std::endl;

};

void Simulation::set_UF_mcl_wheel_lock_func(FUNC func)
{
    Config.UF_mcl_wheel_lock = *func;
    std::cout << "Calling func set_UF_mcl_wheel_lock_func -> " <<
    Config.UF_mcl_wheel_lock(0) << std::endl;
};

void Simulation::set_UF_mcr_wheel_travel_func(FUNC func)
{
    Config.UF_mcr_wheel_travel = *func;
    std::cout << "Calling func set_UF_mcr_wheel_travel_func -> " <<
    Config.UF_mcr_wheel_travel(0) << std::endl;
};

void Simulation::set_UF_mcl_wheel_travel_func(FUNC func)
{
    Config.UF_mcl_wheel_travel = *func;
    std::cout << "Calling func set_UF_mcl_wheel_travel_func -> " <<
    Config.UF_mcl_wheel_travel(0) << std::endl;
};

