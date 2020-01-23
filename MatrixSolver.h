//
// Created by hani on 23/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_MATRIXSOLVER_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_MATRIXSOLVER_H

#include "Solver.h"
#include "Matrix.h"
#include "Searchable.h"
#include "MatrixAdapter.h"

class MatrixSolver : public Solver<std::string,std::string>{
private:
    Matrix *matrix;
    MatrixAdapter *adapter;
    Searcher searcher;
public:
    std::string solve(std::string problem) {
    }



};


#endif //MILESTONE_2_ADVANCED_PROGRAMMING_MATRIXSOLVER_H
