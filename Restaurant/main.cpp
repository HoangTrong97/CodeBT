// g++ main.cpp -o main
#include <bits/stdc++.h>
using namespace std;
  
string split(string str, string delimiter, string &s, string &s1){
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != string::npos) {
        token = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        if(s==""){
            s=token;
            if(s=="add" || s>="00" && s<="99"){
                s="";
            }
        }
        else if(s1=="")
        {
            s1 = token;
            if(s1=="0" || s1== "1")
            {
                s1 = "";
            }
        }
        else {
            break;
        }
    }
    return str;
}

int convert(string str, int &b){
    int aa=0;
        int s_str=sizeof(str);
        for(int i=0; i<s_str-1;i++){
        string t;
        int tg;
        int a=0;
        if(str[i]>='0' && str[i]<='9'){  
            t='\0';
            t=str[i];
            stringstream str2num(t); 
            str2num >> a;
            int j=i+1;
            tg=a;
            if(str[j]>='0' && str[j]<='9'){  
                t='\0';
                t=str[j];
                int b=0;
                stringstream str1num(t); 
                str1num >> b;
                tg= tg*10+b;
            }
            i++;
            if(aa==0){
            aa=tg;
            }
            else if (b==0){
                b=tg;
            }
            else {break;}
         }
    }

    return aa;
}
void addCustomer(queue<tuple<int, int, string, string> > &q,queue<tuple<int, int, string, string> > &q1, string str){
    ofstream input;
    input.open ("Restaurant.txt",ofstream::app);
    int a;
    if(str[0]=='a'){  
        string s,s1;
        str=str+" ";
        split(str," ",s,s1);
        int b=0;
        a=convert(str, b);
        if(b==0){
            tuple<int, int, string, string> tuple1;
            tuple1 = make_tuple(a, b, s, s1);
            q.push(tuple1);
        }
        else if(b==1){
            tuple<int, int, string, string> tuple2;
            tuple2= make_tuple(a, b, s, s1);
            q1.push(tuple2);
        }
        input <<str<< endl;

    }
    input.close();
}

void serve(queue<tuple<int, int, string, string> > &q,queue<tuple<int, int, string, string> > &q1, string str, int &i, int &j)
{   
    ofstream input;
    input.open ("Restaurant.txt",ofstream::app);
    if(j==q.size()){
            i=0;
            j=0;
        }
    if(str[0]=='s'){
        if(i<q1.size()){
            if(!q1.empty()){
                tuple<int, int, string, string> Tuple = q1.front();
                string str1, str2;
                int c=0;
                int e=0;
                c=get<0>(Tuple);
                str1=get<2>(Tuple);
                str2=get<3>(Tuple);
                if(str2!=""){
                    cout<<str2<<"\t"<<str1<<endl;
                    input <<str<<"\t"<<str2<<"\t"<<str1<< endl;
                }
                else{
                    cout<<c<<"\t"<<str1<<endl;
                    input <<str<<"\t"<<c<<"\t"<<str1<< endl;
                }

                q1.pop();
                while(1){
                    tuple<int, int, string, string> Tuple1 = q1.front();
                    int d=0;
                    d=get<0>(Tuple1);
                    if(c==d)
                    {   
                        q1.push(Tuple1);
                        q1.pop();
                        i++;
                        e++;
                    }
                    else{
                        break;
                    }
                    if(e>7){break;}
                }
            }
        }
        else if(j<q.size()){
            if(!q.empty()){
                tuple<int, int, string, string> Tuple1 = q.front();
                string st1, st2;
                int c=0;
                int e=0;
                c=get<0>(Tuple1);
                st1=get<2>(Tuple1);
                st2=get<3>(Tuple1);
                if(st2!=""){
                    cout<<st2<<"\t"<<st1<<endl;
                    input <<str<<"\t"<<st2<<"\t"<<st1<< endl;
                }
                else{
                    cout<<c<<"\t"<<st1<<endl;
                    input <<str<<"\t"<<c<<"\t"<<st1<< endl;
                }
                q.pop();
                while(1){
                    tuple<int, int, string, string> Tuple2 = q.front();
                    int d;
                    d=get<0>(Tuple2);
                    if(c==d)
                    {   
                        q.push(Tuple2);
                        q.pop();
                        j++;
                        e++;
                    }
                    else{
                        break;
                    }
                    if(e>7){break;}
                }
            }
        }
    }
    input.close();
}


int main()
{
    queue<tuple<int, int, string, string> > q;
    queue<tuple<int, int, string, string> > q1;
    int i=0;
    int j=0;
    string str;
    ofstream Input("Restaurant.txt");
    while(1){
        getline(cin,str);
        addCustomer(q ,q1,str);
        serve(q ,q1,str,i,j);
    }
  return 0;
}

