
#include <numeric>

#include "uraeus/solvers/solvers.hpp"

#include "double_wishbone_direct_acting.hpp"

#include "simulation.hpp"

void test_sim()
{
    auto sim = Simulation();

    sim.ConstructConfiguration("double_wishbone_direct_acting.json");

    sim.set_UF_mcr_wheel_lock([](double t)->double{return 0;});
    sim.set_UF_mcl_wheel_lock([](double t)->double{return 0;});

    sim.set_UF_mcr_wheel_travel([](double t)->double{return 546 + 170*std::sin(t);});    
    sim.set_UF_mcl_wheel_travel([](double t)->double{return 546 - 170*std::sin(t);});

    sim.Solve(2*(22.0/7), 5e-3);

    sim.SaveResults("", "pos", 0);
    sim.SaveResults("", "vel", 1);
    sim.SaveResults("", "acc", 2);

}

void test_Solver()
{
    Solver<Topology> Soln{};
    
    Soln.model.config.constructFromJSON("double_wishbone_direct_acting.json");
    std::cout << "Constructed JSON File" << std::endl;

    Soln.model.config.set_inital_configuration();

    Soln.model.config.UF_mcr_wheel_lock = [](double t)->double{return 0;};
    Soln.model.config.UF_mcl_wheel_lock = [](double t)->double{return 0;};

    Soln.model.config.UF_mcr_wheel_travel = [](double t)->double{return 546 + 150*std::sin(t);};
    Soln.model.config.UF_mcl_wheel_travel = [](double t)->double{return 546 - 150*std::sin(t);};

    std::cout << "\nInitializing Model!" << std::endl;
    Soln.initialize();

    Soln.set_time_array(5, 5e-3);
    Soln.Solve();
    Soln.ExportResultsCSV("", "pos", 0);

}


int main()
{

    //test_Solver();
    test_sim();

    return 0;
}
