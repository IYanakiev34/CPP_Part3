cmake_minimum_required(VERSION 3.12)

add_library(COUNTER 
        ctor.cc
        dtor.cc
        data.cc)

target_compile_options(COUNTER PRIVATE -Wall -Werror -std=c++20 -g -O2)
