#include<iostream>
#include "mymath.h"
#include <vector>
void InsertionSort(std::vector <int> v){
 int i, key, j;
   for (i = 1; i <v.size(); i++)
   {
       key = v[i];
       j = i-1;
       while (j >= 0 && v[j] > key)
       {
           v[j+1] = v[j];
           j = j-1;
       }
       v[j+1] = key;
   }
    for (int i = 0; i <v.size(); i++)
    {
        std::cout <<v[i]<<" ";
    }
}
