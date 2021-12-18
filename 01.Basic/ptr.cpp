#include<memory>
#include"all.h"
/**
unique_prt:
1. 特点：
    独享它所指向的对象（不支持拷贝构造，=运算符）；
    离开作用域，自动隐式注销，不会引起内存泄漏；
    相比shared_ptr内存消耗更小；

2. 函数：
初始化：
std::unique_ptr<int>p1; //空构造
std::unique_ptr<int>p1(new int(10)); //默认构造
std::unique_ptr<int, Structor>p1(new int(10), Structor()); //自定义删除器,仿函数

struct Structor{
    void operator()(int*p){
        delete p;
    }
}

内部函数：
get()获得内部对象的指针
reset()销毁内部对象并接受新的对象的所有权
release()放弃内部对象的所有权
move(unique_ptr)让unique_ptr交出裸指针所有权并置空自身

 */


using namespace std;
namespace ptr_demo {

//自定义删除器模板
template <typename T>
struct Deleter1{
    void operator()(T* p){
        cout<<*p<<endl;
        cout<<"Deleter: dele ptr"<<endl;
        delete p;
    }
};

struct Deleter2{
    void operator()(int* p){
        cout<<*p<<endl;
        cout<<"Deleter1: dele ptr"<<endl;
        delete p;
    }
};

template<typename T>
using Safe_ptr = unique_ptr<T, Deleter1<T>>;//等同于typedef

int test_unique(){
    //测试1
    unique_ptr<int>p1;
    int* array1 = new int(1);
    p1.reset(array1);
    //测试2
    int* array2 = new int(2);
    Safe_ptr<int> p2(array2,Deleter1<int>());
    //测试3
    int* array3 = new int(3);
    unique_ptr<int,Deleter2> p3(array3,Deleter2());
}

}
