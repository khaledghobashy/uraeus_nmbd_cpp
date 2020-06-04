#include "Topology.hpp"

class NotImplemented : public std::logic_error
{
public:
    NotImplemented() : std::logic_error("Function not yet implemented") { };
};


void ATopology::map_indicies()
{
    std::cout << "Mapping Indicies!" << std::endl;
    int i = 0;
    for (auto& name : names)
    {
        std::cout << name << std::endl;
        indicies_map[prefix + name] = i;
        i++;
    };
};

void ATopology::initialize()
{
    Dict_SS interface_map;
    t = 0;
    map_indicies();
    assemble(indicies_map, interface_map, 0);
    set_initial_states();
    eval_constants();

};

void ATopology::set_gen_coordinates(const Eigen::Ref<Eigen::VectorXd>& q)
{
    this-> q << q;
};

void ATopology::set_gen_velocities(const Eigen::Ref<Eigen::VectorXd>& qd)
{
    this-> qd << qd;
};

void ATopology::set_gen_accelerations(const Eigen::Ref<Eigen::VectorXd>& qdd)
{
    this-> qdd << qdd;
};

