
#include <eigen/Eigen/Eigen>
#include <functional>

template<class S>
class Explicit_RK4
{

public:
    Explicit_RK4();
    
    double h;
    double t;
    Eigen::Index n_stages;

    Eigen::VectorXd SSODE(S* solver, Eigen::VectorXd, double, double);
    void Initialize(Eigen::Index dof);
    void Advance(S* solver, Eigen::VectorXd StateVectorD0, Eigen::VectorXd StateVectorD1);

    Eigen::MatrixXd K;
    Eigen::VectorXd y;

    const Eigen::Matrix4d A = (Eigen::MatrixXd(4, 4) << 
                                0, 0,    0, 0,
                                1./2, 0, 0, 0,
                                0, 1./2, 0, 0,
                                0,  0,  1., 0).finished();
    const Eigen::Vector4d B = (Eigen::VectorXd(4) << 1./6, 1./3, 1./3, 1./6).finished();
    const Eigen::Vector4d C = (Eigen::VectorXd(4) << 0, 1./2, 1./2, 0).finished();

};


template<class S>
Explicit_RK4<S>::Explicit_RK4()
{};

template<class S>
void Explicit_RK4<S>::Initialize(Eigen::Index dof)
{
    n_stages = 4;
    K.resize(n_stages, 2*dof);
};

template<class S>
Eigen::VectorXd Explicit_RK4<S>::SSODE(S* solver, Eigen::VectorXd StateVectorD0, double t, double h)
{
    return solver->SSODE(StateVectorD0, t, h);
};

template<class S>
void Explicit_RK4<S>::Advance(S* solver, Eigen::VectorXd StateVectorD0, Eigen::VectorXd StateVectorD1)
{
    K.row(0) = StateVectorD1;

    for (int i = 1; i < n_stages; i++)
    {
        const auto& a = A.row(i).transpose();
        const auto& c = C(i);
        const auto& k = K.topRows(i);

        Eigen::VectorXd dy = h * (k.transpose() * a.head(i));
        K.row(i) = SSODE(solver, StateVectorD0 + dy, t + (c * h), h);
    }

    y = StateVectorD0 + (h * K.transpose() * B);
    t += h;

};



template<class S>
class Explicit_RK23
{

public:
    Explicit_RK23();
    
    double h;
    double t;
    Eigen::Index n_stages;

    Eigen::VectorXd SSODE(S* solver, Eigen::VectorXd, double, double);
    void Initialize(Eigen::Index dof);
    void Advance(S* solver, Eigen::VectorXd StateVectorD0, Eigen::VectorXd StateVectorD1);

    Eigen::MatrixXd K;
    Eigen::VectorXd y;

    const Eigen::Matrix3d A = (Eigen::MatrixXd(3, 3) << 
                                0, 0,    0,
                                1./2, 0, 0,
                                0, 3./4, 0).finished();
    const Eigen::Vector3d B = (Eigen::VectorXd(3) << 2./9, 1./3, 4./9).finished();
    const Eigen::Vector3d C = (Eigen::VectorXd(3) << 0, 1./2, 3./4).finished();

};


template<class S>
Explicit_RK23<S>::Explicit_RK23()
{};

template<class S>
void Explicit_RK23<S>::Initialize(Eigen::Index dof)
{
    n_stages = 3;
    K.resize(n_stages, 2*dof);
};

template<class S>
Eigen::VectorXd Explicit_RK23<S>::SSODE(S* solver, Eigen::VectorXd StateVectorD0, double t, double h)
{
    return solver->SSODE(StateVectorD0, t, h);
};

template<class S>
void Explicit_RK23<S>::Advance(S* solver, Eigen::VectorXd StateVectorD0, Eigen::VectorXd StateVectorD1)
{
    K.row(0) = StateVectorD1;

    for (int i = 1; i < n_stages; i++)
    {
        const auto& a = A.row(i).transpose();
        const auto& c = C(i);
        const auto& k = K.topRows(i);

        Eigen::VectorXd dy = h * (k.transpose() * a.head(i));
        K.row(i) = SSODE(solver, StateVectorD0 + dy, t + (c * h), h);
    }

    y = StateVectorD0 + (h * K.transpose() * B);
    t += h;

};
