#include <iostream>

#include "all.h"
/**
 *Lambda表达式：可以被理解为匿名函数
 * 1. 格式：[capture list](param list)->return type{function body};
 *      capture list:用于标记传递到函数体中的外部变量
 *          []  未定义任何可用外部变量
 *          [&]  全部引用传递
 *          [=]  全部值传递
 *          [x, &y] x值传递，y引用传递
 *      param list:调用函数时传递的变量
 *      return type: 返回值，void可以不用写
 *      function body:函数体本身
 *
 */

namespace lambda_demo {

void test() {
  int a = 10;
  int b = 20;
  auto func = [a](int x) -> int { return a + x; };
  std::cout << func(b) << std::endl;
}

}  // namespace lambda_demo
