cmake_minimum_required(VERSION 3.12)

project(26 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(26 main.cc)

target_compile_options(26 PRIVATE -g -O2 -Wall -Werror)

target_include_directories(26
        PRIVATE "${CMAKE_BINARY_DIR}"
        PRIVATE "${CMAKE_SOURCE_DIR}"
        )