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

# Set the root directory for libraries
set(LIBS_DIR "${CMAKE_SOURCE_DIR}/libs")

# Include Directories for Headers (including libraries from the libs folder)
include_directories(include)

# Iterate through the libraries in the libs folder
file(GLOB_RECURSE LIBS_SUBDIRS RELATIVE ${LIBS_DIR} ${LIBS_DIR}/*)

foreach(lib_dir ${LIBS_SUBDIRS})
    if(IS_DIRECTORY ${LIBS_DIR}/${lib_dir})
        # Add include directories for each library's 'include' folder
        include_directories(${LIBS_DIR}/${lib_dir}/include)

        # Add library directories for each library's 'lib' folder
        link_directories(${LIBS_DIR}/${lib_dir}/lib)

        # Link all `.lib` files from each 'lib' folder
        file(GLOB LIB_FILES ${LIBS_DIR}/${lib_dir}/lib/*.lib)
        if(LIB_FILES)
            target_link_libraries(citygloom PRIVATE ${LIB_FILES})
        endif()

        # Optional: If DLLs are present, copy them to the output directory
        file(GLOB DLL_FILES ${LIBS_DIR}/${lib_dir}/lib/*.dll)
        foreach(dll_file ${DLL_FILES})
            add_custom_command(TARGET citygloom POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy ${dll_file} $<TARGET_FILE_DIR:citygloom>)
        endforeach()
    endif()
endforeach()

# Add Source Files
file(GLOB_RECURSE SRC_FILES src/*.cpp include/*.h)

# Add the Executable
add_executable(citygloom ${SRC_FILES})

