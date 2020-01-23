//
// Created by hani on 19/01/2020.
//

#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "Matrix.h"
#include "Astar.h"
#include "Searcher.h"

int main() {

    int a_matrix[10][10] = {0, 0, 6, 7, 8, 9, 10, 11, 12, 13,
                            14, 0, 0, 7, 3, 4, 12, 0, 0, 0,
                            6, -1, 0, 0, 0, 0, 0, 0, 5, 0,
                            -1, 5, 2, 3, 0, 0, 6, 7, 8, 0,
                            2, 1, 2, 3, 4, 0, 0, 7, 4, 0,
                            23, 2, 10, -1, 3, 0, 0, 0, 0, 12,
                            13, 12, 0, 5, 2, 1, 0, 3, 4, 5,
                            1, 2, 123, 5, 2, 3, 0, 1, 2, 5,
                            3, 1, 2, 12, 5, 3, 0, 0, 0, 6,
                            3, 1, 2, -1, 5, 4, 3, 23, 0, 0};

    Searcher<pair<int,int>> *my_Matrix = new Matrix(make_pair(0, 0), make_pair(9, 9), 10);
    my_Matrix->setMat(a_matrix);
    Searcher<string>* searcher;
    string solution = seracher->search(my_Matrix);
    CacheManager<string>* cache_manager = new CacheManager<string>(1000);
    cache_manager->insert(my_Matrix->toString() + "_" +  searcher->getClassName(), solution);
}