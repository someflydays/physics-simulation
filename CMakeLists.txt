cmake_minimum_required(VERSION 3.10)

# Specify project name ('physics-simulation') and language used (C++).
project(physics-simulation CXX)

# Compile each .cxx file from the src/ directory into an executable named 'app'.
add_executable(app src/main.cxx src/particle.cxx src/simulation.cxx)

# Include the directory where the header files are located.
include_directories(app PRIVATE include/)

# Set the output directory for binary files to ./bin/
set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)