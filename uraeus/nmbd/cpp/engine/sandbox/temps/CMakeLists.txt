
# Adding something we can run - Output name matches target name
add_executable(temp2 temps.cpp)

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
target_link_libraries(temp2 PRIVATE euler_parameters)
target_link_libraries(temp2 PRIVATE geometries)
target_link_libraries(temp2 PRIVATE helpers)
target_link_libraries(temp2 PRIVATE spatial_algebra)
target_link_libraries(temp2 PRIVATE utilities)
