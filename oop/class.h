#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>

using namespace std;

class vandongvien{
    private:
        string hoten;
        int tuoi;
        string monthidau;
        float cannang;
        float chieucao;
    public:
    vandongvien();
    vandongvien(string hoten, int tuoi, string monthidau, float cannang,float chieucao);
    virtual ~vandongvien();
    friend istream &operator>>(istream &is, vandongvien &obj);
    friend ostream &operator<<(ostream &os, vandongvien obj);
    bool operator>(vandongvien obj1);
    };

#endif
