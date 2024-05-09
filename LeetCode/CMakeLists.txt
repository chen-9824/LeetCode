cmake_minimum_required(VERSION 3.5)

project(LeetCode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include/)

add_executable(LeetCode main.cpp include/203.h)
