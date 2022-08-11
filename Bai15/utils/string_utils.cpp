#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "mymath.h"

std::vector<int> StringToVector(std::string str){
    std::vector <int> vt;
    std::stringstream ss;
    ss << str;
    std::string tg;
    int a;
    while (!ss.eof()) { 
        ss >> tg;
        if (std::stringstream(tg) >> a)
            vt.push_back(a);
        tg="";
    }
    for(int i=0; i<vt.size(); i++){
        std::cout<<vt[i]<<" " ;
    }
        std::cout<<"\n" ;
    return vt;
}
