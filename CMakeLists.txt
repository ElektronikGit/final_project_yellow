cmake_minimum_required(VERSION 3.11)
project(final_project)

set(CMAKE_CXX_STANDARD 11)

add_executable(final_project main.cpp condition_parser.h condition_parser.cpp token.h token.cpp database.h database.cpp
        node.h node.cpp test_runner.h test_runner.cpp)
