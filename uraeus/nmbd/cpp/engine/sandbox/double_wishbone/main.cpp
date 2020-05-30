
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

    /* std::cout << Config.R_rbr_hub << std::endl;
    std::cout << Config.R_rbl_hub << std::endl;

    std::cout << Config.R_rbr_uca << std::endl;
    std::cout << Config.R_rbl_uca << std::endl;

    std::cout << Config.R_rbr_lca << std::endl;
    std::cout << Config.R_rbl_lca << std::endl;

    std::cout << Config.R_rbr_upper_strut << std::endl;
    std::cout << Config.R_rbl_upper_strut << std::endl;

    std::cout << Config.R_rbr_upright << std::endl;
    std::cout << Config.R_rbl_upright << std::endl;

    std::cout << Config.q << std::endl;
    std::cout << Config.qd << std::endl; */

    Config.UF_mcr_wheel_lock = [](double t)->double{return 0;};
    Config.UF_mcl_wheel_lock = [](double t)->double{return 0;};

    Config.UF_mcr_wheel_travel = [](double t)->double{return 546 + 150*std::sin(t);};
    Config.UF_mcl_wheel_travel = [](double t)->double{return 546 - 150*std::sin(t);};

    Solver<Topology> Soln(model);
    Soln.set_time_array(2*(22./7), 2*(22./7) * 1e2);
    Soln.Solve();
    Soln.ExportResultsCSV("", 0);


    return 0;
}
