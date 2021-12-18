cmake_minimum_required(VERSION 3.0.0)
project(CppDemo VERSION 0.1.0)
#-------------------------项目结构-----------------------
ADD_SUBDIRECTORY(01.Basic)                  #基础语法
#ADD_SUBDIRECTORY(02.Class)                 #面向对象
#ADD_SUBDIRECTORY(03.IO)                    #文件系统
#ADD_SUBDIRECTORY(04.Exception)             #异常处理
ADD_SUBDIRECTORY(05.STL)                    #STL标准库
#ADD_SUBDIRECTORY(06.pthread)               #多线程
#ADD_SUBDIRECTORY(07.gtest)                 #单元测试
ADD_SUBDIRECTORY(08.Eigen)                  #矩阵计算库
#ADD_SUBDIRECTORY(09.protobuf)              #protobuf传输协议
#ADD_SUBDIRECTORY(10.Opencv)                #Opencv库
ADD_SUBDIRECTORY(tmp)                       #日常简单使用
