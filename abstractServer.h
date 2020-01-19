//
// Created by hani on 15/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_ABSTRACTSERVER_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_ABSTRACTSERVER_H

#include "ClientHandler.h"
class abstractServer{
public:
    virtual void open(int num)=0;
    virtual void closeServer()=0;
    virtual void acceptClients(int clientSocket)=0;
private:
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING_ABSTRACTSERVER_H
