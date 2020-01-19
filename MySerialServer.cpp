//
// Created by hani on 15/01/2020.
//



#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include "MySerialServer.h"
#include <thread>
#include <unistd.h>
#include <string>

void MySerialServer::open(int a_port) {
    this->port = a_port;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    struct timeval tv;
    tv.tv_sec = 10;
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
//    if (listen(socketfd, 200) == -1) {
//        std::cerr << "Error during listening" << std::endl;
//        exit(-3);
//    }
    this->socket_num = socketfd;
    std::thread acceptThread;
    MySerialServer *server = new MySerialServer(this->port,this->handler);
    acceptThread = std::thread(&MySerialServer::acceptClients,server,this->socket_num);
    acceptThread.join();
    MySerialServer::closeServer();

}

void MySerialServer::acceptClients(int clientSocket) {
    while (listen(clientSocket,200)!=-1) {
        struct timeval tv;
        tv.tv_sec = 5;
        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
        int client_socket = accept(clientSocket, (struct sockaddr *) &this->address_num, (socklen_t *) &this->address_num);
        if (client_socket==-1){
            break;
        }
        try {
            int returnInt = this->handler->handleClient(client_socket);

//            if (returnInt==-10){
//                break;
//            }
        }
        catch(std::exception e){
            MySerialServer::closeServer();
        }
    }
}

void MySerialServer::closeServer() {
    close(this->socket_num);
}

MySerialServer::MySerialServer(int a_port, ClientHandler *a_handler) {
    this->port = a_port;
    this->handler = a_handler;
}

