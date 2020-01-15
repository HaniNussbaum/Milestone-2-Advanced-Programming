//
// Created by noa on 15/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__MYCLIENTHANDLER_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__MYCLIENTHANDLER_H_
#include <string>
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include "ClientHandler.h"
#include "ex2.h"
#include "Solver.h"
#define MAX_CACHE 100

using namespace std;

class MyClientHandler : public ClientHandler {
  Solver solver;
  CacheManager<string>* cache_manager;
  void handleClient(int socket);
  MyClientHandler(Solver s) {
    this->solver = s;
    this->cache_manager = new CacheManager<string>(MAX_CACHE);
  }
  ~MyClientHandler() {
    delete this->cache_manager;
  }
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__MYCLIENTHANDLER_H_
