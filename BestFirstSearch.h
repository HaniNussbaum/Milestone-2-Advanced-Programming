//
// Created by hani on 21/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING_BESTFIRSTSEARCH_H
#define MILESTONE_2_ADVANCED_PROGRAMMING_BESTFIRSTSEARCH_H

#include <string>
#include "Matrix.h"
#include <queue>
#include "ComparePointByWeight.h"
#include <set>
#include <unordered_map>
#include <algorithm>
#include "Searcher.h"
#include "Searchable.h"

typedef std::pair<int, int> point;
typedef std::pair<point, std::pair<int, point>> pathAndPoint;

class BestFirstSearch : public Searcher<string,pair<int,int>> {
public:
    std::string getClassName() {
        return "BestFirstSearch";
    }
    BestFirstSearch* clone(){
        BestFirstSearch *cloned = new BestFirstSearch();
        return cloned;
    }
    std::string search(Searchable<pair<int,int>> *s);

    std::string backtrace(point);
    //checks the results of AllPossibleStates and returns a list of neighbors that haven't been processed yet.
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
    //custom comparator that compares the path by the cost of it.
    struct compare {
        bool operator()(const pathAndPoint first_point, const pathAndPoint second_point) const {
            return first_point.second.first < second_point.second.first;
        }
    };

    unordered_map<pair<int, int>, pair<int, int>, pair_hash> parent_map;
    unordered_map<pair<int,int>,int,pair_hash> parent_map_track;
    std::multiset<pathAndPoint, compare> open;
    std::multiset<pathAndPoint> closed;
    point initialState;
    point goalState;
    Searchable<pair<int,int>> *matrix;


};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING_BESTFIRSTSEARCH_H
