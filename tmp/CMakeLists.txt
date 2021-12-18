cmake_minimum_required(VERSION 3.0.0)
project(tmp VERSION 0.1.0)
#-------------------------工程设置----------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall")

#-------------------------工程依赖----------------------
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
message(${EIGEN3_INCLUDE_DIR})

#-------------------------可执行文件--------------------
add_executable(tmp_1 tmp.cpp)
