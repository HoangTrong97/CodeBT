#include "client.h"

int main(){
    client client;
    client.create();
    client.Connect();
    client.SendMsg();
    client.ReceiveMsg();
    client.Close();
    return 0;
}
