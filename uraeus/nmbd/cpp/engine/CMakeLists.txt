cmake_minimum_required(VERSION 3.10)

project(uraeus  VERSION 0.0.1
                DESCRIPTION "uraeus.nmbd.cxx"
                LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_subdirectory(src)
add_subdirectory(sandbox/double_wishbone)

set(uraeus_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/src")


include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "${uraeus_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${uraeus_VERSION_MINOR}")
include(CPack)


install(
    EXPORT uraeusTargets
    FILE uraeusTargets.cmake
    NAMESPACE uraeus::
    DESTINATION lib/cmake/uraeus
)


include(CMakePackageConfigHelpers)

# generate the config file that includes the exports
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/uraeusConfig.cmake"
    INSTALL_DESTINATION "lib/cmake/uraeus"
    PATH_VARS uraeus_INCLUDE_DIRS
  )

# generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/uraeusConfigVersion.cmake"
  VERSION "${uraeus_VERSION_MAJOR}.${uraeus_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)

# install the configuration file
install(
    FILES "uraeusConfig.cmake"
    DESTINATION lib/cmake/uraeus
)

# generate the export targets for the build tree
# needs to be after the install(TARGETS ) command
export(EXPORT uraeusTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/uraeusTargets.cmake"
)

export(PACKAGE uraeus)
