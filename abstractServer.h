//
// Created by hani on 15/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_ABSTRACTSERVER_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_ABSTRACTSERVER_H

class abstractServer{
public:
    virtual void open(int num,clientHandler handler)=0;
    virtual void stop()=0;
    virtual void accept(clientHandler handler)=0;
private:
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING_ABSTRACTSERVER_H
