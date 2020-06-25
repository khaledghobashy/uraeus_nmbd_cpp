
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

    //std::function<Eigen::VectorXd(Eigen::VectorXd, double, double)> SSODE;
    //std::function<Eigen::VectorXd(Eigen::VectorXd, double, double)> SSODE;

    Eigen::VectorXd SSODE(S* solver, Eigen::VectorXd, double, double);
    void Initialize(Eigen::Index dof);
    void Advance(S* solver, Eigen::VectorXd& StateVectorD0, Eigen::VectorXd& StateVectorD1);

    //Eigen::VectorXd SSODE(Eigen::VectorXd, double, double);

    Eigen::MatrixXd K;
    Eigen::VectorXd y;

    const Eigen::MatrixXd A = (Eigen::MatrixXd(4, 4) << 
                                0, 0, 0,   0,
                                1/2, 0, 0, 0,
                                0, 1/2, 0, 0,
                                0,  0, 1,  0).finished();
    const Eigen::VectorXd B = (Eigen::VectorXd(4) << 1/6, 1/3, 1/3, 1/6).finished();
    const Eigen::VectorXd C = (Eigen::VectorXd(4) << 0, 1/2, 1/2, 0).finished();



};


template<class S>
Explicit_RK4<S>::Explicit_RK4()
{};

template<class S>
void Explicit_RK4<S>::Initialize(Eigen::Index dof)
{
    n_stages = 4;
    K.resize(5, dof);
};

template<class S>
Eigen::VectorXd Explicit_RK4<S>::SSODE(S* solver, Eigen::VectorXd StateVectorD0, double t, double h)
{
    return solver->SSODE(StateVectorD0, t, h);
};

template<class S>
void Explicit_RK4<S>::Advance(S* solver, Eigen::VectorXd& StateVectorD0, Eigen::VectorXd& StateVectorD1)
{

    K.row(0) = StateVectorD1;

    for (int i = 1; i < n_stages; i++)
    {
        const auto& a = A.row(i);
        const auto& c = C(i);

        const auto& k = K.topRows(i);

        auto dy = h * (k.transpose() * a.head(i));
        K.row(i) = SSODE(solver, StateVectorD0 + dy, t + (c * h), h);

    }

    y = StateVectorD0 + (h * K.topRows(n_stages).transpose() * B);

    t += h;

};

