add_library(Topology Topology.cpp Topology.hpp)
target_include_directories(Topology PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(Topology PRIVATE configuration)
target_link_libraries(Topology PRIVATE spatial_algebra)
target_link_libraries(Topology PRIVATE euler_parameters)
target_link_libraries(Topology PRIVATE helpers)
target_link_libraries(Topology PRIVATE utilities)

add_library(fourbar_lib spatial_fourbar.cpp spatial_fourbar.hpp)

target_include_directories(fourbar_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(fourbar_lib PRIVATE Topology)
target_link_libraries(fourbar_lib PRIVATE configuration)
target_link_libraries(fourbar_lib PRIVATE spatial_algebra)
target_link_libraries(fourbar_lib PRIVATE euler_parameters)
target_link_libraries(fourbar_lib PRIVATE helpers)
target_link_libraries(fourbar_lib PRIVATE utilities)


add_executable(fourbar fourbar.cpp)

target_link_libraries(fourbar PRIVATE Topology)
target_link_libraries(fourbar PRIVATE fourbar_lib)
target_link_libraries(fourbar PRIVATE configuration)
target_link_libraries(fourbar PRIVATE spatial_algebra)
target_link_libraries(fourbar PRIVATE euler_parameters)
target_link_libraries(fourbar PRIVATE helpers)
target_link_libraries(fourbar PRIVATE utilities)

