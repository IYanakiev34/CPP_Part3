cmake_minimum_required(VERSION 3.12)

project(Set2 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(set2 src/main.cc)

# Set the compiler options
target_compile_options(set2 PRIVATE -Wall -Werror -std=c++20 -g -O2)

# Add the subdirectories

# Link libraries

target_include_directories(set2
    PRIVATE "${CMAKE_BINARY_DIR}"
    PRIVATE "${CMAKE_SOURCE_DIR}/src/")
