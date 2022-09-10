#include "client.h"

client::client(){}

void client::create(){
    sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		printf("Could not create socket");
	}
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( PORT );
}
void client::Connect(){
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("connect failed. Error");
	}
}
void client::SendMsg(){
    if( write(sock , message , strlen(message)) < 0)
	{
		puts("Send failed");
	}
}
void client::ReceiveMsg(){
	while(1){
    	int nRead = read(sock , server_reply , 2000);
		if(nRead  < 0)
		{
			puts("recv failed");
		 	break;
		}
		server_reply[nRead] = 0;
		std::cout << "Server replyx :" << server_reply << std::endl;
	}
}
void client::Close(){
    close(sock);
}
