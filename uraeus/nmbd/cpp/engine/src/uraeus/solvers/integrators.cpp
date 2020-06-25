
#include "integrators.hpp"

template<class S>
Explicit_RK4<S>::Explicit_RK4()
{};

template<class S>
void Explicit_RK4<S>::Initialize(Eigen::Index dof)
{
    n_stages = 4;
    K.resize(5, dof);
};

/* template<class T>
Eigen::VectorXd Explicit_RK4<T>::SSODE(T* solver, Eigen::VectorXd, double, double)
{
    return solver->SSODE(Eigen::VectorXd, double, double);
}; */

template<class S>
void Explicit_RK4<S>::Advance(Eigen::VectorXd& StateVectorD0, Eigen::VectorXd& StateVectorD1)
{

    K.row(0) = StateVectorD1;

    for (int i = 1; i < n_stages; i++)
    {
        const auto& a = A.row(i);
        const auto& c = C(i);

        const auto& k = K.topRows(i);

        auto dy = h * (k.transpose() * a.head(i));
        K.row(i) = SSODE(StateVectorD0 + dy, t + (c * h), h);

    }

    y = StateVectorD0 + (h * K.topRows(n_stages).transpose() * B);

    t += h;

};

