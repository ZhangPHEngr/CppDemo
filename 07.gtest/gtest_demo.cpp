#include "gtest_demo.h"

using namespace std;

GTestDemo::GTestDemo(int a) {
    m_field_1 = a;
}

int GTestDemo::Func_1() {
    int a = 10;
    for (int i = 0; i < a; ++i) {
        cout<<i<<endl;
    }
    return a;
}

//int main(){
//    auto *gTestDemo = new GTestDemo();
//    gTestDemo->Func_1();
//}
