//
// Created by hani on 23/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_BFS_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_BFS_H

#include <utility>
#include <map>
#include <set>
#include "Matrix.h"
#include <unordered_map>
#include <algorithm>
#include <queue>
#include "Searcher.h"

typedef std::pair<int, int> point;
typedef std::pair<point, std::pair<int, point>> pathAndPoint;


class BFS : public Searcher<string,pair<int,int>> {
public:
    std::string search(Searchable<pair<int,int>> *a_matrix);
    std::string getClassName(){
        return "BFS";
    }
    std::string backtrace(point);

    std::list<point> successors(point a_point) {
        std::list<point> successors;
        std::list<point> neighbors = matrix->getAllPossibleStates(a_point);
        for (point a_point: neighbors) {
            auto closedFind = std::find_if(closed.begin(), closed.end(), [a_point](const pathAndPoint &pap) {
                return (pap.first.first == a_point.first && pap.first.second == a_point.second);
            });
            if (closedFind == closed.end()) {
                successors.push_back(a_point);
            }
        }
        return successors;
    }


private:
    Searchable<pair<int,int>> *matrix;
    unordered_map<pair<int, int>, pair<int, int>, pair_hash> parent_map;
    unordered_map<pair<int,int>,int,pair_hash> parent_map_track;
    std::list<pathAndPoint> open;
    std::multiset<pathAndPoint> closed;
    point initialState;
    point goalState;

};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING_BFS_H
