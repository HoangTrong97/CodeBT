#include "class.h"
#include "utils.h"
 

int main(){
    vandongvien p("Trong",24,"Bong da",170,70.5);
    cout<<p;
    int n;
    vandongvien ds[1000];
    NhapVDV(ds,n);
    SapXep(ds,n);
    return 0;
}
