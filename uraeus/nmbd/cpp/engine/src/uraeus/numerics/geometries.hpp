#pragma once

// Standard Library Includes.
#include <iostream>
#include <vector>
#include <numeric>

// 3rd Party Includes.
#include <eigen/Eigen/Dense>

// Local Libraries Includes.
#include "spatial_algebra.hpp"
#include "euler_parameters.hpp"


struct geometry
{
public:
    Eigen::Vector3d R = {0, 0, 0};
    Eigen::Vector4d P = {1, 0, 0, 0};
    Eigen::Matrix3d J ;
    Eigen::Matrix3d I ;
    double m = 0;
};

geometry cylinder_geometry(Eigen::Vector3d& p1, Eigen::Vector3d& p2, double& ro, double ri = 0);
geometry triangular_prism(Eigen::Vector3d& p1, Eigen::Vector3d& p2, Eigen::Vector3d& p3, double thickness);
geometry composite_geometry(std::vector<geometry>& geometries);
geometry sphere_geometry(Eigen::Vector3d& p1, double& ro);

