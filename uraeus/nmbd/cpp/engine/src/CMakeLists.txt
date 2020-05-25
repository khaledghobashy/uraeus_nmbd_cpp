include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(euler_parameters 
            uraeus/euler_parameters.cpp 
            uraeus/euler_parameters.hpp)
target_include_directories(euler_parameters PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(spatial_algebra 
            uraeus/spatial_algebra.cpp 
            uraeus/spatial_algebra.hpp)
target_include_directories(spatial_algebra PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")


add_library(geometries 
            uraeus/geometries.cpp 
            uraeus/geometries.hpp)
target_include_directories(geometries PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(geometries PRIVATE euler_parameters)
target_link_libraries(geometries PRIVATE spatial_algebra)


add_library(helpers 
            uraeus/helpers.cpp 
            uraeus/helpers.hpp)
target_include_directories(helpers PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")


add_library(utilities 
            uraeus/utilities.cpp 
            uraeus/utilities.hpp)
target_include_directories(utilities PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(config_parser 
uraeus/systems/config_parser.cpp 
uraeus/systems/config_parser.hpp)
target_include_directories(config_parser PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(config_parser PRIVATE spatial_algebra)
target_link_libraries(config_parser PRIVATE geometries)
target_link_libraries(config_parser ${CONAN_LIBS})


add_library(configuration 
            uraeus/systems/configuration.cpp 
            uraeus/systems/configuration.hpp)
target_include_directories(configuration PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(configuration PRIVATE geometries)


