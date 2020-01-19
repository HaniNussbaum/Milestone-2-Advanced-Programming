//
// Created by noa on 15/01/2020.
//

#include "MyClientHandler.h"

void MyClientHandler::handleClient(int socket) {
  char buffer[1024] = {0};
  //vector<double> double_Vector;
  int valread = read(socket, buffer, 1024);
  string buffer_str(buffer);
  stringstream str_stream(buffer_str);
  string line;
  getline(str_stream, line, '\n');



  //if solution is in cache send it back
  string solution;
  try {
    solution = this->cache_manager->get(buffer_str);
  //if no solution is found solve the problem
  } catch(char const* e) {
    solution = this->solver.solve(buffer);
  }
  int is_sent = send(socket, &solution, solution.size(), 0);
  if (is_sent == -1) {
    cout<<"can't send solution (handleClient)"<<endl;
  }
}