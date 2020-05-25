
#include "geometries.hpp"
#include "spatial_algebra.hpp"
#include "euler_parameters.hpp"

#include <iostream>


geometry cylinder_geometry(Eigen::Vector3d& p1, Eigen::Vector3d& p2, double& ro, double ri)
{   
    geometry geo;

    Eigen::Vector3d axis = p2 - p1 ;
    auto frame = triad(axis);
    
    const double l = axis.norm();
    const double vol = (22/7)*(std::pow(ro, 2) - std::pow(ri,2)) * l * 1e-3;

    double m = 7.9/vol ;
    const double Jzz = (m/2)*(std::pow(ro,2) + std::pow(ri,2));
    const double Jyy = (m/12)*(3*(std::pow(ro,2) + std::pow(ri,2)) + std::pow(l,2));
    const double Jxx = Jyy ;

    Eigen::Vector4d P = A2P(frame);
    Eigen::DiagonalMatrix<double, 3> J(Jxx, Jyy, Jzz);

    geo.R = centered({p1, p2});
    geo.P << 1, 0, 0, 0 ;
    geo.J = A(P).transpose() * J * A(P) ;
    geo.m = m ;

    return geo;

};


geometry triangular_prism(Eigen::Vector3d& p1, Eigen::Vector3d& p2, Eigen::Vector3d& p3, double thickness)
{
    geometry geo;

    double l1, l2, l3, pr, theta, height, area, volume, density;

    Eigen::Vector3d v1 = p1 - p2 ;
    Eigen::Vector3d v2 = p1 - p3 ;
    Eigen::Vector3d v3 = p2 - p3 ;

    l1 = v1.norm();
    l2 = v2.norm();
    l3 = v3.norm();

    pr = (l1 + l2 + l3) / 2 ;

    double cos_theta = v1.transpose() * v2;
    cos_theta = cos_theta / (l1*l2) ;
    theta = std::acos(cos_theta);
    height = l2 * std::sin(theta);
    area = std::sqrt(pr*(pr - l1)*(pr-l2)*(pr-l3)) ;
    volume = area * height ;
    density = 7.9 ;

    Eigen::Vector3d v = oriented({p1, p2, p3});
    Eigen::Matrix3d frame = triad(v, v1) ;

    double a = v2.transpose() * v1 ;

    double Ixc = (l1*std::pow(height,3)) / 36 ;
    double Iyc = ((std::pow(l1,3)*height)-(std::pow(l1,2)*height*a)+(l1*height*std::pow(a,2))) / 36 ;
    double Izc = ((std::pow(l1,3)*height)-(std::pow(l1,2)*height*a)+(l1*height*std::pow(a,2))+(l1*std::pow(height,3))) / 36 ;

    double mass = density * volume * 1e-3;
    Eigen::Vector4d P = A2P(frame);
    Eigen::DiagonalMatrix<double, 3> J(Ixc, Iyc, Izc);
    J = mass*J;
    
    geo.R = centered({p1, p2, p3});
    geo.P << 1, 0, 0, 0 ;
    geo.J = A(P).transpose() * J * A(P) ;
    geo.m = mass ;

    return geo;

};

geometry sphere_geometry(Eigen::Vector3d& p1, double& ro)
{
    geometry geo;

    double vol = (22/7) * (4/3) * std::pow(ro, 3) * 1e-3;
    double m   = 7.9 * vol;
    double Jp  = (2/5) * m * std::pow(ro, 2);

    Eigen::DiagonalMatrix<double, 3> J(Jp, Jp, Jp);
    Eigen::Vector4d P{1, 0, 0, 0};

    geo.R = p1;
    geo.P = P;
    geo.m = m;
    geo.J = J;

    return geo;
    
};

geometry composite_geometry(std::vector<geometry>& geometries)
{
    geometry geo;

    double m = 0;
    Eigen::Vector3d R;
    Eigen::Matrix3d J;
    const auto& I = Eigen::MatrixXd::Identity(3, 3);

    // composite body total mass as the sum of it's subcomponents
    for (auto g : geometries) {m += g.m;};

    // center of mass vector relative to the origin
    for (auto g : geometries) { R += (g.m * g.R);};
    R *= (1/m);

    for (auto g : geometries)
    {
        const auto& d = g.R - R;
        J += (
                A(g.P) * (g.J) * (A(g.P).transpose())
              + g.m * (d.squaredNorm()*I - d*d.transpose())
             );

    };
    
    Eigen::Vector4d P{1, 0, 0, 0};

    geo.R = R;
    geo.P = P;
    geo.m = m;
    geo.J = J;

    return geo;
};
