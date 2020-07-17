
# Set the minimum version of CMake that's required 
cmake_minimum_required(VERSION 3.12)

project(dark_hpstr VERSION 0.1
                   DESCRIPTION "Analysis framework for the Heavy Photon Search experiment." 
                   LANGUAGES CXX
)

# If an install location hasn't been set via CMAKE_INSTALL_PREFIX, set it to 
# a reasonable default ($PWD/install).  
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install CACHE PATH "" FORCE)
    message(STATUS "Install directory set to ${CMAKE_INSTALL_PREFIX}")
endif()

# Set the default release type to "Release". If a release type is specified 
# at the command line, it's respected.
set(default_build_type "Release")
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
endif()

# Load additional macro commands 
list(APPEND CMAKE_MODULE_PATH ${dark_hpstr_SOURCE_DIR}/cmake/)
message(STATUS ${CMAKE_MODULE_PATH})

# Load the BuildMacros module. If loaded correctly, the variable 
# 'build_macros_found' will be set to the path of the module.  Otherwise, it
# is set to NOTFOUND.
include(BuildMacros RESULT_VARIABLE build_macros_found)

# Set the default release type to "Release". If a release type is specified 
# at the command line, it's respected.
set(default_build_type "Release")
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
endif()

add_subdirectory(Event)
add_subdirectory(Processing)
