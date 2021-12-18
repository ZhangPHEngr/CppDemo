cmake_minimum_required(VERSION 3.0.0)
project(gtest_demo VERSION 0.1.0)
#-------------------------工程设置----------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall")

#-------------------------可执行文件--------------------
#add_executable(${PROJECT_NAME} gtest_demo.cpp)#这里不能生成，否则会和测试程序冲突
#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})#设置可执行文件输出路径
ADD_LIBRARY(${PROJECT_NAME}lib STATIC gtest_demo.cpp)

#-------------------------gtest相关--------------------
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)#gtest依赖pthread
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_gtest test_gtest_demo.cpp)

target_link_libraries(test_gtest ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_gtest ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(test_gtest ${PROJECT_NAME}lib)

add_test(Test test_gtest)
enable_testing()# 开启测试