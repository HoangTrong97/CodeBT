// $ g++ -std=c++11 restaurant.cpp -o restaurant -lpthread

#include <iostream>
#include <stdio.h>
#include <unistd.h> //close
#include <arpa/inet.h> //close
#include <bits/stdc++.h>
#include <thread>

using namespace std;
	
#define TRUE 1
#define FALSE 0
#define PORT 8888

int max_sd;
fd_set readfds;
const int max_clients = 30;
int client_socket[max_clients];
int master_socket;		
struct sockaddr_in address;
int addrlen;

void init_readfds() {

	//clear the socket set
	FD_ZERO(&readfds);

	//add master socket to set
	FD_SET(master_socket, &readfds);
	max_sd = master_socket;
		
	//add child sockets to set
	for (int i = 0 ; i < max_clients ; i++)
	{
		//socket descriptor
		int sd = client_socket[i];
			
		//if valid socket descriptor then add to read list
		if(sd > 0)
			FD_SET( sd , &readfds);
			
		//highest file descriptor number, need it for the select function
		if(sd > max_sd)
			max_sd = sd;
	}
}

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

int convert(string str){
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
            if(aa==0){
            aa=tg;
            }
            else {break;}
         }
    }

    return aa;
}

string split(string str, string delimiter, string &s){
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != string::npos) {
        token = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        if(s==""){
            s=token;
            if(s>="00"&&s<="99"){
                s="";
            }
            if(s=="request"){
                s="";
            }
        }
        else{break;}
    }
    str=s;
    return str;
}

void addCustomer(queue<tuple<int, string, int> > &q, string s, int &a,int sd){
        string s1;
        split(s," ",s1);
        tuple<int, string, int> tuple1;
        tuple1 = make_tuple(a, s1, sd);
        q.push(tuple1);
        a++;

}

void serve(queue<tuple<int,string,int> > &q, int valread)
{   
    string st;
    char buff[1000];
	while(1){
    getline(cin,st);
    if(st[0]=='s'){
		if(!q.empty()){
                strcpy(buff,"Don mon");
                tuple<int, string, int> Tuple = q.front();
                string str1=get<1>(Tuple);
                char *temp = new char[str1.size()+1];
                for(int i=0; i<str1.size()+1; i++)
                    temp[i]=str1[i];
                strcat(buff, "  ");
                strcat(buff, temp);
                int a=get<2>(Tuple);
                cout<<get<0>(Tuple)<<"\t"<<temp<<endl;
                send( a, buff , valread, 0);
                int c=get<0>(Tuple);
                int e=0;
                q.pop();
				if(!q.empty()){
                while(1){
                    tuple<int, string, int> Tuple1 = q.front();
                    int d=0;
                    d=get<0>(Tuple1);
                    if(c==d)
                    {   
                        q.push(Tuple1);
                        q.pop();
                        e++;
                    }
                    else{
                        break;
                    }
                    if(e>7){break;}
                }
				}
				strcpy(buff,"Don mon");
            }
        // }
    }
    }
}

void process_incoming_connection() {
	if (FD_ISSET(master_socket, &readfds))
	{
		int new_socket;
		// printf("before accept\n");
		if ((new_socket = accept(master_socket,
				(struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}
		
			
		//add new socket to array of sockets
		for (int i = 0; i < max_clients; i++)
		{
			//if position is empty
			if( client_socket[i] == 0 )
			{
				client_socket[i] = new_socket;
				break;
			}
		}
	}
}

void process_IO_operations(queue<tuple<int, string, int> > &q) {
	//else its some IO operation on some other socket
	for (int i = 0; i < max_clients; i++)
	{
		int sd = client_socket[i];
			
		if (FD_ISSET( sd , &readfds))
		{
			getpeername(sd , (struct sockaddr*)&address , (socklen_t*)&addrlen);

			//Check if it was for closing , and also read the
			//incoming message
			char buffer[1024]; //data buffer of 1K
			int valread;
			if ((valread = read( sd , buffer, 1024)) == 0)
			{
				
				//Close the socket and mark as 0 in list for reuse
				close( sd );
				client_socket[i] = 0;
			}
				
			//Echo back the message that came in
			else
			{
				//set the string terminating NULL byte on the end of the data read
				buffer[valread] = '\0';
				printf("%s \n" ,buffer);
                string ss=convertToString(buffer, 1024);
                int a=convert(ss);
                addCustomer(q,ss,a,sd);
			}
			    thread t1(serve,ref(q),valread);
                t1.detach();
		}
	}
}

int main(int argc , char *argv[]){

    queue<tuple<int, string, int> > q;
	for (int i = 0; i < max_clients; i++)
	{
		client_socket[i] = 0;
	}
		
	//create a master socket
	if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	
	//set master socket to allow multiple connections ,
	//this is just a good habit, it will work without this
	int opt = TRUE;
	if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR  | SO_REUSEPORT, (char *)&opt,
		sizeof(opt)) < 0 )
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	
	//type of socket created
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
		
	//bind the socket to localhost port 8888
	if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
		
	//try to specify maximum of 3 pending connections for the master socket
	if (listen(master_socket, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
		
	//accept the incoming connection
	addrlen = sizeof(address);
		
	while(TRUE)
	{
		init_readfds();
		int activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);
		if ((activity < 0) && (errno!=EINTR))
		{
			printf("select error");
		}	
		process_incoming_connection();
		process_IO_operations(q);
	}
		
	return 0;
}
