#include <iostream>
#include <string>
#include <vector>
#include "./utils/mymath.h"

int main(){
    std::string str;
    std::vector <int> v;
    std::cout <<"Nhap chuoi so Str:";
    std::getline(std::cin, str);
    v=StringToVector(str);
    InsertionSort(v);
    return 0;
}
