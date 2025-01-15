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
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include Directories for Headers (including libraries from the libs folder)
include_directories(include)

# Generate version.h from template
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/include/version.h.in" # Input template
    "${CMAKE_CURRENT_BINARY_DIR}/version.h"           # Output file
    @ONLY
)

# Add Include Directory for Generated Files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# Add Source Files
file(GLOB_RECURSE SRC_FILES src/*.cpp include/*.h)

# Add the Executable
add_executable(citygloom ${SRC_FILES})

# Link SDL3 Library
target_link_libraries(citygloom PRIVATE SDL3::SDL3)

# Copy SDL DLL on Windows
if(WIN32)
    add_custom_command(
        TARGET citygloom POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy $<TARGET_FILE:SDL3::SDL3-shared> $<TARGET_FILE_DIR:citygloom>
        VERBATIM
    )
endif()
