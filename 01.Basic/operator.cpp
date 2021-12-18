#include "all.h"

#include <iostream>
using namespace std;

namespace div_demo {

int test() {
  for (int i = 0; i < 8; i++) {
    cout << "i = " << i << ", (i/2) = " << (i / 2) << endl;
  }
    const float K = 0.0 / 0.0;
    cout<<K<<endl;
  return 0;
}

}  // namespace div_demo
