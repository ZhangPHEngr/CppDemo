#include <gtest/gtest.h>
#include "gtest_demo.h"

/*
教程：https://blog.csdn.net/ONEDAY_789/article/details/76718463
1.gtest概念
2.TEST三个宏
3.断言宏：ASSERT宏和EXPECT宏
4.事件机制
5.死亡测试

A.TEST宏定义：
 1.TEST(测试集合名，测试用例名)
 2.TEST_F(fixture集合，测试用例名)

B.测试集合包括两种：
 1.一般测试集合
 2.fixture测试集合，可以赋予特殊的上下文内容，和【TestSuite，TestCase事件机制关联】

C.测试用例：一个测试集合可以包含多个测试用例，用例名随意

D.事件机制：
 1.全局事件
    为当前测试文件修改环境
    会在整体测试用例前后执行SetUp()和TearDown()函数
 2.TestSuite事件
    为每个测试集合添加上下文处理
    会在当前suite包含的用例前后执行SetUpTestCase()和TearDownTestCase()
 3.TestCase事件
    为每个测试用例添加上下文处理
    会在每个测试用例前后执行SetUp()和TearDown()函数
 */


int add(int a,int b){
    return a+b;
}

//---------------测试集合和测试用例 demo--------------------//
TEST(testCaseA,test0){
    EXPECT_EQ(add(2,3),5);
}
TEST(testCaseA,test1){
    EXPECT_EQ(add(3,3),5);
}
TEST(testCaseB,test0){
    EXPECT_EQ(add(10,3),13);
}

//------------------测试别的文件中的函数--------------------//
TEST(TestSuite_GTestDemo, Func_1){
//    GTestDemo gTestDemo(10);
    EXPECT_TRUE(GTestDemo(10).Func_1() == 10) << "返回不为10";
}

//------------------全局环境修改-------------------------//
class FooEnvironment : public testing::Environment {
public:
    virtual void SetUp() {
        std::cout << "全局环境改动 开始" << std::endl;
    }

    virtual void TearDown() {
        std::cout << "全局环境改动 结束" << std::endl;
    }
};
//------------------TestSuite事件-------------------------//
class TestSuite : public testing::Test {
protected:
    static void SetUpTestCase() {
        int a = 100;
        std::cout << "Fixture集合上文" << std::endl;
    }
    static void TearDownTestCase() {
        std::cout << "Fixture集合下文" << std::endl;
    }
};
TEST_F(TestSuite, test0){

    EXPECT_EQ(add(2,3),5);
}
TEST_F(TestSuite, test1){
    EXPECT_EQ(add(3,3),5);
}

//------------------TestCase事件-------------------------//
class FooCalcTest:public testing::Test{
protected:
    virtual void SetUp()
    {
        std::cout << "单个Case上文" << std::endl;
    }
    virtual void TearDown()
    {
        std::cout << "单个Case下文" << std::endl;
    }
};

TEST_F(FooCalcTest, test0)
{
    EXPECT_EQ(add(3,3),5);
}

TEST_F(FooCalcTest, test1)
{
    EXPECT_EQ(add(3,3),5);
}

//------------------07.gtest-------------------------//
int main(int argc, char *argv[])
{
    testing::AddGlobalTestEnvironment(new FooEnvironment);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
