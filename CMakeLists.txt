cmake_minimum_required(VERSION 3.14)

# Specify project name (physics-simulation) and language used (C++).
project(physics-simulation CXX)

# Specify C++ Standard (updated to C++14 as required by GoogleTest).
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the directory where the header files for physics-simulation are located.
include_directories(${CMAKE_SOURCE_DIR}/include)

# Compile each .cxx file from the src/ directory into an executable named 'app'.
add_executable(app src/main.cxx src/particle.cxx src/simulation.cxx)

# Set the output directory for binary files to ./bin/
set_target_properties(app PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing with CTest.
enable_testing()

# Compile source code and test files into an executable named 'unit'.
add_executable(unit test/particle-unit-tests.cxx test/simulation-unit-tests.cxx src/particle.cxx src/simulation.cxx)

# Link GoogleTest to the test executable.
target_link_libraries(unit gtest_main gmock_main)

# Include GoogleTest in testing
include(GoogleTest)
gtest_discover_tests(unit)