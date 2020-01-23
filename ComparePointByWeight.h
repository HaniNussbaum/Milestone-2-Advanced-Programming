//
// Created by hani on 21/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_COMPAREPOINTBYWEIGHT_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_COMPAREPOINTBYWEIGHT_H

#include <utility>
typedef std::pair<int,int> point;
typedef std::pair<point,std::pair<int,point>> pathAndPoint;

class ComparePointByWeight {
public:
    bool operator()(pathAndPoint first, pathAndPoint second) {
        return first.second.first>second.first.second;
    }
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING_COMPAREPOINTBYWEIGHT_H
