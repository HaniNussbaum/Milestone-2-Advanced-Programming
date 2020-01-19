//
// Created by hani on 19/01/2020.
//

#include "StringReverser.h"
#include <algorithm>

std::string StringReverser::solve(std::string problem) {
    std::string str = problem;
    reverse(str.begin(), str.end());
    return str;
}