#include "uraeus/solvers/solvers.hpp"

#include "new_API/spatial_fourbar.hpp"
//#include "spatial_fourbar.hpp"


void test_model()
{
    Eigen::VectorXd q(Topology::n);
    Eigen::VectorXd qd(Topology::n);
    Eigen::VectorXd qdd(Topology::n);

    Topology model("", q, qd, qdd);
    model.config.constructFromJSON("fourbar.json");

}

void test_Solver()
{
    //ConfigurationAssembler Config("fourbar.json");

    Solver<Topology> Soln{};
    
    Soln.model.config.constructFromJSON("fourbar.json");
    std::cout << "Constructed JSON File" << std::endl;

    Soln.model.config.set_inital_configuration();

    Soln.model.config.UF_mcs_act = [](double t)->double{return 2*(22.0/7)*t;};

    std::cout << "\nInitializing Model!" << std::endl;
    Soln.initialize();

    //std::cout << "Soln.q = \n" << Soln.q << "\n";
    //std::cout << "model.q = \n" << Soln.model.coord.m_q << "\n";

    Soln.set_time_array(5, 5e-3);
    Soln.Solve();
    Soln.ExportResultsCSV("", "pos", 0);

}

int main()
{
    //test_model();
    test_Solver();
    return 0;
}
