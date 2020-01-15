//
// Created by hani on 15/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_MYSERIALSERVER_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_MYSERIALSERVER_H


#include "abstractServer.h"

class MySerialServer : abstractServer{
private:
    int port;
    clientHandler handler;
    int socket_num;
public:
    void open(int port, clientHandler handler);
    void close();
    void accept(clientHandler handler);
};


#endif //MILESTONE_2_ADVANCED_PROGRAMMING_MYSERIALSERVER_H
