
# Set the minimum version of CMake that's required
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(Processing VERSION 2.1.0
                  DESCRIPTION "Framework used to define processing pipelines and modules."
                  LANGUAGES CXX
)

# Search for the Python3 library
find_package (Python3 COMPONENTS Interpreter Development)

# Search and configure ROOT
find_package(ROOT 6.16 CONFIG REQUIRED)

setup_lcio_target()

# Setup the library
setup_library(name Processing
    dependencies LCIO::Interface DARK::Event ROOT::Core ROOT::TreePlayer Python3::Python)

# Set some target properties
set_target_properties(Processing PROPERTIES 
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_executable(dark-hpstr ${PROJECT_SOURCE_DIR}/src/dark_hpstr.cxx)

target_link_libraries(dark-hpstr PUBLIC Event Processing)

# Install the fire executable
install(TARGETS dark-hpstr DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
