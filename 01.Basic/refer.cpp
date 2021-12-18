#include "all.h"

#include <iostream>
using namespace std;

namespace refer_demo {

void func(int& a, int* pp) { pp[0] = a; }

void test() {
  int array[2] = {0, 1};
  int ss = 9;
  func(ss, array);
  cout << array[0] << endl;
  cout << array[1] << endl;
}
}  // namespace refer_demo
