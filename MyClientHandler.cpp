//
// Created by noa on 15/01/2020.
//

#include "MyClientHandler.h"

int MyClientHandler::handleClient(int socket) {
  string line, solution, problem_buffer = "";
  char message[10000] = {0};
  int i = 1;
  while (true) {
    char buffer[1024] = {0};
    int valread = read(socket, buffer, 1024);
    string buffer_string(buffer);
    cout<<buffer_string<<endl;
    problem_buffer += buffer_string;
    if (buffer_string.find("end") != string::npos) {
      break;
    }
    buffer_string.clear();
    i++;
  }
  cout<<to_string(i)<<endl;
  string problem = problem_buffer.substr(0, problem_buffer.length() - 4);
  this->solver->setProblem(problem);
  hash<string> str_hash;
  string prob_hash = to_string(str_hash(problem));
  prob_hash += "_";
  prob_hash += this->solver->getSearcherClassName();

  try {
    solution = this->cache_manager->get(problem);
    //if no solution is found solve the problem_buffer
  } catch (char const *e) {
    solution = this->solver->solve(problem);
    this->cache_manager->insert(prob_hash, solution);
    solution = solution+"\r\n";
    strcpy(message, solution.c_str());
    int is_sent = send(socket, &message, strlen(message), 0);
  }
  close(socket);
}