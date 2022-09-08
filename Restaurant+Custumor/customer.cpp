#include <iostream>	//printf
#include <stdio.h>	//printf
#include <string.h>	//strlen
#include <arpa/inet.h>	//inet_addr
#include <unistd.h>
#include <thread>

using namespace std;

#define PORT 8888
void reply(char* server_reply, int sock)
{		
		// bzero(server_reply, 2000);
		int nRead = read(sock , server_reply , 2000);
		if(nRead  < 0)
		{
			puts("recv failed");
			// break;
		}
		server_reply[nRead] = 0;
		std::cout<< server_reply << std::endl;
}
int main(int argc , char* argv[])
{
	struct sockaddr_in server;
	char message[1000] , server_reply[2000],tam[200];
	char* a;
	for (int i = 0; i < argc; ++i) {
    a=argv[i];
    }
	strcpy(message, a);
	//Create socket
	int sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		printf("Could not create socket");
		return -1;
	}

	
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( PORT );

	//Connect to remote server
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("connect failed. Error");
		return -1;
	}
	
	
	//keep communicating with server
	while(1)
	{	
		fgets(tam, sizeof(tam), stdin);
		strcat(message, " ");
    	strcat(message, tam);
		//Send some data
		if( write(sock , message , strlen(message)) < 0)
		{
			puts("Send failed");
			return -1;
		}
		thread t1(reply,server_reply,sock);
        t1.detach();
		strcpy(message, a);
	}
	
	close(sock);
	return 0;
}