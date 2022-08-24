#include <iostream>
#include <cstring>
#include <string>

struct sinhvien
{
    char ten[50];
    int namsinh;
    std::string noisinh;
    int sothutu;
    std::string ngaytruc;
};
 
 typedef sinhvien sv;

void Nhap(sv arr_sv[]){
    int i=0;
    while(i<6){
        std::cout<<"\nsinh vien thu "<<i+1 ;
        std::cout<<"\nTen: ";
        std::cin>>arr_sv[i].ten;
        std::cout<<"\nNam sinh: ";
        std::cin>>arr_sv[i].namsinh;
        std::cout<<"\nNoi sinh: ";
        std::getline(std::cin, arr_sv[i].noisinh);
        std::getline(std::cin, arr_sv[i].noisinh);
        arr_sv[i].sothutu=0;
        arr_sv[i].ngaytruc=" ";
        i++;
    }
}
void convert(sv arr_sv[]){
    int a;
    for (int i = 0; i < 6; i++)
    {
        if(arr_sv[i].ten[0]>=97 && arr_sv[i].ten[0]<=122)
            arr_sv[i].ten[0]=arr_sv[i].ten[0]-32;
        for (int j = 1; j < 6; j++)
        {
             if(arr_sv[i].ten[j]>=65 && arr_sv[i].ten[j]<=90)
                arr_sv[i].ten[j]=arr_sv[i].ten[j]+32;
        }    
    }
}
    
 

void Sapxep(sv arr_sv[])
{
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<6;j++)
		{
		   if(strcmp(arr_sv[i].ten,arr_sv[j].ten)>0)
		  {
			sv k=arr_sv[i];
            arr_sv[i]=arr_sv[j];
            arr_sv[j]=k;
		  }
		}
	} 
}
void Xuat(sv arr_sv[])
{
	for(int i=0;i<6;i++)
	{
		std::cout <<"\nTen "<<arr_sv[i].ten;
	}
}
void CapNhat(sv arr_sv[])
{   

    for (int i = 0; i < 6; i++)
    {
        arr_sv[i].sothutu=i+1;
    }
}

void Ngaytruc(std::string sv_chan[],std::string sv_le[], sv arr_sv[]){
    int a=0;
    int b=0;
    for (int i = 0; i < 6; i++)
    {   

        if(arr_sv[i].sothutu%2==0){
            sv_chan[a]=arr_sv[i].ten;
            arr_sv[i].ngaytruc="Truc 2 4 6";
            a++;
        }
        else
        {
            sv_le[b]=arr_sv[i].ten;
            arr_sv[i].ngaytruc="Truc 3 5 7";
            b++;
        }
    }
    
}
void output_arr(std::string sv_chan[],std::string sv_le[]){
    std::cout<<"\nDanh sach truc ngay chan: ";
    for(int i=0; i<3
; i++)
    {
        std::cout<<sv_chan[i]<<" ";
    }
    std::cout<<"\nDanh sach truc ngay le: ";
     for(int i=0; i<3
; i++)
    {
        std::cout<<sv_le[i]<<" ";
    }
}

 int main(){
    sv  arr_sv[6];
    std::string sv_chan[3], sv_le[3];

    std::cout<<"Nhap Thong tin sinh vien: ";

    Nhap(arr_sv);

    convert(arr_sv);
    Sapxep(arr_sv);
    Xuat(arr_sv);

    CapNhat(arr_sv);
    Ngaytruc(sv_chan,sv_le,arr_sv);
    output_arr(sv_chan,sv_le);
    
    return 0;
 }