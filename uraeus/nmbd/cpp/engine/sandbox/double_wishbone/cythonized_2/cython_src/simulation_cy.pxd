# distutils: language = c++
# cython: language_level=3

from libcpp.string cimport string
from libcpp.functional cimport function

ctypedef double (*func_t)(double x)


cdef extern from "../cpp_src/simulation.hpp":    
    cdef cppclass Simulation:
        Simulation() except +
        
        void Solve(double simTime, double steps)
        void ConstructConfiguration(string fileName)
        void SaveResults(string location, string name, int level)

        void set_UF_mcr_wheel_lock_func(func_t func)
        void set_UF_mcl_wheel_lock_func(func_t func)

        void set_UF_mcr_wheel_travel_func(func_t func)
        void set_UF_mcl_wheel_travel_func(func_t func)

