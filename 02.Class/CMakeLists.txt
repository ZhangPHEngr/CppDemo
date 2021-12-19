cmake_minimum_required(VERSION 3.0.0)
project(basic VERSION 0.1.0)
#-------------------------工程结构----------------------

#-------------------------工程设置----------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall")

#-------------------------工程依赖----------------------

include_directories(.)

#-------------------------可执行文件--------------------
add_executable(class_demo class_demo.cpp)
add_executable(func_virtual_demo func_virtual.cpp)
