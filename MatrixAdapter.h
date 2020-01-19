//
// Created by noa on 19/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__MATRIXADAPTER_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__MATRIXADAPTER_H_
#include "Matrix.h"
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

class MatrixAdapter {
  pair<int,int> getPoint(string point);
 public:
  Matrix* adapt(string mat_str);
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__MATRIXADAPTER_H_
