# Minimum CMake Version Required
cmake_minimum_required(VERSION 3.16)

# Add SDL3 to Project
add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)

# Project Name and Version
project(citygloom VERSION 0.0.0.1)

# VS Project Properties
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT citygloom)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQURIED True)

# Include Directories for Headers (including libraries from the libs folder)
include_directories(include)

# Add Source Files
file(GLOB_RECURSE SRC_FILES src/*.cpp include/*.h)

# Add the Executable
add_executable(citygloom ${SRC_FILES})

target_link_libraries(citygloom PRIVATE SDL3::SDL3)