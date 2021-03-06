//
// Created by noa on 15/01/2020.
//

#include "MyClientHandler.h"
#include <climits>

int MyClientHandler::handleClient(int socket) {
    string line, solution, problem_buffer = "";
    char message[5000000] = {0};
    int i = 1;
    while (true) {
        char buffer[1024] = {0};
        int valread = read(socket, buffer, 1024);
        string buffer_string(buffer);
        problem_buffer += buffer_string;
        //reads in a loop until the word "end" is found. chains it into a buffer.
        if (buffer_string.find("end") != string::npos) {
            break;
        }
        buffer_string.clear();
        i++;
    }

    string problem = problem_buffer.substr(0, problem_buffer.find('e'));
    this->solver->setProblem(problem);
    hash<string> str_hash;
    //makes a hash string for the problem with the given algorithm to solve.
    string prob_hash = to_string(str_hash(problem));
    prob_hash += "_";
    prob_hash += this->solver->getSearcherClassName();
    try {
        solution = this->cache_manager->get(prob_hash);
        cout<<"found in cache"<<endl;
      solution = solution + "\r\n";
      strcpy(message, solution.c_str());
        //if no solution is found solve the problem_buffer
    } catch (char const *e) {
        solution = this->solver->solve(problem);
        //if a solution is empty then the problem cannot be solved.
        if (solution.compare("") == 0) {
            strcpy(message, "No solution found for the problem\r\n");
        } else {
            this->cache_manager->insert(prob_hash, solution);
            solution = solution + "\r\n";
            strcpy(message, solution.c_str());
        }
        //sends the message
    }
  int is_sent = send(socket, &message, strlen(message), 0);
  close(socket);
}