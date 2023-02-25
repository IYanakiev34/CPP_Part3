cmake_minimum_required(VERSION 3.22)
project(set3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

FILE(GLOB SOURCES
        I2C/*
        tests/*
        *
)

add_executable(set3 ${SOURCES})
