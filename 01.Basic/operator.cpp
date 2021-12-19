#include <iostream>

using namespace std;


int div_demo() {
    for (int i = 0; i < 8; i++) {
        cout << "i = " << i << ", (i/2) = " << (i / 2) << endl;
    }
    const float K = 0.0 / 0.0;
    cout << K << endl;
    return 0;
}

int main(int argc, char **argv) {
    div_demo();
}
