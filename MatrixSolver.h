//
// Created by hani on 23/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_MATRIXSOLVER_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_MATRIXSOLVER_H

#include "Solver.h"
#include "Matrix.h"
#include "Searchable.h"
#include "MatrixAdapter.h"
#include "Searcher.h"

class MatrixSolver : public Solver<std::string, std::string> {
private:
    Matrix *matrix;
    MatrixAdapter *adapter;
    Searcher<std::string> *searcher;
public:
    std::string solve(std::string problem);

    void setSearcher(Searcher<std::string> *a_searcher) {
        this->searcher = a_searcher;
    }

    string getSearcherClassName();
};


#endif //MILESTONE_2_ADVANCED_PROGRAMMING_MATRIXSOLVER_H
