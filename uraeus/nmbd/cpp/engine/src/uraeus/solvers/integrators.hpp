
#include <eigen/Eigen/Eigen>
#include <functional>

class Explicit_RK4
{

public:
    Explicit_RK4(Eigen::Index dof);
    
    double h;
    double t;
    Eigen::Index n_stages;

    std::function<Eigen::VectorXd(Eigen::VectorXd, double, double)> SSODE;

    Eigen::MatrixXd K;
    Eigen::VectorXd y;

    const Eigen::MatrixXd A = (Eigen::MatrixXd(4, 4) << 
                                0, 0, 0,   0,
                                1/2, 0, 0, 0,
                                0, 1/2, 0, 0,
                                0,  0, 1,  0).finished();
    const Eigen::VectorXd B = (Eigen::VectorXd(4) << 1/6, 1/3, 1/3, 1/6).finished();
    const Eigen::VectorXd C = (Eigen::VectorXd(4) << 0, 1/2, 1/2, 0).finished();


    void Advance(Eigen::VectorXd& StateVectorD0, Eigen::VectorXd& StateVectorD1);

};
