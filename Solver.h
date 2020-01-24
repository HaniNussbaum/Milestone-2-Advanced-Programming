//
// Created by noa on 15/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__SOLVER_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__SOLVER_H_
#include <string>
#include "Searcher.h"
template <typename  P, typename S>

class Solver {
public:
  virtual S solve(P problem) = 0;
  virtual std::string getSearcherClassName() = 0;
  virtual void setSearcher(Searcher<std::string,pair<int,int>> *a_searcher)=0;
  virtual void setProblem(P problem) = 0;
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__SOLVER_H_
