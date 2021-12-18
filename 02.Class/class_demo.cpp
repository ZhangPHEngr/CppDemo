#include "class_demo.h"

#include <iostream>
#include <cstring>
/**

实例化对象的方法：
   1. 实例化对象变量： ClassA A;//无参，也可以使用{}
                    ClassA B(10);//有参，也可以使用{}
                    ClassA AA[3];//数组无参，也可以使用{}
                    ClassA BB[3](1,2,3);//数组有参，也可以使用{}
        -这种实例化方法，对象保存在栈上，程序自动析构；
        -对象变量传递要传全部数据，浪费时间空间；
        -A.成员变量、成员函数
   2. 实例化对象指针： ClassA *C = new C;//无参，也可以使用{}
                    ClassA *D = new D(10);//有参，也可以使用{}
        -这种实例化方法，对象保存在堆上，需要手动析构，如：delete[] *A
        -对象指针传递只传递地址，4/8字节，C = D 后，C和D指向同一地址；
        -C->成员变量、成员函数
对象拷贝：
    使用场景：A(B)  A = B 都会调用默认的拷贝构造函数
    浅拷贝：直接复制一份原对象内存，如果原对象有指针指向别的内存，只复制指针【表层拷贝】
    深拷贝：复制一份原对象内存，且复制一份原对象指针指向的内存【深层拷贝】
https://www.cnblogs.com/bluetzar/articles/1223313.html
 */

using namespace std;

namespace class_demo {

Person::Person() { cout << "create Person" << endl; }

Person::Person(int age) {
  this->age = age;
  cout << "create Person(param)" << endl;
}

Person::~Person() { cout << "destroy Person" << endl; }

void Person::setAge(int age) { this->age = age; }
int Person::getAge() { return this->age; }

void Person::func() { cout << "class func" << endl; }
void Person::operator+(const Person &p) { this->age += p.age; }//运算符重载


class Tom : public Person
{
public:
    Tom() {cout<<" create Tom"<<endl;};
    void func(){
        cout << "run subclass func" << endl;
    }
};

class Demo1{
private:
    int a = 0;
    char *str;
public:
    Demo1(int b, const char *cstr){
        a = b;
        str=new char[b];
        strcpy(str,cstr);
    }
    //编译器会默认生成浅拷贝构造函数，需要深拷贝就自己写
    Demo1(Demo1& d){
        a = d.a;
        //浅拷贝，只拷贝指针，没有复制内存资源
//        str = d.str;
        //深拷贝，申请并复制新的内存资源
        str=new char[a];
        if(str != 0){
            cout<<"深拷贝"<<endl;
            strcpy(str,d.str);
        }
    }
    ~Demo1(){
        delete str;
    }
    void show () const{ //如果函数中没有修改对象的值就可以使用const修饰，表示当前函数只读
        cout<<str<<endl;
    }
};

int test() {

  Person s1(20);
  // s1->setAge(10);
  cout << s1.getAge() << endl;
  s1.func();
  Person s2(30);
  s2.operator+(s1);
  cout << s2.getAge() << endl;
  return 0;
}

int testInherit(){

    //多态，父类对象指针指向子类，此时运行子类函数
    Person * p(new Tom());// 父类构造-->子类构造-->父类指针指向子类
    p->func();

}

void InitClass(){
    cout<<"------------------------实例化-----------------------"<<endl;
    //实例化对象变量
    Person person[3]{20,30,40};
    cout<<person[1].getAge()<<endl;
    //实例化对象指针
    auto *p = new Person[2]{50,60};
    cout<<p[1].getAge()<<endl;
    delete []p;
    cout<<"------------------------实例化结束-----------------------"<<endl;
}

void CopyClass(){
    cout<<"------------------------对象拷贝-----------------------"<<endl;
    Demo1 A(10, "hello");
    Demo1 B = A;
    B.show();
    cout<<"------------------------对象拷贝结束-----------------------"<<endl;
}
}  // namespace class_demo

int main(){
//    class_demo::InitClass();
    class_demo::CopyClass();
}