cmake_minimum_required(VERSION 3.12)

project(Set2 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(set2 src/main.cc)

# Add the subdirectories
add_subdirectory(src/11)


# Link libraries
target_link_libraries(set2 PRIVATE COUNTER)

# Set the compiler options
target_compile_options(set2 PRIVATE -Wall -Werror -std=c++20 -g -O2)

target_include_directories(set2
    PRIVATE "${CMAKE_BINARY_DIR}"
    PRIVATE "${CMAKE_SOURCE_DIR}/src/"
    PRIVATE "${CMAKE_SOURCE_DIR}/src/9/"
    PRIVATE "${CMAKE_SOURCE_DIR}/src/10/"
    PRIVATE "${CMAKE_SOURCE_DIR}/src/11/"
    PRIVATE "${CMAKE_SOURCE_DIR}/src/12/"
    PRIVATE "${CMAKE_SOURCE_DIR}/src/14/"
    PRIVATE "${CMAKE_SOURCE_DIR}/src/15/"
    )
