#include "simulation.hpp"

int main()
{
    std::cout << "\nSTARTING!!" << std::endl;
    Simulation sim = Simulation();

    sim.ConstructConfiguration("double_wishbone_direct_acting.json");

    sim.set_UF_mcr_wheel_lock_func([](double t)->double{return 0;});
    sim.set_UF_mcl_wheel_lock_func([](double t)->double{return 0;});

    sim.set_UF_mcr_wheel_travel_func([](double t)->double{return 546 + 130*sin(t);});
    sim.set_UF_mcl_wheel_travel_func([](double t)->double{return 546 + 130*sin(t);});

    sim.Solve(5, 100);

    sim.SaveResults("", "pos", 0);
    sim.SaveResults("", "vel", 1);
    sim.SaveResults("", "acc", 2);

    return 0;
}
