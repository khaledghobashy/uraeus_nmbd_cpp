# Numerical Libraries
# ===================

add_library(uraeuslib 
    uraeus/numerics/euler_parameters.cpp
    uraeus/numerics/spatial_algebra.cpp
    uraeus/numerics/geometries.cpp
    uraeus/solvers/helpers.cpp
    uraeus/solvers/utilities.cpp
    uraeus/systems/configuration.cpp
)
target_include_directories(uraeuslib 
    PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>")

target_compile_options(uraeuslib PRIVATE "-fPIC")

# add the install targets
install(
    TARGETS uraeuslib 
    EXPORT uraeusTargets
    DESTINATION lib/cmake/uraeus/lib)

install(
    FILES 
        uraeus/numerics/euler_parameters.hpp
        uraeus/numerics/spatial_algebra.hpp
        uraeus/numerics/geometries.hpp
        uraeus/solvers/helpers.hpp
        uraeus/solvers/utilities.hpp
        uraeus/solvers/solvers.hpp
        uraeus/systems/configuration.hpp
    
        DESTINATION lib/cmake/uraeus/include
  )