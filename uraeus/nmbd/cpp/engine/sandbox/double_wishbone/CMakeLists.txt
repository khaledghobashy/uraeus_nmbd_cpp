add_library(dwb_lib 
            new_API/double_wishbone_direct_acting.cpp 
            new_API/double_wishbone_direct_acting.hpp)

target_include_directories(dwb_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(dwb_lib PRIVATE configuration)
target_link_libraries(dwb_lib PRIVATE spatial_algebra)
target_link_libraries(dwb_lib PRIVATE euler_parameters)
target_link_libraries(dwb_lib PRIVATE helpers)
target_link_libraries(dwb_lib PRIVATE utilities)

add_executable(dwb main.cpp)

target_link_libraries(dwb PRIVATE dwb_lib)
target_link_libraries(dwb PRIVATE configuration)
target_link_libraries(dwb PRIVATE spatial_algebra)
target_link_libraries(dwb PRIVATE euler_parameters)
target_link_libraries(dwb PRIVATE helpers)
target_link_libraries(dwb PRIVATE utilities)
