//
// Created by hani on 19/01/2020.
//

#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "Matrix.h"
#include "BestFirstSearch.h"

int main() {

    int a_matrix[10][10] = {0, 0, 6, 7, 8, 9, 10, 11, 12, 13,
                            14, 0, 0, 7, 3, 4, 12, 76, 23, 45,
                            6, -1, 0, 0, 0, 32, 10, 23, 5, 2,
                            -1, 5, 2, 3, 0, 0, 6, 7, 8, 4,
                            2, 1, 2, 3, 4, 0, 0, 7, 4, 1,
                            23, 2, 10, -1, 3, 0, 0, 6, 1, 12,
                            13, 12, 0, 5, 2, 1, 0, 3, 4, 5,
                            1, 2, 123, 5, 2, 3, 0, 1, 2, 5,
                            3, 1, 2, 12, 5, 3, 0, 0, 0, 6,
                            3, 1, 2, -1, 5, 4, 3, 23, 0, 0};
//int a_matrix[3][3] = { 0,10,10,
//                       -1,15,10,
//                       0,20,0};
    Matrix *my_Matrix = new Matrix(make_pair(0, 0), make_pair(9, 9), 10);
    my_Matrix->setMat(a_matrix);
    BestFirstSearch *bfs = new BestFirstSearch(my_Matrix);
    bfs->search();

//    Solver<string, string> *mySolver = new StringReverser();
//    MySerialServer *myServer = new MySerialServer(5600, new MyTestClientHandler(mySolver));
//    myServer->open(5600);
}