cmake_minimum_required(VERSION 3.27)
project(Project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(test-unit)

add_executable(Project_1 main.cpp
        AVL.cpp
        AVL.h
        test-unit/catch.hpp
        test-unit/test.cpp
)
