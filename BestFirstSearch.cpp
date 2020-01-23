//
// Created by hani on 21/01/2020.
//

#include "BestFirstSearch.h"
#include <algorithm>
#include <iostream>

std::string BestFirstSearch::search() {
    struct MyClassComp {
        explicit MyClassComp(point a_point) {
            point_to_find = a_point;
        };
        inline bool operator()(const pathAndPoint &pap) const {
            return pap.first.first == point_to_find.first && pap.first.second == point_to_find.second;
        }
    private:
        point point_to_find;
    };
    while (!open.empty()) {
        pathAndPoint n = make_pair(open.begin()->first, open.begin()->second);
        closed.insert(n);
        int check_first = n.first.first;
        int checl_second = n.first.second;
        open.erase(open.begin());
        if (n.first.first == goalState.first && n.first.second == goalState.second) {
            cout<< backtrace(n.first)<<endl;
            return backtrace(n.first);
        } else {
            list<point> neighbours = successors(n.first);
            for (point p : neighbours) {
                int pointFirst = p.first;
                int pointSecond = p.second;
                auto itOpen = std::find_if(open.begin(), open.end(), MyClassComp(p));
                auto itClosed = std::find_if(closed.begin(), closed.end(), MyClassComp(p));
                pathAndPoint p_path_and_point = make_pair(p, make_pair(n.second.first + matrix->getValueOfPoint(p),n.first));
                if (itOpen == open.end() && itClosed == closed.end()) {
                    open.insert(p_path_and_point);
                    parent_map[p] = n.first;
                } else {
                    if (itClosed->second.first > p_path_and_point.second.first) {
                        if (itOpen == open.end()) {
                            open.insert(p_path_and_point);
                            parent_map[p] = n.first;
                        } else {
                            auto openFind = std::find_if(open.begin(), open.end(),
                                                         [pointFirst, pointSecond](const pathAndPoint &pap) {
                                                             return (pap.first.first == pointFirst &&
                                                                     pap.first.second == pointSecond);
                                                         });
                            if (openFind != open.end()) {
                                open.erase(openFind);
                                open.insert(p_path_and_point);
                                parent_map[p] = n.first;
                            }
                        }
                    }
                }
            }
        }
    }
}

std::string BestFirstSearch::backtrace(point a_point) {
    string point_str = to_string(a_point.first) + "," + to_string(a_point.second) + " ; ";
    if (a_point.first == this->initialState.first && a_point.second == this->initialState.second) {
        return point_str;
    } else {
        return  backtrace(this->parent_map[a_point])+ point_str;
    }
}
