#include <iostream>
#include <array>

void InitArray(){
    std::array<int,2> array1{2,3};
    std::array<int,2> array2{{2,3}};
    array1 = {5,6};
    std::cout << array1[0] << std::endl;
    std::cout << array2[1] << std::endl;
}

void Array2D(){
    std::array<int32_t, 2> a1{1,2};
    std::array<int32_t, 2> a2{3,4};
    std::array<std::array<int32_t, 2>, 2>a{a1,a2};
    std::cout << a[1][1] << std::endl;
}
int main(int argc, char** argv){
//    InitArray();
    Array2D();
    return 0;
}
