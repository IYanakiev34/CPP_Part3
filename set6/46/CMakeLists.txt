cmake_minimum_required(VERSION 3.22)
project(set6)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_custom_command(
        OUTPUT
            ${CMAKE_CURRENT_SOURCE_DIR}/lexer/Scanner.h
            ${CMAKE_CURRENT_SOURCE_DIR}/lexer/Scannerbase.h
            ${CMAKE_CURRENT_SOURCE_DIR}/lexer/Scanner.ih
            ${CMAKE_CURRENT_SOURCE_DIR}/lexer/lex.cc
        COMMAND flexc++ lexer
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/lexer/lexer
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Scanner
)

add_custom_target(
        LEX_GEN_FILES
        DEPENDS
            ${CMAKE_CURRENT_SOURCE_DIR}/lexer/Scanner.h
            ${CMAKE_CURRENT_SOURCE_DIR}/lexer/Scannerbase.h
            ${CMAKE_CURRENT_SOURCE_DIR}/lexer/Scanner.ih
            ${CMAKE_CURRENT_SOURCE_DIR}/lexer/lex.cc

)

FILE(GLOB SOURCES
        Scanner/lex.cc
        tests/*.cc
        *.cc
)

add_executable(set6 ${SOURCES})
add_dependencies(set6 LEX_GEN_FILES)
