include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(configuration_test configuration_test.cpp)

#target_include_directories(configuration_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(configuration_test ${CONAN_LIBS})
target_link_libraries(configuration_test PRIVATE configuration)
target_link_libraries(configuration_test PRIVATE spatial_algebra)