#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include "mymath.h"

void StringToVector(std::string str, std::vector <int> v){
    std::copy(str.begin(), str.end(), std::back_inserter(v));
    for(int i=0; i<v.size(); i++){
        std::cout<<v[i]<<" " ;
    }
    std::cout <<"\n";
}