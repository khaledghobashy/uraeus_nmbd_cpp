
#include <functional>
#include "boost/math/tools/numerical_differentiation.hpp"

double derivative(std::function<double(double)> func, double x, int order);
