//
// Created by zhangph on 12/17/21.
//

/*
 static_cast

 dynamic_cast

 */
#include <iostream>

using namespace std;
int main(int argc, char** argv){

    string s{""};
    s = s + to_string(2);

    int32_t a = -10;
    uint32_t b = static_cast<uint32_t>(a);

    uint32_t c = 5;
    int32_t d = static_cast<int32_t>(c);
    cout<<b<<endl;
    cout<<d<<endl;

    int32_t mm = -1;
    cout<<static_cast<double>(mm)<<endl;

    uint32_t u1 = 10;
    int32_t u2 = 3;
    cout<<u1*u2<<endl;

    cout<<static_cast<int32_t>(false)<<endl;

    int64_t u3 = 10;
    int32_t u4 = 30;
    cout<<u3*u4<<endl;
    cout<<u4 - u3<<endl;

    return 0;
}