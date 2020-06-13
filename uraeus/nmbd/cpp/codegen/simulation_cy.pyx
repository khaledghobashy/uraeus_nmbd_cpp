# distutils: language = c++
# cython: language_level=3

from libcpp.string cimport string
from libcpp.functional cimport function

from simulation_cy cimport Simulation, PyObjWrapper 

import ctypes

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
    
    def set_UF_mcr_wheel_lock(self, func):
        cdef PyObjWrapper f = PyObjWrapper(func)
        self.sim.set_UF_mcr_wheel_lock(f)
        print("simylation_cy.pxy | set_UF_mcr_wheel_lock(0) = %s"%func(0.0))
    
    def set_UF_mcl_wheel_lock(self, func):
        cdef PyObjWrapper f = PyObjWrapper(func)
        self.sim.set_UF_mcl_wheel_lock(f)
        print("simylation_cy.pxy | set_UF_mcl_wheel_lock(0) = %s"%func(0.0))

    def set_UF_mcr_wheel_travel(self, func):
        cdef PyObjWrapper f = PyObjWrapper(func)
        self.sim.set_UF_mcr_wheel_travel(f)
        print("simylation_cy.pxy | set_UF_mcr_wheel_travel(0) = %s"%func(0.0))

    def set_UF_mcl_wheel_travel(self, func):
        cdef PyObjWrapper f = PyObjWrapper(func)
        self.sim.set_UF_mcl_wheel_travel(f)
        print("simylation_cy.pxy | set_UF_mcl_wheel_travel(0) = %s"%func(0.0))

    def set_UF_far_strut_Fs(self, func):
        cdef PyObjWrapper f = PyObjWrapper(func)
        self.sim.set_UF_far_strut_Fs(f)
        print("simylation_cy.pxy | set_UF_far_strut_Fs(0) = %s"%func(0.0))

    def set_UF_far_strut_Fd(self, func):
        cdef PyObjWrapper f = PyObjWrapper(func)
        self.sim.set_UF_far_strut_Fd(f)
        print("simylation_cy.pxy | set_UF_far_strut_Fd(0) = %s"%func(0.0))

    def set_UF_fal_strut_Fs(self, func):
        cdef PyObjWrapper f = PyObjWrapper(func)
        self.sim.set_UF_fal_strut_Fs(f)
        print("simylation_cy.pxy | set_UF_fal_strut_Fs(0) = %s"%func(0.0))

    def set_UF_fal_strut_Fd(self, func):
        cdef PyObjWrapper f = PyObjWrapper(func)
        self.sim.set_UF_fal_strut_Fd(f)
        print("simylation_cy.pxy | set_UF_fal_strut_Fd(0) = %s"%func(0.0))

    