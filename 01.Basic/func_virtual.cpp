#include <iostream>
/**
 *虚函数：用于使用函数多态功能
 *  使用virtual声明的虚函数，在多态使用时会根据指针内容选择父、子函数执行
 *  未使用virtual声明的虚函数，在多态使用时会根据指针类型选择函数执行
 *
 */

class BaseClass
{
public:
    BaseClass(){};
    virtual ~BaseClass(){};
    virtual void testVirtual(){
        std::cout << "Virtual, Class: Base, Line: " << __LINE__ << std::endl;
    }
    void testNoVirtual(){
        std::cout << "No Virtual, Class: Base, Line: " << __LINE__ << std::endl;
    }
};

class InheriterClass : public BaseClass
{
public:
    InheriterClass(){};
    ~InheriterClass(){};
    void testVirtual(){
        std::cout << "Virtual, Class: Inheriter, Line: " << __LINE__ << std::endl;
    }
    void testNoVirtual(){
        std::cout << "No Virtual, Class: Inheriter, Line: " << __LINE__ << std::endl;
    }
};


int main(int argc, char** argv){
    BaseClass *ptr1 = new BaseClass();
    BaseClass *ptr2 = new InheriterClass();

    //未使用virtual声明的虚函数，在多态使用时会根据 指针类型 选择函数执行
    ptr1->testNoVirtual();//调用基类函数
    ptr2->testNoVirtual();//调用基类函数

    //使用virtual声明的虚函数，在多态使用时会根据 指针内容 选择父、子函数执行
    ptr1->testVirtual();//调用基类函数
    ptr2->testVirtual();//调用派生类函数
    return 0;
}



