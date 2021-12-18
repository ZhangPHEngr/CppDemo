#include "all.h"

#include <iostream>
using namespace std;

namespace static_demo {

void func() {
  // staic变量只声明一遍，后面就自动跳过声明
  static int a = 0;
  cout << a << endl;
  a++;
}

int test() {
  for (int i = 0; i < 10; i++) func();
  return 0;
}

}  // namespace static_demo
