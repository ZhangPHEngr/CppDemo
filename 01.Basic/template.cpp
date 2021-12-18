#include <iostream>
/**
 * 模板：
 *      概念：
 *          便于复用，可以对函数和类进行复用
 *          模板函数
 *          模板类
 *      格式：
 *          template <typename T>
 *              ...func body...
 *          template用于声明一下为函数模板
 *          typename说明后续T为可变数据类型，可以是基本数据类型或类，typename可以用class替代
 */

using namespace std;

template <typename T>
T add(T& a, T& b) {
  T c = a + b;
  return c;
}

template <typename T1>
class Tem{
public:
    T1 a;
    Tem(T1 a):a(a){
        cout<<"Tem constructor"<<endl;
    }
};

int main(int argc, char** argv){
    //--------------模板函数-------------//
    int a = 6;
    int b = 4;
    cout << add(a, b) << endl;//模板函数根据输入自动判断T
    //--------------模板类-------------//
    Tem<int> tem(20);//模板类需要手动指定
    cout<< tem.a<<endl;

    return 0;
}


