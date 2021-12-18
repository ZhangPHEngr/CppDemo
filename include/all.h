#pragma once

//头文件
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <map>
#include <string>
#include <string.h>
#include <iostream>
#include <Eigen/Dense>

//-----------------------声明----------------------------//
//模板
namespace template_demo
{
    int test();
}
//lambda表达式
namespace lambda_demo
{
    void test();
}
//多线程
namespace pthread_demo
{
    void *threadFunc1(void *args);
    void *threadFunc2(void *args);
    void test();
}
//虚函数
namespace virtualFunc_demo
{

    class BaseClass
    {
    public:
        BaseClass(){};
        virtual ~BaseClass(){};
        virtual void testVirtual();
        void testNoVirtual();
    };
    class InheriterClass : public BaseClass
    {
    public:
        InheriterClass(){};
        ~InheriterClass(){};
        void testVirtual();
        void testNoVirtual();
        void test();
    };

}
//文件读写部分
namespace ofs_demo
{
    int test();
}
//指针部分
namespace ptr_demo
{
    int test_unique();
}
//string 部分
namespace string_demo
{
    int test();
    int devide();
    int joint();
}
//STL部分
namespace STL_demo
{
    int test_vector();
    int test_map();
}
//
namespace div_demo
{
    int test();
}

//STL vector
namespace vector_demo
{
    int test();
}
//结构体
namespace struct_demo
{

    int test();

}
//静态变量
namespace static_demo
{
    int test();
}
//sizeof
namespace sizeof_demo
{

    int test();

}
//引用
namespace refer_demo
{
    void func(int &a, int *pp);
    void test();
} 
