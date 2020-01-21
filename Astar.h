//
// Created by noa on 19/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__ASTAR_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__ASTAR_H_
#include <climits>
#include <queue>
#include <stack>
#include <unordered_map>
#include "Matrix.h"
#include "PairHash.h"

using namespace std;

class Astar {
  struct cell_det {
    cell_det() : g(INT_MAX), f(INT_MAX), h(INT_MAX), visited(false) {}
    int g, h, f;
    bool visited;
  };
  unordered_map<pair<int,int>, pair<int,int>, pair_hash> parent_map;
  pair<int,int> goal;
  pair<int,int> start;
  int h_distance(pair<int,int> point);
  string reconstructPath(pair<int,int> point);
 public:
  string search(Matrix* matrix);
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__ASTAR_H_
