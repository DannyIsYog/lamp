cmake_minimum_required(VERSION 3.10)
project(MiniAcceleratorSimulator)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include header files directory
include_directories(include)

# Gather all source files from src/
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(MiniAcceleratorSimulator ${SOURCES})
