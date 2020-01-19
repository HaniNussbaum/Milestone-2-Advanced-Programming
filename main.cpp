//
// Created by hani on 19/01/2020.
//

#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include <string>

int main(){
    Solver<string,string> *mySolver = new StringReverser();
    MySerialServer * myServer = new MySerialServer(5600,new MyTestClientHandler(mySolver));
    myServer->open(5600);
}