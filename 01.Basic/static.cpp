#include <iostream>

using namespace std;

/*
 * static关键字：
 *      作用：
 *          将所修饰变量转移至静态区，这样就可以既增加变量生命周期，又只被所属上层使用
 *          由于static变量和方法会优先加载进静态区，所以静态方法只能调用静态方法或变量
 *      static变量：
 *          修饰局部变量：放在函数中，函数可多次调用，直到程序结束
 *          全局变量：放在文件中，对外部文件不可访问，直到程序结束
 *          类变量：该变量属于类，可以 类名.属性名 直接访问，不用new对象
 *      static方法：
 *          一般方法：放在文件中，对外部文件不可访问，直到程序结束
 *          类方法：该方法属于类，可以 类名.方法名 直接访问，不用new对象
 *
 *      参考：
 *          https://www.runoob.com/w3cnote/cpp-static-usage.html
 */

//只能在本函数中被访问
static int a = 10;

//只能在本函数中被访问
static void static_func(){
    cout<<"static_func a:"<< a<<endl;
}

void func() {
    int b = 10;
    static int a = 0;// static变量只声明一遍，后面就自动跳过声明，只能在本函数中被访问
    cout << "a:" << a << " b:" << b << endl;
    a++;//执行完函数，非static变量会被释放，而static变量在静态区，只对所属上层负责，也就是func()
    b++;
}

int test_static_var() {
    for (int i = 0; i < 10; i++) func();
    return 0;
}


class Demo{
public:
    static int var;
    static void func(){
        cout<<"class static func a:"<<(Demo::var)++<< endl;
    }
public:
    Demo(int var){
        this->var = var;
    }

};
int Demo::var = 10;//类内声明，类外初始化

int main(int argc, char **argv) {
    test_static_var();
    static_func();
    Demo::func();//测试类的静态方法
    cout<<Demo::var<<endl;//测试类的静态变量
}

