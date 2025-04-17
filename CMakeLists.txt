cmake_minimum_required(VERSION 3.30)
project(Prog2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Weverything -Wno-c++98-compat")
set(CMAKE_CXX_COMPILER clang++)

include_directories(src)

add_executable(simple.out src/first.cpp
        src/niceheader.h
        src/functions.cpp
        src/functions.h)
