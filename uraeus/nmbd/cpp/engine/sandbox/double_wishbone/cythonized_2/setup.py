from setuptools import Extension, setup

from Cython.Build import cythonize
from Cython.Distutils import build_ext

import os

object_files = ["objects/%s"%i for i in os.listdir("objects")]

ext = Extension('test', 
                sources=["cython_src/simulation_cy.pyx", 
                         "cpp_src/simulation.cpp", 
                         ],
                language="c++",
                extra_compile_args=["-std=c++17"],
                extra_objects=object_files)

setup(ext_modules=cythonize(ext), 
      include_dirs=['/home/khaledghobashy/Documents/coding_projects/opensource/uraeus_nmbd_cpp/uraeus/nmbd/cpp/engine/src'],
      cmdclass = {'build_ext': build_ext},)
