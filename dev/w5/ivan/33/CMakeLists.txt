cmake_minimum_required(VERSION 3.12)

project(33 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(33 main.cc)

target_compile_options(33 PRIVATE -std=c++20 -g -O2)

target_include_directories(33
    PRIVATE "${CMAKE_BINARY_DIR}"
    PRIVATE "${CMAKE_SOURCE_DIR}" 
    )