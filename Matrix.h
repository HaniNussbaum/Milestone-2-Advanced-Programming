//
// Created by noa on 19/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__MATRIX_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__MATRIX_H_

#include <unordered_set>
#include "Searchable.h"
#include "PairHash.h"

using namespace std;

class Matrix : public Searchable<pair<int, int>> {
    pair<int, int> source, destination;
    int size;
    int **mat;
    unordered_set<pair<int, int>, pair_hash> blocked;
    size_t hash_num;
public:
    Matrix(pair<int, int> src, pair<int, int> dst, int n) {
        this->source = src;
        this->destination = dst;
        this->size = n;
        this->mat = new int *[n];
        for (int i = 0; i < n; ++i) {
            mat[i] = new int[n];
        }
    }

    void setPoint(pair<int, int> point, int value);

    void addBlockedPoint(pair<int, int> point);

    bool isPointValid(pair<int, int> point);

    bool isBlocked(pair<int, int> point);

    pair<int, int> getInitialState();

    bool isGoalState(pair<int, int> state);

    list<pair<int, int>> getAllPossibleStates(pair<int, int> state);

    int getSize();

    pair<int, int> getGoal();

    int getValueOfPoint(pair<int, int> point);

    void setHashNum(size_t hn);

    string toString();

    //only for testing
    void setMat(int arr[][10]) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (arr[i][j] == -1) {
                    this->addBlockedPoint(make_pair(i, j));
                } else {
                    this->mat[i][j] = arr[i][j];
                }
            }
        }
    }
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__MATRIX_H_
