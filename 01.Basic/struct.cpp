#include <iostream>
using namespace std;

/*
 * Struct：
 *      概念：
 *          定义在栈上的数据体，常用做数据容器，初始化时自动按顺序幅值
 *          现也可添加函数，继承和多态等等，但是作为类时要自定义构造函数
 *      定义：
 *          struct StructName {}
 *          struct StructName {} var_name
 *      初始化：
 *          struct StructName var_name{v1, v2, ...}
 *      使用：
 *          var_name.v1
 *      知识点：
 *          1.struct和class的不同：
 *              默认的继承访问权限：struct是public，class是private
 *              默认的属性访问权限：struct是public，class是private
 *              struct保存在栈上会自动释放，class保存在堆上需要手动释放
 *          2.内存对齐计算：https://cloud.tencent.com/developer/article/1703257
 *              每个成员的首地址是自身大小的整数倍
 *              结构体的总大小，为其成员中所含最大类型的整数倍
 */

struct AA {
  int a;
  int b;
  struct AA* ptr1;
};

struct BB {
  int c;
  int d;
  AA* ptr1;
};

struct base{
    string name;
    int age;
    base(string name, int age){
        this->name = name;
        this->age = age;
    }
    virtual void show(){
        cout<<"base class"<<endl;
    };
};

struct deived : base{
    int n_class;
    deived(string name, int age, int n_class) : base(name, age) {
        this->n_class = n_class;
    }
    void show() override {
        cout<<"deived class"<<endl;
    }
};

int main(int argc, char** argv){
    //-----------------继承-----------------//
    struct base b{"zhangsan", 20};
    b.show();
    struct deived d{"zhangsan", 20, 2};
    d.show();
    //-----------------内存对齐-----------------//
    struct AA aa{1,2, nullptr};
    struct BB bb{2,3, &aa};
    bb.ptr1->a = 10;
    cout << sizeof(bb) << endl;

    return 0;
}

