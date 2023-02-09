cmake_minimum_required(VERSION 3.12)

project(FirstHomework VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(set1
    src/main.cc
    src/1/source1.cc
    src/5/ctor.cc
    )

add_executable(ex4 src/4/main.cc)

target_compile_options(set1 PUBLIC -std=c++20 -g -O2 -Wall -Werror)

target_include_directories(set1
    PRIVATE "${PROJECT_SOURCE_DIR}/src"
    PRIVATE "${PROJECT_BINARY_DIR}"
    )

