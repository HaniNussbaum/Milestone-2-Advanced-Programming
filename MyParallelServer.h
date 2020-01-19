//
// Created by hani on 16/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_MYPARALLELSERVER_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_MYPARALLELSERVER_H

#include <netinet/in.h>
#include "abstractServer.h"

class MyParallelServer : abstractServer{
private:
    int port;
    ClientHandler *handler;
    int socket_num;
    sockaddr_in address_num;
public:
    void open(int port);
    MyParallelServer(int port, ClientHandler *handler);
    void closeServer();
    void acceptClients(int clientSocker);
    ~MyParallelServer();
};


#endif //MILESTONE_2_ADVANCED_PROGRAMMING_MYPARALLELSERVER_H
