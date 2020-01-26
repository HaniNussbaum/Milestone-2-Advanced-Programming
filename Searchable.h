//
// Created by noa on 19/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__SEARCHABLE_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__SEARCHABLE_H_
#include <list>
using namespace std;
template <typename  T>
//This class represents a problem that is searchable, and all the methods need to be implemented by a searchable.
class Searchable {
 public:
  virtual T getInitialState() = 0;
  virtual bool isGoalState(T state) = 0;
  virtual list<T> getAllPossibleStates(T state) = 0;
  virtual T getGoal() = 0;
  virtual string toString() = 0;
  virtual void setHashNum(size_t hn) = 0;
  virtual int getSize() = 0;
  virtual int getValueOfPoint(T point) = 0;
 private:
  list<T> possibleStates;
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__SEARCHABLE_H_
