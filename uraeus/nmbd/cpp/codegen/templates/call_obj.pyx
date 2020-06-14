# distutils: language = c++
# cython: language_level=3
cdef public double call_obj(obj, double t):
    return obj(t)
