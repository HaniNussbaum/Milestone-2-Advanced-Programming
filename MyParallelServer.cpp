//
// Created by hani on 16/01/2020.
//

#include "MyParallelServer.h"
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <thread>
#include <unistd.h>

void MyParallelServer::open(int a_port) {
    //opens a regular server with the given port.
    this->port = a_port;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    struct timeval tv;
    tv.tv_sec = 120;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);

    if (socketfd == -1) {
        std::cerr << "Could not create a socket" << std::endl;
        exit(-1);
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(this->port);
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        exit(-2);
    }
    this->address_num = address;
    this->socket_num = socketfd;
    MyParallelServer::acceptClients(this->socket_num);
    MyParallelServer::closeServer();
}

void MyParallelServer::acceptClients(int clientSocket) {
    //listens to up to 1024 clients in a vector.
    while (listen(clientSocket, 1024) != -1) {
        //sets a timeout of 120 seconds for the socket.
        struct timeval tv;
        tv.tv_sec = 120;
        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
        int client_socket = accept(clientSocket, (struct sockaddr *) &this->address_num,
                                   (socklen_t *) &this->address_num);
        if (client_socket == -1) {
            break;
        }
        ClientHandler *currClientHandler = handler->clone();
        //each client has its own thread opened to it with a given personal socket.
        //the thread is then detached.
        std::thread clientThread(&ClientHandler::handleClient, currClientHandler, client_socket);
        clientThread.detach();
    }
}

MyParallelServer::MyParallelServer(int port, ClientHandler *handler) {
    this->port = port;
    this->handler = handler;
}

void MyParallelServer::closeServer() {
    close(this->socket_num);
}
