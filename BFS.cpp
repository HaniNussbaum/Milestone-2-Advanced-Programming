//
// Created by hani on 23/01/2020.
//

#include <iostream>
#include "BFS.h"

std::string BFS::search(Searchable<pair<int, int>> *a_matrix) {
    this->matrix = a_matrix;
    this->initialState = a_matrix->getInitialState();
    this->goalState = a_matrix->getGoal();
    pathAndPoint initialStatePoint = make_pair(initialState, make_pair(0, initialState));
    this->open.push_back(initialStatePoint);
    this->closed.insert(initialStatePoint);
    //the start of the algorithm, after the initalState node was foudn.
    while (!open.empty()) {
        pathAndPoint s = open.front();
        open.pop_front();
        if (s.first.first == goalState.first && s.first.second == goalState.second) {
            return backtrace(s.first);
        }
        std::list<point> neighbors = successors(s.first);
        //processes the neighbors
        for (point p : neighbors) {
            parent_map[p] = s.first;
            int pointFirst = p.first;
            int pointSecond = p.second;

            pathAndPoint p_path_and_point = make_pair(p,
                                                      make_pair(s.second.first + matrix->getValueOfPoint(p),
                                                                s.first));
            parent_map_track[p_path_and_point.first] = p_path_and_point.second.first;
            auto closedFind = std::find_if(closed.begin(), closed.end(),
                                           [pointFirst, pointSecond](const pathAndPoint &pap) {
                                               return (pap.first.first == pointFirst &&
                                                       pap.first.second == pointSecond);
                                           });
            if (closedFind == closed.end()) {
                //marks the node as visited by adding it to closed.
                closed.insert(p_path_and_point);
                open.push_back(p_path_and_point);
            }

        }
    }
    return "";
}

std::string BFS::backtrace(point a_point) {
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
        this->parent_map.clear();
        this->parent_map_track.clear();
        this->closed.clear();
        this->open.clear();
        return "";

    } else {
        return backtrace(this->parent_map[a_point]) + point_str;
    }
}
