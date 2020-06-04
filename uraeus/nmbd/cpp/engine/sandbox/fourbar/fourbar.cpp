#include "uraeus/solvers/solvers.hpp"

#include "spatial_fourbar.hpp"


int main()
{
    Topology model{""};

    Configuration& Config = model.config;
    
    Config.constructFromJSON("fourbar.json");
    std::cout << "Constructed JSON File" << std::endl;

    Config.set_inital_configuration();

    Config.UF_mcs_act = [](double t)->double{return 2*(22.0/7)*t;};

    std::cout << "\nInitializing Model!" << std::endl;
    model.initialize();

    Solver<Topology> Soln(model);
    Soln.set_time_array(5, 5e-3);
    Soln.Solve();
    Soln.ExportResultsCSV("", "pos", 0);

    return 0;
}
