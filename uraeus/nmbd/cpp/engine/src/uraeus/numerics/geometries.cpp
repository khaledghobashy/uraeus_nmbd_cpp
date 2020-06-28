/*
============================================================================
                            uraeus.nmbd.cpp
============================================================================

Use of this source code is governed by a BSD-style license that can be found
in the LICENSE file at the top level of the distribution.

Authors:
    - Khaled Ghobashy


============================================================================
                                Summary
============================================================================

*/

// Local includes
#include "geometries.hpp"


// geometry class default constructor with initializer list
// --------------------------------------------------------
geometry::geometry()
    :
        R(0, 0, 0),
        P(1, 0, 0, 0),
        J(),
        m(0)
    {
        J << 0, 0, 0, 0, 0, 0, 0, 0, 0;
    };


// cylinder geometry function returning a geometry object
// ------------------------------------------------------
geometry cylinder_geometry(Eigen::Vector3d& p1, Eigen::Vector3d& p2, double& ro, double ri)
{   

    geometry geo;

    Eigen::Vector3d axis = p2 - p1 ;
    auto frame = triad(axis);
    const double length = axis.norm();

    const double density = 7.9*1e-3;
    
    const double vol = (22./7) * (std::pow(ro, 2) - std::pow(ri, 2)) * length;

    double m = density * vol ;

    const double Jzz = (m/2) * (std::pow(ro, 2) + std::pow(ri, 2));
    const double Jyy = (m/12) * (3 * (std::pow(ro, 2) + std::pow(ri, 2)) + std::pow(length, 2));
    const double Jxx = Jyy ;

    Eigen::Vector4d P = A2P(frame);
    Eigen::DiagonalMatrix<double, 3> J(Jxx, Jyy, Jzz);

    geo.J = A(P) * J * A(P).transpose() ;
    geo.P << 1, 0, 0, 0 ;
    
    geo.R = centered({p1, p2});
    geo.m = m ;

    return geo;

};


// triangular_prism geometry function returning a geometry object
// --------------------------------------------------------------
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

    // The normal height of the vertix from the base.
    double cos_theta = v1.transpose() * v2;
    cos_theta = cos_theta / (l1*l2) ;
    theta = std::acos(cos_theta);
    height = l2 * std::sin(theta);
    area = std::sqrt(pr*(pr - l1)*(pr-l2)*(pr-l3)) ;
    volume = area * thickness ;
    density = 7.9*1e-3;

    // Creating a centroidal reference frame with z-axis normal to triangle
    // plane and x-axis oriented with the selected base vector v1.
    Eigen::Vector3d v = oriented({p1, p2, p3});
    Eigen::Matrix3d frame = triad(v, v1) ;

    // Calculating the principle inertia properties "moment of areas" at the
    // geometry centroid.
    double a = v2.transpose() * (v1/l1) ;
    double Ixc = (l1*std::pow(height,3)) / 36 ;
    double Iyc = ((std::pow(l1,3)*height)-(std::pow(l1,2)*height*a)+(l1*height*std::pow(a,2))) / 36 ;
    double Izc = ((std::pow(l1,3)*height)-(std::pow(l1,2)*height*a)+(l1*height*std::pow(a,2))+(l1*std::pow(height,3))) / 36 ;


    // Evaluating the moments of inertia of the side-walls
    double Ix_n = (1/12) * std::pow(thickness, 3) * l1;
    double Iy_n = (1/12) * std::pow(thickness, 3) * height;

    // Evaluating mass
    double mass = density * volume;

    // Calculating the total moment of inertia from the moment of areas
    double Ix = ((mass/area) * Ixc + ((mass/thickness*l1) * Ix_n));
    double Iy = ((mass/area) * Iyc + ((mass/thickness*height) * Iy_n));
    double Iz = ((mass/area) * Izc);

    // Evaluate Geometry properties
    Eigen::Vector4d P = A2P(frame);
    Eigen::DiagonalMatrix<double, 3> J(Ix, Iy, Iz);

    //  Transforming Inertia to the Global Frame
    geo.J = A(P) * J * A(P).transpose() ;
    geo.P << 1, 0, 0, 0 ;

    geo.R = centered({p1, p2, p3});
    geo.m = mass ;

    return geo;

};


// sphere_geometry geometry function returning a geometry object
// -------------------------------------------------------------
geometry sphere_geometry(Eigen::Vector3d& p1, double& ro)
{
    geometry geo;

    double vol = (22./7) * (4./3) * std::pow(ro, 3);
    double m   = 7.9*1e-3 * vol;
    double Jp  = (2./5) * m * std::pow(ro, 2);

    Eigen::DiagonalMatrix<double, 3> J(Jp, Jp, Jp);
    Eigen::Vector4d P{1, 0, 0, 0};

    geo.R = p1;
    geo.P = P;
    geo.m = m;
    geo.J = J;

    return geo;
    
};

// composite_geometry geometry function returning a geometry object
// ----------------------------------------------------------------
geometry composite_geometry(std::vector<geometry>& geometries)
{
    geometry geo;

    auto& m = geo.m;
    auto& R = geo.R;
    auto& J = geo.J;

    const auto& I = Eigen::MatrixXd::Identity(3, 3);

    // composite body total mass as the sum of it's subcomponents
    for (const auto& g : geometries) {m += g.m;};
    //std::cout << "Geometry mass = " << m << std::endl;

    // center of mass vector relative to the origin
    for (const auto& g : geometries)
    { 
        R += (1/m) * (g.m * g.R);
        //std::cout << "R = " << R << std::endl;
    };
    //std::cout << "Geometry R = " << R << std::endl;

    for (const auto& g : geometries)
    {
        auto d = g.R - R;
        J += (
                A(g.P) * (g.J) * (A(g.P).transpose())
              + g.m * (d.squaredNorm()*I - d*d.transpose())
             );

    };
    
    geo.P << 1, 0, 0, 0;

    return geo;
};
