# Set the minimum version required for CMake (v3.10)
cmake_minimum_required(VERSION 3.10)

# Specify project name (PhysicsSimulation) and language used (C++)
project(PhysicsSimulation CXX)

# Define the executable and its source files
add_executable(app src/main.cxx)

# Set the output directory for binary files to ./bin/
set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)