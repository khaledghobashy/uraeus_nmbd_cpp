# distutils: language = c++
# cython: language_level=3

from libcpp.string cimport string

cdef extern from "dwb_test.hpp":
    cdef int solve(double simTime, double steps)

