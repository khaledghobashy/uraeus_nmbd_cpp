
#include "dwb_test.hpp"

int solve(double simTime, double steps)
{
    Topology model("");

    Configuration& Config = model.config;
    
    Config.constructFromJSON("double_wishbone_direct_acting.json");
    std::cout << "Constructed JSON File" << std::endl;

    Config.set_inital_configuration();

    Config.UF_mcr_wheel_lock = [](double t)->double{return 0;};
    Config.UF_mcl_wheel_lock = [](double t)->double{return 0;};

    Config.UF_mcr_wheel_travel = [](double t)->double{return 546 + 150*std::sin(t);};
    Config.UF_mcl_wheel_travel = [](double t)->double{return 546 - 150*std::sin(t);};

    Solver<Topology> Soln(model);
    Soln.set_time_array(simTime, steps);
    Soln.Solve();
    Soln.ExportResultsCSV("", 0);

    return 0;
};

