
#include "all.h"

using namespace std;


namespace STL_demo {
int test_map(){
    map<int, string> mapStudent;

    //数据插入：
    //第一种：用insert函数插入pair数据
    mapStudent.insert(pair<int, string>(1, "student_one"));
    mapStudent.insert(pair<int, string>(2, "student_two"));
    mapStudent.insert(pair<int, string>(3, "student_three"));
    //第二种：用下标插入
    mapStudent[100] = "pppp";

    map<int, string>::iterator iter;
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
        cout<<iter->first<<' '<<iter->second<<endl;
}
}
