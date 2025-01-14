# Minimum CMake Version Required
cmake_minimum_required(VERSION 3.16)

# Project Name and Version
project(citygloom VERSION 0.0.0.1)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQURIED True)

# Include Directories for Headers
include_directories(include)

# Add Source Files
file(GLOB_RECUR SRC_FILES src/*.cpp include/*.h)

# Add the Executable
add_exeutable(citygloom ${SRC_FILES})