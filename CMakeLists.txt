cmake_minimum_required(VERSION 3.24)
project(CBPR)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CBPR
        Commander.h
        Country.h
        main.cpp)
