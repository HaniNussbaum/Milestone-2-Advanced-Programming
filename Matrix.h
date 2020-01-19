//
// Created by noa on 19/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__MATRIX_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__MATRIX_H_
#include "Searchable.h"
#include <unordered_set>

class Matrix : public Searchable<pair<int,int>> {
  pair<int,int> source, destination;
  int size;
  int** mat;
  unordered_set<pair<int,int>> blocked;
 public:
  Matrix(pair<int,int> src, pair<int,int> dst, int n) {
    this->source = src;
    this->destination = dst;
    this->size = n;
    this->mat = new int*[n];
    for(int i = 0; i < n; ++i) {
      mat[i] = new int[n];
    }
  }
  void setPoint(pair<int,int> point, int value);
  void addBlockedPoint(pair<int,int> point);
  bool isPointValid(pair<int,int> point);
  bool isBlocked(pair<int,int> point);
  pair<int,int> getInitialState();
  bool isGoalState(pair<int,int> state);
  list<pair<int,int>> getAllPossibleStates(pair<int,int> state);
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__MATRIX_H_
