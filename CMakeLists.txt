cmake_minimum_required(VERSION 3.13)
project(for_atcoder)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ftrapv -fexceptions -fsanitize=address -fno-omit-frame-pointer -DLOCAL")
#set(CMAKE_CXX_FLAGS_DEBUG "-g3 -ggdb -O0 -DLOCAL")

include_directories(include)

add_executable(for_atcoder problems/AISing2019/C.cpp)
