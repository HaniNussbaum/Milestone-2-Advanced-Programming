//
// Created by hani on 23/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_MATRIXSOLVER_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_MATRIXSOLVER_H

#include "Solver.h"
#include "Matrix.h"
#include "Searchable.h"
#include "MatrixAdapter.h"

//This class is a solver for a specific searchable that is a Matrix.
//it can take a string that represents a matrix and translate it into a matrix object.
//It then calls the searcher to solve the problem.
class MatrixSolver : public Solver<std::string, std::string> {
private:
    Matrix *matrix;
    MatrixAdapter *adapter;
    Searcher<std::string, pair<int, int>> *searcher;
public:

    MatrixSolver *clone() {
        MatrixSolver *cloned = new MatrixSolver();
        cloned->setSearcher(this->searcher->clone());
        return cloned;

    }

    MatrixSolver() {
        this->adapter = new MatrixAdapter();
    }

    std::string solve(std::string problem);

    void setSearcher(Searcher<std::string, pair<int, int>> *a_searcher) {
        this->searcher = a_searcher;
    }

    void setProblem(string problem);

    string getSearcherClassName();
};


#endif //MILESTONE_2_ADVANCED_PROGRAMMING_MATRIXSOLVER_H
