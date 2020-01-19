//
// Created by noa on 19/01/2020.
//

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int socket) {
  char buffer[1024] = {0};
  string line, solution;
  while (line.compare("end") != 0) {
    int valread = read(socket, buffer, 1024);
    string buffer_str(buffer);
    stringstream str_stream(buffer_str);
    getline(str_stream, line, '\n');
    try {
      solution = this->cache_manager->get(buffer_str);
      //if no solution is found solve the problem
    } catch (char const *e) {
      solution = this->solver.solve(buffer);
    }
    int is_sent = send(socket, &solution, solution.size(), 0);
    if (is_sent == -1) {
      cout << "can't send solution (handleClient)" << endl;
    }
    line.clear();
    solution.clear();
  }
}