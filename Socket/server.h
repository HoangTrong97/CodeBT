#ifndef SERVER_H
#define SERVER_H
#include <bits/stdc++.h>
#include <iostream>	
#include <stdio.h>	
#include <string.h>	
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;
class Server  { 
public:
    Server();
    void create();
    void start();
    void init_readfds();
    void Handle();
    void process_incoming_connection(); 
    void process_IO_operations();
private:
    int max_sd;
    fd_set readfds;
    int max_clients = 30;
    int client_socket[30];
    int master_socket;	
    struct sockaddr_in address;
    int addrlen;
    int PORT=8080;
};
#endif
