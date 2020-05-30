include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(sim_lib simulation.cpp simulation.hpp)
target_include_directories(sim_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(sim_lib PRIVATE dwb_lib)
target_link_libraries(sim_lib PRIVATE configuration)
target_link_libraries(sim_lib PRIVATE spatial_algebra)
target_link_libraries(sim_lib PRIVATE euler_parameters)
target_link_libraries(sim_lib PRIVATE helpers)


add_executable(dwb_2 main.cpp)

target_link_libraries(dwb_2 PRIVATE dwb_lib)
target_link_libraries(dwb_2 PRIVATE configuration)
target_link_libraries(dwb_2 PRIVATE spatial_algebra)
target_link_libraries(dwb_2 PRIVATE euler_parameters)
target_link_libraries(dwb_2 PRIVATE helpers)
target_link_libraries(dwb_2 PRIVATE sim_lib)
