//
// Created by noa on 15/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__CLIENTHANDLER_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__CLIENTHANDLER_H_

class ClientHandler {
 public:
  virtual int handleClient(int socket) = 0;
};
#endif //MILESTONE_2_ADVANCED_PROGRAMMING__CLIENTHANDLER_H_
