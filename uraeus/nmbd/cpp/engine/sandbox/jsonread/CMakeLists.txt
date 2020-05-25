
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(jsonread jsonread.cpp)
target_link_libraries(jsonread ${CONAN_LIBS})
target_link_libraries(jsonread PRIVATE config_parser)
target_link_libraries(jsonread PRIVATE spatial_algebra)

