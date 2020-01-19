//
// Created by hani on 15/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_MYSERIALSERVER_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_MYSERIALSERVER_H


#include "abstractServer.h"
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <thread>
#include <unistd.h>

class MySerialServer : public abstractServer {
private:
    int port;
    ClientHandler *handler;
    int socket_num;
    sockaddr_in address_num;
public:
    void open(int port, ClientHandler *handler);

    void closeServer();

    void acceptClients(ClientHandler *handler);

    MySerialServer(int port,ClientHandler *handler);
    ~MySerialServer();
};


#endif //MILESTONE_2_ADVANCED_PROGRAMMING_MYSERIALSERVER_H
