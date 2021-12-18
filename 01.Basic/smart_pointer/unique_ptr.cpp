//
// Created by zhangph on 12/16/21.
//
#include <iostream>
#include <memory>
/*
 * unique_ptr:
 *     概念：
 *          一个智能指针对象，能唯一控制托管一个指针（资源块），
 *          全局只能有一个unique_ptr用于该资源块，实现该特性就要求unique没有拷贝构造函数，不能赋值运算符，不能clone
 *          unique只支持move()函数来移交资源控制权，移交后原unique_ptr指向空
 *     构造：
 *          unique_ptr<T> pInt(new T()） //unique_ptr没有make方法方便生成
 *     获取原指针：
 *          get()
 */
using namespace std;

int main(int argc, char **argv) {
    // 创建一个unique_ptr实例
    unique_ptr<int> pInt(new int(5));
//    unique_ptr<int> pInt2(pInt);    // 报错, 不能拷贝构造
//    unique_ptr<int> pInt3 = pInt;   // 报错，不能赋值运算
    cout <<"step 1 " <<*(pInt.get()) << endl;
    unique_ptr<int> ptr_new = move(pInt);
    cout <<"step 2 " <<*(pInt.get()) << endl;//这时候指针已经空了，执行异常
    cout <<"step 3 " <<*(ptr_new.get()) << endl;

    return 0;
}
