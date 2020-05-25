cmake_minimum_required(VERSION 3.10)

project(uraeus  VERSION 0.0.1
                DESCRIPTION "uraeus.nmbd.cxx"
                LANGUAGES CXX)

add_definitions("-std=c++17")

add_subdirectory(src)
add_subdirectory(sandbox/temps)
add_subdirectory(sandbox/jsonread)
add_subdirectory(sandbox/configuration)
add_subdirectory(sandbox/fourbar)

