/*
基本用法：
 https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html




vector的 = 与 assign: https://blog.csdn.net/weixin_44560698/article/details/119893852

 */

#include <iostream>
#include <vector>
using namespace std;

void func1(){
    vector<int> v1(1, 5);
    vector<int> v2(2, 6);
    vector<int> v3(3, 7);
    vector<int> v4(4, 8);


    cout << "v1.addr: " << &v1 << "\nv2.addr: " << &v2 << endl;
    cout << "v3.addr: " << &v3 << "\nv4.addr: " << &v4 << endl;
    cout<<"赋值前："<<endl;
    cout << "v1-size: " << v1.size() << " v1.addr: " << &v1 << endl;
    cout << "v2-size: " << v2.size() << " v2.addr: " << &v2 << endl;
    v2 = v1;
    cout<<"赋值后："<<endl;
    cout << "v1-size: " << v1.size() << " v1.addr: " << &v1 << endl;
    cout << "v2-size: " << v2.size() << " v2.addr: " << &v2 << endl;

    v4.assign(v3.begin(), v3.end());
    cout << "v3-size: " << v3.size() << " v3.addr: " << &v3 << endl;
    cout << "v4-size: " << v4.size() << " v4.addr: " << &v4 << endl;
}


void init(){
    struct Data{
        int a;
        double b;
    };
    // 批量初始化
    struct Data data{1, 2.0};
    vector<Data> v1;
    v1.assign(10,data);//初始化10个data
    cout<<v1[1].a<<endl;
}

void Vector2D(){
    std::vector<std::vector<int32_t, 2>,3> v1{{1,2},{4,5},{5,6}};
    std::vector<std::vector<int32_t, 2>,3> v2{{1,2,4,},{5,5,6}};
    std::cout << v1[0][2] << std::endl;
}

int main(int argc, char** argv){
//    func1();
//    init();
    Vector2D();
    return 0;
}