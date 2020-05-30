cmake_minimum_required(VERSION 3.10)

project(uraeus  VERSION 0.0.1
                DESCRIPTION "uraeus.nmbd.cxx"
                LANGUAGES CXX)

add_definitions("-std=c++17")

add_subdirectory(src)
add_subdirectory(sandbox/configuration)
add_subdirectory(sandbox/fourbar)
add_subdirectory(sandbox/double_wishbone)
add_subdirectory(sandbox/double_wishbone/cythonized_2/cpp_src)

