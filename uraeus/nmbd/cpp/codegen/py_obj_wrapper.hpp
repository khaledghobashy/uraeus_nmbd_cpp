#pragma once

#include <iostream>
#include <Python.h>

#include "call_obj.h"

class PyObjWrapper {
public:
    // constructors and destructors mostly do reference counting
    PyObjWrapper(PyObject* o): held(o) {
        Py_XINCREF(o);
    }

    PyObjWrapper(const PyObjWrapper& rhs): PyObjWrapper(rhs.held) { // C++11 onwards only
    }

    PyObjWrapper(PyObjWrapper&& rhs): held(rhs.held) {
        rhs.held = 0;
    }

    // need no-arg constructor to stack allocate in Cython
    PyObjWrapper(): PyObjWrapper(nullptr) {
    }

    ~PyObjWrapper() {
        Py_XDECREF(held);
    }

    PyObjWrapper& operator=(const PyObjWrapper& rhs) {
        PyObjWrapper tmp = rhs;
        return (*this = std::move(tmp));
    }

    PyObjWrapper& operator=(PyObjWrapper&& rhs) {
        held = rhs.held;
        rhs.held = 0;
        return *this;
    }

    double operator()(double t) 
    {
        PyObject* PyInit_simulation_cy();
        PyObject* PyInit_call_obj();
        // nullptr check 
        if (held) 
        {
            //std::cout << "py_wrapper | Calling Func:" << std::endl;
            //std::cout << "py_wrapper | t = " << t << std::endl;
            double v = call_obj(held, t);
            //std::cout << "V = " << v << std::endl;
            return v; // note, no way of checking for errors until you return to Python
        }
/*         else
        {
            std::cout << "Calling 0:" << std::endl;
            return 0;
        };
 */    }

private:
    PyObject* held;
};
