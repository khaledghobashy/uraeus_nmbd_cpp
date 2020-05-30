from setuptools import Extension, setup

from Cython.Build import cythonize
from Cython.Distutils import build_ext

ext = Extension('test', 
                sources=["cy_dwb_test.pyx", 
                         "dwb_test.cpp", 
                         "double_wishbone_direct_acting.cpp",
                         "/home/khaledghobashy/Documents/coding_projects/opensource/uraeus_nmbd_cpp/uraeus/nmbd/cpp/engine/src/uraeus/systems/configuration.cpp",
                         "/home/khaledghobashy/Documents/coding_projects/opensource/uraeus_nmbd_cpp/uraeus/nmbd/cpp/engine/src/uraeus/numerics/geometries.cpp",
                         "/home/khaledghobashy/Documents/coding_projects/opensource/uraeus_nmbd_cpp/uraeus/nmbd/cpp/engine/src/uraeus/numerics/spatial_algebra.cpp",
                         "/home/khaledghobashy/Documents/coding_projects/opensource/uraeus_nmbd_cpp/uraeus/nmbd/cpp/engine/src/uraeus/numerics/euler_parameters.cpp",
                         "/home/khaledghobashy/Documents/coding_projects/opensource/uraeus_nmbd_cpp/uraeus/nmbd/cpp/engine/src/uraeus/solvers/utilities.cpp",
                         "/home/khaledghobashy/Documents/coding_projects/opensource/uraeus_nmbd_cpp/uraeus/nmbd/cpp/engine/src/uraeus/solvers/helpers.cpp",
                         ],
                language="c++",
                extra_compile_args=["-std=c++17"])

setup(ext_modules=cythonize(ext), 
      include_dirs=['/home/khaledghobashy/Documents/coding_projects/opensource/uraeus_nmbd_cpp/uraeus/nmbd/cpp/engine/src'],
      cmdclass = {'build_ext': build_ext},)
