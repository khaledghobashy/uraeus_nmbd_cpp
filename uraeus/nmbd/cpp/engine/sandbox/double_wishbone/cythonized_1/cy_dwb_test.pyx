# distutils: language = c++
# cython: language_level=3

from cy_dwb_test cimport solve

cpdef int pysolve(double simTime, double steps):
    return solve(simTime, steps)