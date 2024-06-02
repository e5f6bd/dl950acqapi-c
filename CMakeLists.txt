cmake_minimum_required(VERSION 3.10)

# Set the project name and specify it is a shared library (DLL)
project(dl950acqapi-c LANGUAGES CXX)

# Define the variable for the path to the dependency files
set(DL950ACQAPI_PATH "" CACHE PATH "Path to DL950ACQAPI dependencies")

# Check if the path is provided
if(NOT DL950ACQAPI_PATH)
    message(FATAL_ERROR "Please provide the path to the DL950ACQAPI dependencies using the -DDL950ACQAPI_PATH=<path> option.")
endif()

# Include directories
include_directories(${DL950ACQAPI_PATH})

# Generate `*.lib` file as well
# https://stackoverflow.com/a/76338336
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Add the library
add_library(dl950acqapi-c SHARED dl950acqapi-c.cpp)

# Link the library
target_link_libraries(dl950acqapi-c ${DL950ACQAPI_PATH}/DL950ACQAPI64.lib)

# Specify the output directory for the compiled DLL and LIB
set_target_properties(dl950acqapi-c PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# # Set the target to build for a 64-bit system
# if(CMAKE_SIZEOF_VOID_P EQUAL 8)
#     set_target_properties(dl950acqapi-c PROPERTIES COMPILE_FLAGS "-m64" LINK_FLAGS "-m64")
# endif()
