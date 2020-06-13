# distutils: language = c++
# cython: language_level=3

from libcpp.string cimport string
from libcpp.functional cimport function

cdef extern from "py_obj_wrapper.hpp":
    cdef cppclass PyObjWrapper:
        PyObjWrapper()
        PyObjWrapper(object) # define a constructor that takes a Python object
             # note - doesn't match c++ signature - that's fine!

cdef extern from "../../src/simulation.hpp":    
    cdef cppclass Simulation:
    
        Simulation() except +
        
        void Solve(double simTime, double steps)
        void ConstructConfiguration(string fileName)
        void SaveResults(string location, string name, int level)

        void set_UF_mcr_wheel_lock(PyObjWrapper func) except +
        void set_UF_mcl_wheel_lock(PyObjWrapper func) except +
        
        void set_UF_mcr_wheel_travel(PyObjWrapper func) except +
        void set_UF_mcl_wheel_travel(PyObjWrapper func) except +

        void set_UF_far_strut_Fs(PyObjWrapper func) except +
        void set_UF_far_strut_Fd(PyObjWrapper func) except +

        void set_UF_fal_strut_Fs(PyObjWrapper func) except +
        void set_UF_fal_strut_Fd(PyObjWrapper func) except +


