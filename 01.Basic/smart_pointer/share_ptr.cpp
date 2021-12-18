//
// Created by zhangph on 12/9/21.
//
/*
 share_ptr:
    1.概念：
        是一个保存在栈上的智能指针对象，里面有个计数器，且托管着一个所指向对象的指针；
        当计数器为0时，析构所指向对象；
    2.使用方法：
        初始化：
            std::shared_ptr<T> p1(new T());//智能指针创建
            std::shared_ptr<T> p2 = std::make_shared<T>();//智能指针创建
            std::shared_ptr<Person> p3 = p1;//智能指针赋值
            p1.reset(new T(3));//智能指针赋值
            // 首先生成新对象，然后引用计数减1，引用计数为0，最后将新对象的指针交给智能指针
        获取计数值：
            p1.use_count()
        获取原始指针：
            T *pInt = p1.get();
    3.注意事项：
        不能将一个原始指针直接赋值给一个智能指针，原因是一个是类，一个是指针；
        智能指针可以指定删除器，当智能指针的引用计数为0时，自动调用指定的删除器来释放内存。std::shared_ptr可以指定删除器的一个原因是其默认删除器不支持数组对象;
        不要用一个原始指针初始化多个shared_ptr，原因在于，会造成二次销毁;
        禁止在类方法中返回this指针，这样做可能也会造成二次析构,
            可以通过shared_from_this()返回shard_ptr(仅调用这个函数并不会引用计数+1，外面赋值给share_ptr时会自动引用+1)

 */
#include <memory>
#include <iostream>

using namespace std;

// 一般情况
class Person{
public:
    int m_value;
public:
    Person(int value):m_value{value}{
        cout<<"Person Init: "<<m_value<<endl;
    }
    ~Person(){
        cout<<"Person Destroy: "<<m_value<<endl;
    }
};

//使用enable_share_ptr
class Person2: public std::enable_shared_from_this<Person2>{
public:
    Person2(){
        cout<<"Person2 Init"<<endl;
    }
    ~Person2(){
        cout<<"Person2 Destroy"<<endl;
    }
    shared_ptr<Person2> get_ptr(){
        return shared_from_this();
    }
};

int main(int argc, char** argv){

    std::shared_ptr<Person> p1(new Person(1));
    std::shared_ptr<Person> p2 = std::make_shared<Person>(2);

    std::shared_ptr<Person> p3 = p1;
    cout<<p1.use_count()<<endl;
    cout<<p2.use_count()<<endl;
    cout<<p3.use_count()<<endl;


    std::shared_ptr<Person2> person2_1 = std::make_shared<Person2>();
    cout<<person2_1.use_count()<<endl;
    std::shared_ptr<Person2> person2_2 = person2_1->get_ptr();
    cout<<person2_2.use_count()<<endl;

    return 0;
}

