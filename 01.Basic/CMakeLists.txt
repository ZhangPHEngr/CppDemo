cmake_minimum_required(VERSION 3.0.0)
project(basic VERSION 0.1.0)
#-------------------------工程结构----------------------
ADD_SUBDIRECTORY(smart_pointer)
#-------------------------工程设置----------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall")

#-------------------------工程依赖----------------------


#-------------------------可执行文件--------------------
add_executable(data_type_basic data_type_basic.cpp)
add_executable(func_virtual ../02.Class/func_virtual.cpp)
add_executable(cast cast.cpp)
add_executable(struct_demo struct.cpp)
add_executable(template_demo template.cpp)
add_executable(static_demo static.cpp)
add_executable(refer_demo refer.cpp)
add_executable(ptr_demo ptr.cpp)
add_executable(operator_demo operator.cpp)
add_executable(lambda_demo lambda.cpp)
add_executable(func_std_demo func_std.cpp)
add_executable(sizeof_demo sizeof.cpp)