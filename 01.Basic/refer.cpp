#include <iostream>

using namespace std;

/*
 * 引用：
 *      概念：
 *          引用的最大作用是作为指针传递数据，不用copy
 *      使用范围：
 *          一般引用
 *          函数形参
 *          函数范围值
 *
 *      引用和指针的区别：
 *          不存在空引用。引用必须连接到一块合法的内存。
 *          一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
 *          引用必须在创建时被初始化。指针可以在任何时间被初始化。
 */

void func1() {
    int a = 1;
    int c = 2;
    int &b = a;
    b = c;
    cout << b << endl;
}

void func2(int &a, int *pp) {
    pp[0] = a;
}

int &func3() {
    static int a = 10;//这里必须是static，因为一般变量在函数结束时会被销毁，静态变量内存块会一直保留
    return a;
}

int main(int argc, char **argv) {
    func1();

    int array[2] = {0, 1};
    int ss = 9;
    func2(ss, array);
    cout << array[0] << endl;

    int &res = func3();
    cout << res << endl;
}
