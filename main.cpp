//
// Created by hani on 19/01/2020.
//

#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include <string>

int main(){
    StringReverser *s;

    Solver<string,string> *mySolver = new StringReverser();

    MySerialServer * myServer = new MySerialServer(5600,new MyTestClientHandler(s));
    myServer->open(5600, new MyTestClientHandler(s));
}