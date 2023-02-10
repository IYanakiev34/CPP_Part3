cmake_minimum_required(VERSION 3.21)
project(8)

set(CMAKE_CXX_STANDARD 20)

add_executable(8
        optinsert/verbose.cc
        optinsert/optinsert.ih
        optinsert/optinsert.h
        main.cpp)
