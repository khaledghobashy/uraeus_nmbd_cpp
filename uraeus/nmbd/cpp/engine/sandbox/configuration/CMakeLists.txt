include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(configuration_test configuration_test.cpp)

target_link_libraries(configuration_test ${CONAN_LIBS})
target_link_libraries(configuration_test PRIVATE configuration)