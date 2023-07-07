cmake_minimum_required(VERSION 3.23)
project(pl_0_compiler)

set(CMAKE_CXX_STANDARD 23)

add_executable(pl_0_compiler src/main.cpp src/lexer.cpp src/parser.cpp src/sym_tab.cpp)
