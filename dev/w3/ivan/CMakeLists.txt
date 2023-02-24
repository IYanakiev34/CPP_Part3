cmake_minimum_required(VERSION 3.12)

project(set3 VERSION 1.0.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(set3 src/main.cc)

target_compile_options(set3 PRIVATE -Wall -Werror -g -O2)

target_include_directories(set3
    PRIVATE "${CMAKE_BINARY_DIR}"
    PRIVATE "${CMAKE_SOURCE_DIR}/src/")

