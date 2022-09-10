#include "class.h"
#include "utils.h"

vandongvien::vandongvien(){}
vandongvien::vandongvien(string hoten, int tuoi, string monthidau, float chieucao,float cannang){
    this->hoten = hoten;
    this->tuoi = tuoi;
    this->monthidau = monthidau;
    this->cannang = cannang;
    this->chieucao = chieucao;
}

vandongvien::~vandongvien(){}
istream &operator>>(istream &is, vandongvien &obj)
    {   
        cout << "Nhap ho ten: ";
        is.ignore();
        getline(is,obj.hoten);
        cout << "Nhap tuoi: ";
        is >> obj.tuoi;
        cout<<"Nhap mon thi dau: ";
        is.ignore();
        getline(is,obj.monthidau);
        cout << "Nhap chieu cao: ";
        is >> obj.chieucao;
        cout << "Nhap can nang: ";
        is >> obj.cannang;
        return is;
    }
ostream &operator<<(ostream &os, vandongvien obj)
    {
        os <<obj.hoten<<"\t"<<obj.tuoi<<"\t"<<obj.chieucao<<"\t"<<obj.cannang<<"\t"<<obj.monthidau<<endl;
        return os;
    }
bool vandongvien::operator>(vandongvien obj1){
    if(chieucao > obj1.chieucao){
        return true;
    }
    else if(chieucao == obj1.chieucao){
        if(cannang > obj1.cannang){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void NhapVDV(vandongvien ds[], int &n)
{   
    cout << "Nhap vao so luong VDV: ";
    cin>>n;
    for(int i=0 ; i<n ; i++ ){
        cin>>ds[i];
    }
    for(int i=0; i<n; i++){
        cout<<ds[i];
    }
    
}

void SapXep(vandongvien ds[], int n)
{   
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++){
            if(ds[j]>ds[i]){
                swap(ds[j],ds[i]);
            }
        }
    }
    cout<<"Danh sach sau khi sap xep: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<ds[i];
    }
}
