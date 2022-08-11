#include <iostream>
#include "mymath.h"

void input_a(int a[], int n){
    for(int i=0; i<n; i++){
        std::cin>>a[i];
    }
}


void output(int a[], int n){
    for(int i=0; i<n; i++){
        std::cout << a[i] <<" ";
    }
}


void SXTD(int a[], int n){
    int tg;
    for(int i=0; i<n; i++){
        tg=a[i];
        for(int j=0; j<n; j++){
            if(a[j]>a[i]){
                tg=a[i];
                a[i]=a[j];
                a[j]=tg;
            }
        }
    }
}


int main(){
    int n;
    int a[n];
    std::cout <<"Nhap vao n:";
    std::cin >> n;
    std::cout<<"\nNhap mang a: ";
    input_a(a,n);
    std::cout<<"\nSap xep tang dan: ";
    SXTD(a,n);
    output(a,n);
    std::cout<<"\nInsertionSort: ";
    InsertionSort(a,n);
    output(a,n);
    std::cout<<"\n";
    return 0;
}
