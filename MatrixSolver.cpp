//
// Created by hani on 23/01/2020.
//
#include "MatrixSolver.h"

std::string MatrixSolver::solve(std::string problem) {
    return this->searcher.search(problem);
}

string MatrixSolver::getSearcherClassName() {
  return this->searcher->getClassName();
}