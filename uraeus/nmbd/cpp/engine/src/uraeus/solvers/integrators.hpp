
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
    void Advance(S* solver, Eigen::VectorXd StateVectorD0, Eigen::VectorXd StateVectorD1);

    //Eigen::VectorXd SSODE(Eigen::VectorXd, double, double);

    Eigen::MatrixXd K;
    Eigen::VectorXd y;

    Eigen::Matrix4d A; /* (Eigen::MatrixXd(4, 4) << 
                                0, 0, 0,   0,
                                1/2, 0, 0, 0,
                                0, 1/2, 0, 0,
                                0,  0, 1,  0).finished(); */
    Eigen::Vector4d B; //= (Eigen::VectorXd(4) << 1/6, 1/3, 1/3, 1/6).finished();
    Eigen::Vector4d C; //= (Eigen::VectorXd(4) << 0, 1/2, 1/2, 0).finished();



};


template<class S>
Explicit_RK4<S>::Explicit_RK4()
{};

template<class S>
void Explicit_RK4<S>::Initialize(Eigen::Index dof)
{
    n_stages = 4;
    K.resize(5, 2*dof);

    A << 0, 0, 0,   0,
        1./2, 0, 0, 0,
        0, 1./2, 0, 0,
        0,  0, 1,  0;

    //std::cout << "A = \n" << A << "\n";
    B << 1./6, 1./3, 1./3, 1./6;
    C << 0, 1./2, 1./2, 0;
};

template<class S>
Eigen::VectorXd Explicit_RK4<S>::SSODE(S* solver, Eigen::VectorXd StateVectorD0, double t, double h)
{
    //std::cout << "Calling return solver->SSODE(StateVectorD0, t, h) \n";
    return solver->SSODE(StateVectorD0, t, h);
};

template<class S>
void Explicit_RK4<S>::Advance(S* solver, Eigen::VectorXd StateVectorD0, Eigen::VectorXd StateVectorD1)
{

    //std::cout << "StateVectorD0 = " << StateVectorD0.transpose() << "\n";
    //std::cout << "StateVectorD1 = " << StateVectorD1.transpose() << "\n";

    //std::cout << "Calling K.row(0) = StateVectorD1 \n";
    K.row(0) = StateVectorD1;

    //std::cout << "Entering Integration For-loop \n";
    for (int i = 1; i < n_stages; i++)
    {
        //std::cout << "i = " << i << "\n";
        //std::cout << "Calling const auto& a = A.row(i) \n";
        const auto& a = A.row(i).transpose();
        //std::cout << "A = \n" << A << "\n";
        //std::cout << "a = " << a << "\n";
        //std::cout << "Calling const auto& c = C(i) \n";
        const auto& c = C(i);
        //std::cout << "C = \n" << C << "\n";
        //std::cout << "c = " << c << "\n";

        //std::cout << "Calling const auto& k = K.topRows(i) \n";
        const auto& k = K.topRows(i);
        //std::cout << "k = \n" << k << "\n";

        //std::cout << "auto dy = h * (k.transpose() * a.head(i)) \n";
        //std::cout << "k.transpose =  \n" << k.transpose() << "\n";
        //std::cout << "a.head(i) =  \n" << a.head(i) << "\n";
        //std::cout << "(k.transpose() * a.head(i)) =  \n" << (k.transpose() * a.head(i)) << "\n";
        Eigen::VectorXd dy = h * (k.transpose() * a.head(i));
        //std::cout << "dy = \n" << dy << "\n";
        //std::cout << "K.row(i) = SSODE(solver, StateVectorD0 + dy, t + (c * h), h) \n";
        K.row(i) = SSODE(solver, StateVectorD0 + dy, t + (c * h), h);

    }

    //std::cout << "K.topRows(n_stages).transpose() = " << K.topRows(n_stages).transpose() << "\n";
    //std::cout << "K = " << K << "\n";

    //std::cout << "y = StateVectorD0 + (h * K.topRows(n_stages).transpose() * B) \n";
    y = StateVectorD0 + (h * K.topRows(n_stages).transpose() * B);
    //std::cout << "y = " << y.transpose() << "\n";
    //std::cout << "y.shape = (" << y.rows() << ", " << y.cols() << ") \n";

    t += h;

};

