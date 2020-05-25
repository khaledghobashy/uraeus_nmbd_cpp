#include <iostream>
#include <vector>

#include "uraeus/helpers.hpp"
#include "uraeus/euler_parameters.hpp"
#include "uraeus/geometries.hpp"


int main()
{
    Eigen::Matrix3d mat = Eigen::Matrix3d::Identity(3,3);
    std::cout<< "P = " << A2P(mat) << "\n";

    Eigen::Vector3d p1, p2 ;
    double ro = 10 ;

    p1 << 0,0,0;
    p2 << 5,5,5;

    auto geo = cylinder_geometry(p1, p2, ro);

    std::cout<< "geo.R = \n" << geo.R << "\n\n";
    std::cout<< "geo.P = \n" << geo.P << "\n\n";
    std::cout<< "geo.J = \n" << geo.J << "\n\n";
    std::cout<< "geo.m = \n" << geo.m << "\n\n";

}
