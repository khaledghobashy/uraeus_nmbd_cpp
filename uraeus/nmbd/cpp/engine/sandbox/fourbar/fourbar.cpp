#include "uraeus/solvers/solvers.hpp"

#include "spatial_fourbar.hpp"


int main()
{
    Topology model("");

    Configuration& Config = model.config;
    
    Config.constructFromJSON("fourbar.json");
    std::cout << "Constructed JSON File" << std::endl;

    Config.set_inital_configuration();

    Config.UF_mcs_act = [](double t)->double{return 2*(22/7)*t;};

    Solver<Topology> Soln(model);
    Soln.set_time_array(1, 100);
    Soln.Solve();
    Soln.ExportResultsCSV("", 0);


    return 0;
}
