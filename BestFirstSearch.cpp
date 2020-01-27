//
// Created by hani on 21/01/2020.
//

#include "BestFirstSearch.h"
#include <algorithm>
#include <iostream>

std::string BestFirstSearch::search(Searchable<pair<int, int>> *a_matrix) {
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
    this->matrix = a_matrix;
    this->initialState = a_matrix->getInitialState();
    this->goalState = a_matrix->getGoal();
    pathAndPoint initialStatePoint = make_pair(initialState,
                                               make_pair(matrix->getValueOfPoint(initialState), initialState));
    this->open.insert(initialStatePoint);
    parent_map_track[initialState] = matrix->getValueOfPoint(initialState);
    //The start of the algorithm, after the initialNode was added to the queue.
    while (!open.empty()) {
        pathAndPoint n = make_pair(open.begin()->first, open.begin()->second);
        closed.insert(n);
        open.erase(open.begin());
        if (n.first.first == goalState.first && n.first.second == goalState.second) {
            return backtrace(n.first);
        } else {
            list<point> neighbours = successors(n.first);
            //proccess the neighbors and find if there is a shorter path through them.
            for (point p : neighbours) {
                int pointFirst = p.first;
                int pointSecond = p.second;
                auto itOpen = std::find_if(open.begin(), open.end(), MyClassComp(p));
                auto itClosed = std::find_if(closed.begin(), closed.end(), MyClassComp(p));
                pathAndPoint p_path_and_point = make_pair(p, make_pair(n.second.first + matrix->getValueOfPoint(p),
                                                                       n.first));
                if (itOpen == open.end() && itClosed == closed.end()) {
                    open.insert(p_path_and_point);
                    parent_map[p] = n.first;
                    parent_map_track[p] = p_path_and_point.second.first;
                } else {
                    //checks if the new path is shorter.
                    if (itClosed->second.first > p_path_and_point.second.first) {
                        if (itOpen == open.end()) {
                            open.insert(p_path_and_point);
                            parent_map[p] = n.first;
                            parent_map_track[p] = p_path_and_point.second.first;
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
                                parent_map_track[p] = p_path_and_point.second.first;
                            }
                        }
                    }
                }
            }
        }
    }
}

std::string BestFirstSearch::backtrace(point a_point) {
    //Returns a string of the path by tracing the goal node back to the original.
    string point_str;
    pair<int, int> parent = this->parent_map[a_point];
    if (parent.first > a_point.first) {
        point_str = "Up(" + to_string(parent_map_track[a_point]) + "), ";
    } else if (parent.first < a_point.first) {
        point_str = "Down(" + to_string(parent_map_track[a_point]) + "), ";
    } else if (parent.second > a_point.second) {
        point_str = "Left(" + to_string(parent_map_track[a_point]) + "), ";
    } else {
        point_str = "Right(" + to_string(parent_map_track[a_point]) + "), ";
    }

    if (a_point.first == this->initialState.first && a_point.second == this->initialState.second) {
        return "";
    } else {
        return backtrace(this->parent_map[a_point]) + point_str;
    }
}
