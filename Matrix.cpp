//
// Created by noa on 19/01/2020.
//

#include "Matrix.h"

bool Matrix::isPointValid(pair<int, int> point) {
  int x = point.first;
  int y = point.second;
  return (x < size && x >=0) && (y < size && y >= 0);
}

pair<int, int> Matrix::getInitialState() {
  return this->source;
}

bool Matrix::isGoalState(pair<int, int> state) {
  return this->destination.first == state.first && this->destination.second == state.second;
}

list<pair<int, int>> Matrix::getAllPossibleStates(pair<int, int> state) {
  list<pair<int,int>> states;
  pair<int,int> temp, down, left, right, up_right, up_left, down_right, down_left;
  //up
  temp = make_pair(state.first - 1, state.second);
  if (isPointValid(temp) && !isBlocked(temp)) {
    states.push_back(temp);
  }
  //down
  temp = make_pair(state.first + 1, state.second);
  if (isPointValid(temp) && !isBlocked(temp)) {
    states.push_back(temp);
  }
  //right
  temp = make_pair(state.first, state.second + 1);
  if (isPointValid(temp) && !isBlocked(temp)) {
    states.push_back(temp);
  }
  //left
  temp = make_pair(state.first, state.second - 1);
  if (isPointValid(temp) && !isBlocked(temp)) {
    states.push_back(temp);
  }
  return states;
}
void Matrix::setPoint(pair<int, int> point, int value) {
  this->mat[point.first][point.second] = value;
}

void Matrix::addBlockedPoint(pair<int, int> point) {
  this->blocked.insert(point);
}

bool Matrix::isBlocked(pair<int, int> point) {
  return (this->blocked.find(point) != this->blocked.end());
}

int Matrix::getSize() {
  return this->size;
}

pair<int,int> Matrix::getGoal() {
  return this->destination;
}

int Matrix::getValueOfPoint(pair<int, int> point) {
  return this->mat[point.first][point.second];
}

void Matrix::setHashNum(size_t hn) {
  this->hash_num = hn;
}

string Matrix::toString() {
  return to_string(this->hash_num);
}