include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(fourbar spatial_fourbar.cpp spatial_fourbar.hpp)

target_link_libraries(fourbar PRIVATE configuration)
target_link_libraries(fourbar PRIVATE spatial_algebra)
target_link_libraries(fourbar PRIVATE euler_parameters)
target_link_libraries(fourbar PRIVATE helpers)