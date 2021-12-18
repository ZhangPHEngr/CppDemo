#include "all.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;


/**
 * @brief     use of iterator
 * @param     void
 * @return    void
 * @date      2021-02-20
 */
void func1() {
    vector<int> array;
    array.push_back(20);
    array.push_back(24);

    for (vector<int>::iterator it = array.begin(); it != array.end(); it++) {
        cout << (*it) << endl;
    }
}


/**
 * @brief     get sum and mean of a vector
 * @param     void
 * @return    void
 * @date      2021-02-20
 */
void func2() {
    vector<float> tmp;
    for (int i = 1; i < 18; i++) {
        tmp.push_back(i);
        double sum = std::accumulate(tmp.begin(), tmp.end(), 0.0);
        double mean = sum / tmp.size();  //均值
        cout << "avg = " << mean << endl;
    }
}

namespace STL_demo {
int test_vector() {
  // func1();
  func1();
  return 0;
}
}  // namespace vector_demo
