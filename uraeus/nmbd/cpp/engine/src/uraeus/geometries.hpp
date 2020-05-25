#pragma once

#include <eigen/Eigen/Dense>
#include <vector>
#include <numeric>


struct geometry
{
public:
    Eigen::Vector3d R ;
    Eigen::Vector4d P ;
    Eigen::Matrix3d J ;
    Eigen::Matrix3d I ;
    double m;
};

geometry cylinder_geometry(Eigen::Vector3d& p1, Eigen::Vector3d& p2, double& ro, double ri = 0);
geometry triangular_prism(Eigen::Vector3d& p1, Eigen::Vector3d& p2, Eigen::Vector3d& p3, double thickness);
geometry composite_geometry(std::vector<geometry>& geometries);
geometry sphere_geometry(Eigen::Vector3d& p1, double& ro);

