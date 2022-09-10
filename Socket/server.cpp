#include "server.h"
#define TRUE 1
Server::Server(){};

void Server::create(){
    for (int i = 0; i < max_clients; i++)
	{
		client_socket[i] = 0;
	}
		
	//create a master socket
	if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}	int opt = TRUE;
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
}
void Server::start(){
    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
    if (listen(master_socket, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
    addrlen = sizeof(address);
}
void Server::init_readfds(){
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

void Server::Handle(){
    int activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);
		if ((activity < 0) && (errno!=EINTR))
		{
			printf("select error");
		}
}
void Server::process_incoming_connection(){
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

void Server::process_IO_operations(){
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
				//Somebody disconnected , get his details and print
				printf("Host disconnected , ip %s , port %d \n" ,
					inet_ntoa(address.sin_addr) , ntohs(address.sin_port));
					
				//Close the socket and mark as 0 in list for reuse
				close( sd );
				client_socket[i] = 0;
			}
				
			//Echo back the message that came in
			else
			{
				//set the string terminating NULL byte on the end of the data read
				buffer[valread] = '\0';
				printf("Received from client: %s \n" , buffer);
                strcpy(buffer,"wellcome!!!!");
                send(sd , buffer , valread, 0);
                // send(sd , buffer , valread, 0);
                sleep(0.1);
                if(sd ==4){
                    strcpy(buffer,"Good morning");
				    send(sd , buffer , valread, 0);
                }
                else{
                    strcpy(buffer,"Hi client");
				    send(sd , buffer , valread, 0);
                }
			}
		}
	}
}
