//
// Created by noa on 24/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__BOOT_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__BOOT_H_

#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "StringReverser.h"
#include "Matrix.h"
#include "Astar.h"
#include "Searcher.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "DFS.h"
#include "MyClientHandler.h"
#include "MatrixSolver.h"

namespace boot {
  class Main;
}

class boot::Main {
 public:
  Main() {};
  ~Main() {};
  int main(int argc, char** argv) {
    Solver<string,string>* mySolver = new MatrixSolver();
    mySolver->setSearcher(new Astar());
    if (argc == 1) {
      abstractServer *server = new MyParallelServer(5600, new MyClientHandler(mySolver));
      server->open(5600);
    } else {
      int port = stoi(argv[1]);
      abstractServer *server = new MyParallelServer(port, new MyClientHandler(mySolver));
      server->open(port);
    }
  }
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__BOOT_H_
