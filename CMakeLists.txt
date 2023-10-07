cmake_minimum_required(VERSION 3.26)
project(fs)

set(CMAKE_CXX_STANDARD 17)

add_executable(fs main.cpp
        file.cpp
        file.h
        directory.cpp
        directory.h
        )
