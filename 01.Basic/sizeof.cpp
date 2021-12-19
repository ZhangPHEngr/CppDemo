//
// Created by ZhangPH on 2021/12/19.
//
#include <iostream>
#include <string>

using namespace std;

struct pp {
    int a;
    int b;
};


int test() {
    cout << sizeof(char) << endl;
    cout << sizeof(uint8_t) << endl;

    int *ss = new int[10];
    cout << ss << endl;

    return 0;
}

int main(int argc, char** argv){
    test();
}