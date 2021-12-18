cmake_minimum_required(VERSION 3.0.0)
project(basic VERSION 0.1.0)
#-------------------------工程结构----------------------
ADD_SUBDIRECTORY(smart_pointer)
#-------------------------工程设置----------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall")

#-------------------------工程依赖----------------------


#-------------------------可执行文件--------------------
add_executable(data_type_basic data_type_basic.cpp)
add_executable(func_virtual func_virtual.cpp)
add_executable(cast cast.cpp)
add_executable(struct_demo struct.cpp)
add_executable(template_demo template.cpp)