
#include "euler_parameters.hpp"


Eigen::Vector4d A2P(Eigen::Matrix3d& dcm)
{
    double e0s, e1s, e2s, e3s, emax, e0, e1, e2, e3 ;
    Eigen::Vector4d P;
    const double trace = dcm.trace();

    e0s = (trace + 1) / 4 ;
    e1s = (2*dcm(0,0) - trace + 1) / 4 ;
    e2s = (2*dcm(1,1) - trace + 1) / 4 ;
    e3s = (2*dcm(2,2) - trace + 1) / 4 ;

    emax = std::max({e0s, e1s, e2s, e3s});

    if (e0s == emax)
    {
        e0 = std::abs(std::sqrt(e0s)) ;
        e1 = (dcm(2,1) - dcm(1,2)) / (4*e0) ;
        e2 = (dcm(0,2) - dcm(2,0)) / (4*e0) ;
        e3 = (dcm(0,1) - dcm(1,0)) / (4*e0) ;
    }    
    else if (e1s == emax)
    {
        e1 = std::abs(std::sqrt(e1s)) ;
        e0 = (dcm(2,1) - dcm(1,2)) / (4*e1) ;
        e2 = (dcm(0,1) + dcm(1,0)) / (4*e1) ;
        e3 = (dcm(0,2) + dcm(2,0)) / (4*e1) ;
    
    }
    else if (e2s == emax)
    {
        e2 = std::abs(std::sqrt(e2s)) ;
        e0 = (dcm(0,2) - dcm(2,0)) / (4*e2) ;
        e1 = (dcm(0,1) + dcm(1,0)) / (4*e2) ;
        e3 = (dcm(2,1) + dcm(1,2)) / (4*e2) ;
    
    }
    else if (e3s == emax)
    {
        e3 = std::abs(std::sqrt(e3s)) ;
        e0 = (dcm(0,1) - dcm(1,0)) / (4*e3) ;
        e1 = (dcm(0,2) + dcm(2,0)) / (4*e3) ;
        e2 = (dcm(2,1) + dcm(1,2)) / (4*e3) ;
    };

    P << e0, e1, e2, e3 ;
    return P ;
};


Eigen::Matrix<double, 3, 4> G(const Eigen::Vector4d& P)
{
    const double& e0 = P[0];
    const double& e1 = P[1];
    const double& e2 = P[2];
    const double& e3 = P[3];

    Eigen::Matrix<double, 3, 4> m;
    m <<
    -e1, e0, e3,-e2,
    -e2,-e3, e0, e1,
    -e3, e2,-e1, e0;

    return m;
};


Eigen::Matrix<double, 3, 4> E(const Eigen::Vector4d& P)
{
    const double& e0 = P[0];
    const double& e1 = P[1];
    const double& e2 = P[2];
    const double& e3 = P[3];

    Eigen::Matrix<double, 3, 4> m;
    m <<
    -e1, e0,-e3, e2,
    -e2, e3, e0,-e1,
    -e3,-e2, e1, e0;

    return m;
};


Eigen::Matrix3d A(const Eigen::Vector4d& P)
{
    const double& e0 = P[0];
    const double& e1 = P[1];
    const double& e2 = P[2];
    const double& e3 = P[3];

    Eigen::Matrix3d A;

    A <<
    (e0*e0) + (e1*e1) - (e2*e2) - (e3*e3), 
    2*((e1*e2) - (e0*e3)), 
    2*((e1*e3) + (e0*e2)),

    2*((e1*e2) + (e0*e3)), 
    (e0*e0) - (e1*e1) + (e2*e2) - (e3*e3),
    2*((e2*e3) - (e0*e1)),

    2*((e1*e3) - (e0*e2)),
    2*((e2*e3) + (e0*e1)),
    (e0*e0) - (e1*e1) - (e2*e2) + (e3*e3);

    return A;
};


Eigen::Matrix<double, 3, 4> B(const Eigen::Vector4d& P, const Eigen::Vector3d& u)
{
    Eigen::Matrix<double, 3, 4> mat;

    const double& e0 = P[0];
    const double& e1 = P[1];
    const double& e2 = P[2];
    const double& e3 = P[3];
    
    const double& ux = u[0];
    const double& uy = u[1];
    const double& uz = u[2];
    
    mat << 
     2*e0*ux + 2*e2*uz - 2*e3*uy , 
     2*e1*ux + 2*e2*uy + 2*e3*uz , 
     2*e0*uz + 2*e1*uy - 2*e2*ux , 
    -2*e0*uy + 2*e1*uz - 2*e3*ux ,
    
     2*e0*uy - 2*e1*uz + 2*e3*ux ,
    -2*e0*uz - 2*e1*uy + 2*e2*ux ,
     2*e1*ux + 2*e2*uy + 2*e3*uz ,
     2*e0*ux + 2*e2*uz - 2*e3*uy ,
    
     2*e0*uz + 2*e1*uy - 2*e2*ux ,
     2*e0*uy - 2*e1*uz + 2*e3*ux ,
    -2*e0*ux - 2*e2*uz + 2*e3*uy ,
     2*e1*ux + 2*e2*uy + 2*e3*uz ;

    return mat;

};


