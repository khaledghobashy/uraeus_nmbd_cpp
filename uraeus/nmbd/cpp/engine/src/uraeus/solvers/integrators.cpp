
#include "integrators.hpp"

Explicit_RK4::Explicit_RK4(Eigen::Index dof)
{
    n_stages = 4;
    K(5, dof);
};


void Explicit_RK4::Advance(Eigen::VectorXd& StateVectorD0, Eigen::VectorXd& StateVectorD1)
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

