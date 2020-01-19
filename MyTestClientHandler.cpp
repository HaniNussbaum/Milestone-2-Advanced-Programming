//
// Created by noa on 19/01/2020.
//

#include "MyTestClientHandler.h"
#include <string.h>
#include <algorithm>

int MyTestClientHandler::handleClient(int socket) {


    string line, solution;
    while (line.compare("end") != 0) {
        char buffer[1024] = {0};
        char message[1024]={0};

        int valread = read(socket, buffer, 1024);
        string buffer_string(buffer);
        stringstream str_stream(buffer_string);
        std::string chars = "\r\n";
        for (char c:chars) {
            buffer_string.erase(std::remove(buffer_string.begin(), buffer_string.end(), c), buffer_string.end());
        }
        if(buffer_string.compare("end")==0){
            buffer_string.clear();
            break;
        }
        try {
            solution = this->cache_manager->get(buffer_string);
            //if no solution is found solve the problem
        } catch (char const *e) {
            for (char c:chars) {
                buffer_string.erase(std::remove(buffer_string.begin(), buffer_string.end(), c), buffer_string.end());
            }
            solution = this->solver->solve(buffer_string);
            solution = solution+"\r\n";
            strcpy(message, solution.c_str());
        }
        int is_sent = send(socket, &message, strlen(message), 0);
        if (is_sent == -1) {
            cout<<"time out"<<endl;
            close(socket);
            return -10;
        }
        line.clear();
        solution.clear();
        buffer_string.clear();
        memset(&(message[0]),0,1024);
        buffer[0]='0';

        getline(str_stream, line, '\n');
        std::string chars_line = "\r\n";
        for (char c:chars) {
            line.erase(std::remove(line.begin(), line.end(), c), line.end());
        }
    }
    close(socket);
}