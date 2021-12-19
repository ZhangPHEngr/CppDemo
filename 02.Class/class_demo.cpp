#include "class_demo.h"

#include <iostream>
#include <cstring>
/**

ʵ��������ķ�����
   1. ʵ������������� ClassA A;//�޲Σ�Ҳ����ʹ��{}
                    ClassA B(10);//�вΣ�Ҳ����ʹ��{}
                    ClassA AA[3];//�����޲Σ�Ҳ����ʹ��{}
                    ClassA BB[3](1,2,3);//�����вΣ�Ҳ����ʹ��{}
        -����ʵ�������������󱣴���ջ�ϣ������Զ�������
        -�����������Ҫ��ȫ�����ݣ��˷�ʱ��ռ䣻
        -A.��Ա��������Ա����
   2. ʵ��������ָ�룺 ClassA *C = new C;//�޲Σ�Ҳ����ʹ��{}
                    ClassA *D = new D(10);//�вΣ�Ҳ����ʹ��{}
        -����ʵ�������������󱣴��ڶ��ϣ���Ҫ�ֶ��������磺delete[] *A
        -����ָ�봫��ֻ���ݵ�ַ��4/8�ֽڣ�C = D ��C��Dָ��ͬһ��ַ��
        -C->��Ա��������Ա����
���󿽱���
    ʹ�ó�����A(B)  A = B �������Ĭ�ϵĿ������캯��
    ǳ������ֱ�Ӹ���һ��ԭ�����ڴ棬���ԭ������ָ��ָ�����ڴ棬ֻ����ָ�롾��㿽����
    ���������һ��ԭ�����ڴ棬�Ҹ���һ��ԭ����ָ��ָ����ڴ桾��㿽����
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
void Person::operator+(const Person &p) { this->age += p.age; }//���������


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
    //��������Ĭ������ǳ�������캯������Ҫ������Լ�д
    Demo1(Demo1& d){
        a = d.a;
        //ǳ������ֻ����ָ�룬û�и����ڴ���Դ
//        str = d.str;
        //��������벢�����µ��ڴ���Դ
        str=new char[a];
        if(str != 0){
            cout<<"���"<<endl;
            strcpy(str,d.str);
        }
    }
    ~Demo1(){
        delete str;
    }
    void show () const{ //���������û���޸Ķ����ֵ�Ϳ���ʹ��const���Σ���ʾ��ǰ����ֻ��
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

    //��̬���������ָ��ָ�����࣬��ʱ�������ຯ��
    Person * p(new Tom());// ���๹��-->���๹��-->����ָ��ָ������
    p->func();

}

void InitClass(){
    cout<<"------------------------ʵ����-----------------------"<<endl;
    //ʵ�����������
    Person person[3]{20,30,40};
    cout<<person[1].getAge()<<endl;
    //ʵ��������ָ��
    auto *p = new Person[2]{50,60};
    cout<<p[1].getAge()<<endl;
    delete []p;
    cout<<"------------------------ʵ��������-----------------------"<<endl;
}

void CopyClass(){
    cout<<"------------------------���󿽱�-----------------------"<<endl;
    Demo1 A(10, "hello");
    Demo1 B = A;
    B.show();
    cout<<"------------------------���󿽱�����-----------------------"<<endl;
}
}  // namespace class_demo

int main(){
//    class_demo::InitClass();
    class_demo::CopyClass();
}