
#include "helpers.hpp"

double derivative(std::function<double(double)> func, double x, int order = 1)
{
    using namespace boost::math::tools;

    if(order == 1)
    {
        return finite_difference_derivative(func, x);
    }
    else
    {
        return derivative([&func](double y) { return finite_difference_derivative(func, y); }, x, order-1);
    };

};
