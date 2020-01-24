//
// Created by hani on 23/01/2020.
//
#include "MatrixSolver.h"

std::string MatrixSolver::solve(std::string problem) {
    return this->searcher->search(this->adapter->adapt(problem));
}

string MatrixSolver::getSearcherClassName() {
  return this->searcher->getClassName();
}

void MatrixSolver::setProblem(string problem){
  this->matrix = this->adapter->adapt(problem);
}