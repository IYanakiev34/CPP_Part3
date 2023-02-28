cmake_minimum_required(VERSION 3.22)
project(set2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

FILE(GLOB SOURCES
        tests/*
        *
)

add_executable(set2 ${SOURCES})
