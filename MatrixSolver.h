//
// Created by hani on 23/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_MATRIXSOLVER_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_MATRIXSOLVER_H

#include "Solver.h"
#include "Matrix.h"
#include "Searchable.h"
#include "MatrixAdapter.h"

class MatrixSolver : public Solver<std::string, std::string> {
private:
    Matrix *matrix;
    MatrixAdapter *adapter;
    Searcher<std::string,pair<int,int>> *searcher;
public:

    MatrixSolver* clone(){
        MatrixSolver* cloned = new MatrixSolver();
        cloned->setSearcher(this->searcher->clone());
        return cloned;

    }

    MatrixSolver() {
      this->adapter = new MatrixAdapter();
    }
    std::string solve(std::string problem);

    void setSearcher(Searcher<std::string,pair<int,int>> *a_searcher) {
        this->searcher = a_searcher;
    }

    void setProblem(string problem);

    string getSearcherClassName();
};


#endif //MILESTONE_2_ADVANCED_PROGRAMMING_MATRIXSOLVER_H
