# Minimum CMake Version Required
cmake_minimum_required(VERSION 3.16)

# Add Libraries to Project
add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)
add_subdirectory(vendor/GLAD)
add_subdirectory(vendor/glm)

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
    "${CMAKE_CURRENT_BINARY_DIR}/include/version.h"    # Output file
    @ONLY
)

# Add Include Directory for Generated Files
include_directories("${CMAKE_CURRENT_BINARY_DIR}/include")

# Add Source Files
file(GLOB_RECURSE SRC_FILES src/*.cpp include/*.h)

# Add the Executable
add_executable(citygloom ${SRC_FILES})

# Link Libraries
target_link_libraries(citygloom PRIVATE SDL3::SDL3 GLAD PRIVATE glm::glm-header-only)

# Copy SDL DLL on Windows
if(WIN32)
    add_custom_command(
        TARGET citygloom POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy $<TARGET_FILE:SDL3::SDL3-shared> $<TARGET_FILE_DIR:citygloom>
        VERBATIM
    )
endif()

# Copy Shaders Folder
add_custom_target(copyShaders ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders" # Source folder
    "${CMAKE_CURRENT_BINARY_DIR}/shaders" # Destination folder
    COMMENT "Copying shaders to build directory"
)

# Ensure shaders are copied before building the project
add_dependencies(citygloom copyShaders)