cmake_minimum_required(VERSION 3.12)

project(35 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(35 main.cc)

target_compile_options(35 PRIVATE -std=c++20 -g -O2)

target_include_directories(35
    PRIVATE "${CMAKE_BINARY_DIR}"
    PRIVATE "${CMAKE_SOURCE_DIR}" 
    )