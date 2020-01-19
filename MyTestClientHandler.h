//
// Created by noa on 19/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__MYTESTCLIENTHANDLER_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__MYTESTCLIENTHANDLER_H_
#include "ClientHandler.h"
#include "Solver.h"
#include "ex2.h"
#include <sstream>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#define MAX_CACHE 100

using namespace std;

class MyTestClientHandler : public ClientHandler {
  Solver<string, string>* solver;
  CacheManager<string>* cache_manager;
  void handleClient(int socket);
 public:
  MyTestClientHandler(Solver<string, string>* s) {
    this->solver = s;
    this->cache_manager = new CacheManager<string>(MAX_CACHE);
  }
  ~MyTestClientHandler() {
    delete this->cache_manager;
  }
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__MYTESTCLIENTHANDLER_H_
