/*
1.基本类型
    布尔型	bool    1
    字符型	char    1
    整型	    int     4
    浮点型	float   4
    双浮点型	double  8
    以上基础类型还可加上前修饰符：signed unsigned short long
    通过 typedef 自定义数据类型: typedef int new_name
2.指针类型
    数据类型+*   int*   声明一个指向int型数据的指针
    无类型指针	void*   声明一个指向void型数据的指针，void可以指向任何类型，用的时候再强转
    指针变量声明中，*表示当前变量用于存储地址，变量类型表示该地址上数据应该被解析的类型
    指针所占空间与计算机位数有关，64位对应8Byte，32位对应4Byte
3.string
    初始化:
        string s = "1234";
    转换
        string -> const char *          s.data() or s.c_str()
        string -> char *                (char*)s.c_str()
        const char* -> string           s = c
        char* -> string                 s = c
4.结构体类型
    struct 结构体名{
        标识符[=整型常数]；
        ...
        标识符[=整型常数]；
    } 结构体变量;
    定义
    初始化
    访问
    嵌套
    传参和返回
    参考：http://c.biancheng.net/view/1407.html
5.枚举类型
    enum 枚举名{
        标识符[=整型常数],
        ...
        标识符[=整型常数]
    } 枚举变量;
    默认0开头，下一个比上一个大1

扩展知识：
    A.关键字
        const       定义常量，不可改变
        volatile    不可被优化
        restrict
        explicit
        auto        自动引用
        register
        static      变量放在静态区, 函数和类不对外可见
        extern      函数和类对外可见
        static_case：https://www.cnblogs.com/QG-whz/p/4509710.html
    B.左值和右值
        左值（lvalue）：指向内存位置的变量或表达式。左值可以出现在赋值号的左边或右边。变量
        右值（rvalue）：存储在内存中某些地址上的数值。右值是不能被赋值的表达式。具体值
    C.常量
    常量：
        整数常量：
            85         // 十进制
            0213       // 八进制
            0x4b       // 十六进制
            30u        // 无符号整数
            30l        // 长整数
            30ul       // 无符号长整数
        浮点数常量：
            1e6
        其他常量：https://www.runoob.com/cplusplus/cpp-constants-literals.html
        const常量 const int a = 10;
        预定义：#define LENGTH 10
    D.局部变量，全局变量
    E.形式参数，实际参数
参考：
    https://www.runoob.com/cplusplus/cpp-data-types.html
 */

#include<iostream>
#include <limits>

using namespace std;

void basic_demo(){
    bool a = false;
    char b = 's';
    int c = 1;
    float d = 2;
    double e = 3;
    cout<<"bool size:"<< sizeof(a)<<" 该类型最小值："<<numeric_limits<bool>::min()<<" 最大值:"<<numeric_limits<bool>::max()<<endl;
    cout<<"char size:"<< sizeof(b)<<" 该类型最小值："<<numeric_limits<char>::min()<<" 最大值:"<<numeric_limits<char>::max()<<endl;
    cout<<"int size:"<< sizeof(c)<<" 该类型最小值："<<numeric_limits<int>::min()<<" 最大值:"<<numeric_limits<int>::max()<<endl;
    cout<<"float size:"<< sizeof(d)<<" 该类型最小值："<<numeric_limits<float>::min()<<" 最大值:"<<numeric_limits<float>::max()<<endl;
    cout<<"double size:"<< sizeof(e)<<" 该类型最小值："<<numeric_limits<double>::min()<<" 最大值:"<<numeric_limits<double>::max()<<endl;

}

void ptr_demo(){
    int n = 3;
    int* a = &n;//&表示取地址
    cout<<"res:"<< *a<<endl;//*表示解析指针所指内存的值
    cout<<"* size:"<< sizeof(a)<<endl;
    void* p = (void*)a;
    cout<<"p res:"<< *a <<endl;
    cout<<"* size:"<< sizeof(p)<<endl;
}

void enum_demo(){
    enum Demo{
        a,
        b,
        c
    };
    Demo s = a;
    cout<<"enum "<<s<<endl;
}

void struct_demo(){
    struct Date
    {
        int day = 23;
        int month = 8;
        int year = 1983;
    };
    Date date;
    cout<<"结构体访问："<<date.day<<endl;
}

void string_demo() {
    //string 是个类， char是基础数据类型，https://www.cnblogs.com/Pillar/p/4206452.html

    //string -> const char *
    string s = "1234";
    const char* p;
    p = s.c_str();//等同于s.data();
    cout<<p<<endl;

    //string -> char *
    char* p1 = (char*)s.data();
    cout<<p1<<endl;

    //char* -> string
//    char *p2 = "hello";//直接赋值
//    string s2 = p2;
//    cout<<p2<<endl;

    //const char* -> string
    const char *p3 = "hello";//直接赋值
    string s3 = p3;
    cout<<p3<<endl;

    //字符串拆分：strtok 与 strsep 函数说明: https://www.cnblogs.com/devilmaycry812839668/p/6353912.html
    //以上两个函数都会改变原字符串，所以最好先strcpy复制要被拆分的字符串
}

//字符串指定位置添加
void str_joint(){
    char ss[256];
    int index = 20;
    snprintf(ss,256,"this is cam %d ",index);
    cout<<ss<<endl;
}

int main(int argc, char** argv){
//    basic_demo();
//    ptr_demo();
//    enum_demo();
//    struct_demo();
    return 0;
}



