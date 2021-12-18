cmake_minimum_required(VERSION 3.0.0)
project(eigendemo VERSION 0.1.0)
#-------------------------工程设置----------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall")

#-------------------------工程依赖----------------------
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
message(${EIGEN3_INCLUDE_DIR})

#-------------------------可执行文件--------------------
#SET(EXECUTABLE_OUTPUT_PATH ..)#设置可执行文件输出路径
add_executable(my_share_ptr share_ptr.cpp)
add_executable(my_unique_ptr unique_ptr.cpp)