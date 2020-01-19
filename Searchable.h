//
// Created by noa on 19/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__SEARCHABLE_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__SEARCHABLE_H_
#include <list>
using namespace std;
template <typename  T>
class Searchable {
 public:
  virtual T getInitialState() = 0;
  virtual bool isGoalState(T state) = 0;
  virtual list<T> getAllPossibleStates(T state) = 0;
 private:
  list<T> possibleStates;
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__SEARCHABLE_H_
