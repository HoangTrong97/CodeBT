#ifndef CLIENT_H
#define CLIENT_H
#include <bits/stdc++.h>
#include <iostream>	
#include <stdio.h>	
#include <string.h>	
#include <arpa/inet.h>
#include <unistd.h>

class client{
    public:
        client();
        void create();
        void SendMsg() ;
        void ReceiveMsg() ;
        void Close();
        void Connect();
    private:
        char server_reply[2000];
        char message[1000]="Hello sever!";
        struct sockaddr_in server;
        int sock;
        int PORT=8080;
};
#endif
