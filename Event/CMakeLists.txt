
# Set the minimum version of CMake that's required
cmake_minimum_required(VERSION 3.12)

# Set the project name
project(Event VERSION 2.1.0
              DESCRIPTION "Event model module."
              LANGUAGES CXX
)

# Search and configure ROOT
find_package(ROOT 6.16 CONFIG REQUIRED)

# Setup the LCIO target
setup_lcio_target()

# Setup the library
setup_library(name Event
    dependencies ROOT::Core LCIO::Interface)

