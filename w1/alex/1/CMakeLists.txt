cmake_minimum_required(VERSION 3.21)
project(1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(1
        main.ih
        main.cc
        template.h
        one.cc
        two.cc)
