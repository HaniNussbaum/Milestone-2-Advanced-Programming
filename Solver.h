//
// Created by noa on 15/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__SOLVER_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__SOLVER_H_
template <typename  P>
template <typename  S>

class Solver<P,S> {
  virtual S solve(P problem) = 0;
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__SOLVER_H_
