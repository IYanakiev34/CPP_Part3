cmake_minimum_required(VERSION 3.22)
project(set7)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set(PARSER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Parser2)

add_custom_command(
        OUTPUT
            ${CMAKE_CURRENT_SOURCE_DIR}/Scanner/Scanner.h
            ${CMAKE_CURRENT_SOURCE_DIR}/Scanner/Scannerbase.h
            ${CMAKE_CURRENT_SOURCE_DIR}/Scanner/Scanner.ih
            ${CMAKE_CURRENT_SOURCE_DIR}/Scanner/lex.cc
        COMMAND flexc++ lexer
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Scanner/lexer
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Scanner
)

add_custom_command(
        OUTPUT
        ${CMAKE_CURRENT_SOURCE_DIR}/Parser2/Parser.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Parser2/Parserbase.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Parser2/Parser.ih
        ${CMAKE_CURRENT_SOURCE_DIR}/Parser2/parse.cc
        COMMAND bisonc++ grammar
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/Parser2/grammar
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Parser2
)

add_custom_target(
        LEX_GEN_FILES
        DEPENDS
            ${CMAKE_CURRENT_SOURCE_DIR}/Scanner/Scanner.h
            ${CMAKE_CURRENT_SOURCE_DIR}/Scanner/Scannerbase.h
            ${CMAKE_CURRENT_SOURCE_DIR}/Scanner/Scanner.ih
            ${CMAKE_CURRENT_SOURCE_DIR}/Scanner/lex.cc

)

add_custom_target(
        GMR_GEN_FILES
        DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/Parser2/Parser.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Parser2/Parserbase.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Parser2/Parser.ih
        ${CMAKE_CURRENT_SOURCE_DIR}/Parser2/parse.cc

)

FILE(GLOB SOURCES
        Parser2/*.cc
        Scanner/*.cc
        tests/*.cc
        *.cc
)

add_executable(set7 ${SOURCES})
add_dependencies(set7 LEX_GEN_FILES)
add_dependencies(set7 GMR_GEN_FILES)
