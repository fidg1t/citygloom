# GLAD CMakeLists.txt
cmake_minimum_required(VERSION 3.1)
project(GLAD)

# Add GLAD source files
add_library(GLAD STATIC src/glad.c)

# Include directory for GLAD headers
target_include_directories(GLAD PUBLIC include)