include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Numerical Libraries
# ===================
add_library(euler_parameters 
            uraeus/numerics/euler_parameters.cpp 
            uraeus/numerics/euler_parameters.hpp)
target_include_directories(euler_parameters PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(spatial_algebra 
            uraeus/numerics/spatial_algebra.cpp 
            uraeus/numerics/spatial_algebra.hpp)
target_include_directories(spatial_algebra PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")


add_library(geometries 
            uraeus/numerics/geometries.cpp 
            uraeus/numerics/geometries.hpp)
target_include_directories(geometries PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(geometries PRIVATE euler_parameters)
target_link_libraries(geometries PRIVATE spatial_algebra)

# Solver Libraries
# ================
add_library(helpers 
            uraeus/solvers/helpers.cpp 
            uraeus/solvers/helpers.hpp)
target_include_directories(helpers PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(utilities 
            uraeus/solvers/utilities.cpp 
            uraeus/solvers/utilities.hpp)
target_include_directories(utilities PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

# Systems Libraries
# =================
add_library(configuration 
            uraeus/systems/configuration.cpp 
            uraeus/systems/configuration.hpp)
target_include_directories(configuration PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(configuration PRIVATE geometries)
