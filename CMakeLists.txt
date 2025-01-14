# Minimum CMake Version Required
cmake_minimum_required(VERSION 3.16)

# Project Name and Version
project(citygloom VERSION 0.0.0.1)

# VS Project Properties
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT citygloom)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQURIED True)

# Include Directories for Headers
include_directories(include)

# Set the root directory for libraries
set(LIBS_DIR "${CMAKE_SOURCE_DIR}/libs")

# Find all subdirectories in the libs folder (each library will be in its own folder)
file(GLOB_RECURSE LIBS_SUBDIRS RELATIVE ${LIBS_DIR} ${LIBS_DIR}/*)

# Iterate through the libraries in the libs folder
foreach(lib_dir ${LIBS_SUBDIRS})
    if(IS_DIRECTORY ${LIBS_DIR}/${lib_dir})
        # Add include directories for each library's 'include' folder
        include_directories(${LIBS_DIR}/${lib_dir}/include)
        
        # Add library directories for each library's 'lib' folder
        link_directories(${LIBS_DIR}/${lib_dir}/lib)
        
        # Optionally, you can get all the `.lib` files in the `lib` folder and link them
        file(GLOB LIB_FILES ${LIBS_DIR}/${lib_dir}/lib/*.lib)
        if(LIB_FILES)
            target_link_libraries(citygloom PRIVATE ${LIB_FILES})
        endif()
    endif()
endforeach()

# Add Source Files
file(GLOB_RECURSE SRC_FILES src/*.cpp include/*.h)

# Add the Executable
add_executable(citygloom ${SRC_FILES})

# Copy DLLs to the output directory for dynamic libraries
foreach(lib_dir ${LIBS_SUBDIRS})
    if(IS_DIRECTORY ${LIBS_DIR}/${lib_dir})
        file(GLOB DLL_FILES ${LIBS_DIR}/${lib_dir}/lib/*.dll)
        foreach(dll_file ${DLL_FILES})
            add_custom_command(TARGET citygloom POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy ${dll_file} $<TARGET_FILE_DIR:citygloom>)
        endforeach()
    endif()
endforeach()
