#include<iostream>
#include<cmath>
#include <ctime>
#include <thread>
#include <string>
#include <sstream>
#include <unistd.h>


using namespace std;

void times(int &h, int &m, int &s){
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    h=tPtr->tm_hour;
    m=tPtr->tm_min;
    s=tPtr->tm_sec;
}

void set_time(int &h, int &m, int &s, int &count)
{   
    while(1){
    int hh=0;
    int mm=0;
    int ss=0;
    string str,t;
    getline(cin,str);
    int s_str=sizeof(str);
    for(int i=0; i<s_str-1;i++){
        int tg=0;
        if(str[i]>='0' && str[i]<='9'){  
            t='\0';
            t=str[i];
            stringstream str2num(t); 
            int a=0;
            str2num >> a;
            tg=a;
            int j=i+1;
            if(str[j]>='0' && str[j]<='9'){
                t='\0';
                t=str[j];
                int b=0;
                stringstream str1num(t); 
                str1num >> b;
                tg= tg*10+b;
            }
            if(hh==0){
                hh=tg;
            }
            else if(mm==0){
                mm=tg;
            }
            else{
                ss=tg;
            }
            if(ss!=0){
                break;
            }
            i=i+1;
        }
    }
    h=hh;
    m=mm;
    s=ss;
    count=0;
    if(s<=9 && m<=9){
        cout<<"Set time to: "<<h<<":"<<"0"<<m<<":"<<"0"<<s<<endl;
    }
    else if(m<=9){
        cout<<"Set time to: "<<h<<":"<<"0"<<m<<":"<<s<<endl;
    }
    else if(s<=9){
        cout<<"Set time to: "<<h<<":"<<m<<":"<<"0"<<s<<endl;
    }
    else{
        cout<<"Set time to: "<<h<<":"<<m<<":"<<s<<endl;  
    }   
}

}
void clo(int &h, int &m, int &s, int &count){
     while (1){
        sleep(1);
        count++;
        s++;
        if(s==60){
            m++;
            s=0;
        }
        if(m==60){
            h++;
            m=0;
        }
        if(count==10){
            if(s<=9 && m<=9){
            cout<<h<<":"<<"0"<<m<<":"<<"0"<<s<<endl;
            }
            else if(m<=9){
            cout<<h<<":"<<"0"<<m<<":"<<s<<endl;
            }
            else if(s<=9){
            cout<<h<<":"<<m<<":"<<"0"<<s<<endl;
            }
            else{
            cout<<h<<":"<<m<<":"<<s<<endl;  
            }
        count=0;
    }
}
}

int main()
{  
    int h,m,s;
    times(h,m,s);
    int count=0;
    
    if(s<=9 && m<=9){
        cout<<h<<":"<<"0"<<m<<":"<<"0"<<s<<endl;
    }
    else if(m<=9){
        cout<<h<<":"<<"0"<<m<<":"<<s<<endl;
    }
    else if(s<=9){
        cout<<h<<":"<<m<<":"<<"0"<<s<<endl;
    }
    else{
        cout<<h<<":"<<m<<":"<<s<<endl;  
    }

    thread t1(set_time,ref(h),ref(m),ref(s),ref(count));
    thread t2(clo,ref(h),ref(m),ref(s),ref(count));

    t1.join();
    t2.join();

    return 0;
}
