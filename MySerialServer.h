//
// Created by hani on 15/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_MYSERIALSERVER_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_MYSERIALSERVER_H


#include "abstractServer.h"


class MySerialServer : abstractServer{
private:
    int port;
    ClientHandler* handler;
    int socket_num;
    sockaddr_in address_num;
public:
    void open(int port, ClientHandler handler);
    void closeServer();
    void acceptClients(ClientHandler handler);
};


#endif //MILESTONE_2_ADVANCED_PROGRAMMING_MYSERIALSERVER_H
