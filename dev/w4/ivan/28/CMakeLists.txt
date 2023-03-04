cmake_minimum_required(VERSION 3.12)

project(28 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(28 main.cc)

target_compile_options(28 PRIVATE -g -O2)

target_include_directories(28
    PRIVATE "${CMAKE_BINARY_DIR}"
    PRIVATE "${CMAKE_SOURCE_DIR}"    
)