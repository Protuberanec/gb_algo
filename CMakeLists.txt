cmake_minimum_required(VERSION 3.19)
project(cpp_proj)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_proj main.cpp test_sorts.h test_sorts.cpp sorts.cpp sorts.h array_func.h arry_func.cpp)