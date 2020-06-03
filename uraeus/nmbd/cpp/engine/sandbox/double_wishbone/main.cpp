
#include <numeric>

#include "uraeus/solvers/solvers.hpp"

#include "double_wishbone_direct_acting.hpp"


int main()
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
    
    model.initialize();
    model.set_gen_coordinates(Config.q);
    
    Solver<Topology> Soln(model);
    Soln.set_time_array(2*(22./7), 5e-3);
    Soln.Solve();
    Soln.ExportResultsCSV("", "pos", 0);


    return 0;
}
