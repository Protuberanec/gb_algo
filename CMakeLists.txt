cmake_minimum_required(VERSION 3.19)
project(cpp_proj)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_proj main.cpp my_hash.cpp my_hash.h stack_fifo.h stack_fifo.cpp)
