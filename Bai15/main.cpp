#include <iostream>
#include <string>
#include "./utils/mymath.h"

void input_a(int a[], int n){
    int i=0;
    while (i <n)
    {
        std::cin>>a[i];
        i++;
    }
    
}

int main(){
    int n;
    int a[n];
    std::cout <<"Nhap vao n:";
    std::cin >> n;
    std::cout<<"\nNhap mang a: ";
    input_a(a,n);
    std::string str;
    std::vector <int> v;
    std::cout <<"Nhap Str:";
    std::cin >> str;
    StringToVector(str,v);
    InsertionSort(a,n);    
    return 0;
}