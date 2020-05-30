# distutils: language = c++
# cython: language_level=3

from libcpp.string cimport string
from libcpp.functional cimport function

from simulation_cy cimport Simulation

import ctypes
# define the function type for ctypes
FUNC = ctypes.CFUNCTYPE(ctypes.c_double, ctypes.c_double)
ctypedef double(*func_t)(double)

cdef class PySimulation:

    cdef Simulation* sim

    def __cinit__(self):
        self.sim = new Simulation()

    def solve(self, double simTime, double steps):
        self.sim.Solve(simTime, steps)
        print("Cython Solver End!")

    def save_results(self, string location, string name, int level):
        print("calling cython 'save_results!'")
        self.sim.SaveResults(location, name, level)
    
    def construct_configuration(self, string fileName):
        self.sim.ConstructConfiguration(fileName)
    
    def set_UF_mcr_wheel_lock_func(self, func):
        FUNC = ctypes.CFUNCTYPE(ctypes.c_double, ctypes.c_double)
        f = FUNC(func) # create the ctypes function pointer
        this_func = (<func_t*><size_t>ctypes.addressof(f))[0]
        self.sim.set_UF_mcr_wheel_lock_func(this_func)
        v = this_func(0)
        print("UF_mcr_wheel_lock(0) = %s"%v)


    def set_UF_mcl_wheel_lock_func(self, func):
        FUNC = ctypes.CFUNCTYPE(ctypes.c_double, ctypes.c_double)
        f = FUNC(func) # create the ctypes function pointer
        this_func = (<func_t*><size_t>ctypes.addressof(f))[0]
        self.sim.set_UF_mcl_wheel_lock_func(this_func)
        v = this_func(0)
        print("UF_mcl_wheel_lock(0) = %s"%v)


    def set_UF_mcr_wheel_travel_func(self, func):
        FUNC = ctypes.CFUNCTYPE(ctypes.c_double, ctypes.c_double)
        f = FUNC(func) # create the ctypes function pointer
        this_func = (<func_t*><size_t>ctypes.addressof(f))[0]
        self.sim.set_UF_mcr_wheel_travel_func(this_func)
        v = this_func(0)
        print("UF_mclr_wheel_travel(0) = %s"%v)


    def set_UF_mcl_wheel_travel_func(self, func):
        FUNC = ctypes.CFUNCTYPE(ctypes.c_double, ctypes.c_double)
        f = FUNC(func) # create the ctypes function pointer
        this_func = (<func_t*><size_t>ctypes.addressof(f))[0]
        #cdef func_t this_func
        #this_func = (<func_t*><size_t>ctypes.addressof(func))[0]
        self.sim.set_UF_mcl_wheel_travel_func(this_func)
        v = this_func(0)
        print("UF_mcl_wheel_travel(0) = %s"%v)

    
