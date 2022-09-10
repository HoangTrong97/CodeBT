#include "server.h"

int main(int argc, char *argv[]){
    Server server;
    server.create();
    server.start();
    while(true){
        server.init_readfds();
        server.Handle();
        server.process_incoming_connection();
        server.process_IO_operations();
    }
    return 0;
}
