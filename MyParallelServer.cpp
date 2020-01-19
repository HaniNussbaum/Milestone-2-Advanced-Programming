////
//// Created by hani on 16/01/2020.
////
//
//#include "MyParallelServer.h"
//#include <sys/socket.h>
//#include <iostream>
//#include <netinet/in.h>
//#include <thread>
//#include <unistd.h>
//
//void MyParallelServer::open(int port, ClientHandler *handler) {
//    this->port = port;
//    this->handler = handler;
//    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
//    struct timeval tv;
//    tv.tv_sec = 120;
//    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
//    this->socket_num = socketfd;
//    if (socketfd == -1) {
//        std::cerr << "Could not create a socket" << std::endl;
//        exit(-1);
//    }
//    sockaddr_in address;
//    address.sin_family = AF_INET;
//    address.sin_addr.s_addr = INADDR_ANY;
//    address.sin_port = htons(this->port);
//    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
//        std::cerr << "Could not bind the socket to an IP" << std::endl;
//        exit(-2);
//    }
//    this->address_num = address;
//    if (listen(socket_num, 200) == -1) {
//        std::cerr << "Error during listening" << std::endl;
//        exit(-3);
//    }
//}