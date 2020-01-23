//
// Created by noa on 15/01/2020.
//

#include "MyClientHandler.h"

int MyClientHandler::handleClient(int socket) {
  string line, solution, problem_buffer = "";
  char message[1024] = {0};

  while (true) {
    char buffer[1024] = {0};
    int valread = read(socket, buffer, 1024);
    string buffer_string(buffer);
    problem_buffer += buffer_string;
    if (buffer_string.find("end\n") == string::npos) {
      break;
    }
    buffer_string.clear();
  }

  string problem = problem_buffer.substr(0, problem_buffer.length() - 4);
  hash<string> str_hash;
  string prob_hash = to_string(str_hash(problem));
  prob_hash += "_";
  prob_hash += this->solver->getSearcherClassName();

  try {
    solution = this->cache_manager->get(problem);
    //if no solution is found solve the problem_buffer
  } catch (char const *e) {
    solution = this->solver->solve(problem);
    solution = solution+"\r\n";
    strcpy(message, solution.c_str());
  }

  close(socket);
}