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
#include "Searcher.h"

using namespace std;

class Astar : public Searcher<string> {
  struct cell_det {
    cell_det() : g(INT_MAX), f(INT_MAX), h(INT_MAX), visited(false), closed(false) {}
    int g, h, f;
    bool visited;
    bool closed;
  };
  typedef pair<pair<int,int>,cell_det*> cell;
  class Compare {
   public:
    bool operator() (cell c1, cell c2) {
      return c1.second->f > c2.second->f;
    }
  };
  unordered_map<pair<int,int>, pair<int,int>, pair_hash> parent_map;
  pair<int,int> goal;
  pair<int,int> start;
  int h_distance(pair<int,int> point);
  string reconstructPath(pair<int,int> point);
 public:
    string getClassName(){
        return "Astar";
    }
  string search(Matrix* matrix);
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__ASTAR_H_
