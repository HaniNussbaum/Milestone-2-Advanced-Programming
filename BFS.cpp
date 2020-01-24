//
// Created by hani on 23/01/2020.
//

#include <iostream>
#include "BFS.h"

std::string BFS::search(Searchable<pair<int,int>> *a_matrix) {
    this->matrix=a_matrix;
    this->initialState = a_matrix->getInitialState();
    this->goalState = a_matrix->getGoal();
    pathAndPoint initialStatePoint = make_pair(initialState, make_pair(0, initialState));
    this->open.push_back(initialStatePoint);
    this->closed.insert(initialStatePoint);
    while (!open.empty()) {
        pathAndPoint s = open.front();
        open.pop_front();
        if (s.first.first == goalState.first && s.first.second == goalState.second) {
            return backtrace(s.first);
        }
        std::list<point> neighbors = successors(s.first);

        for (point p : neighbors) {
            parent_map[p] = s.first;
            int pointFirst = p.first;
            int pointSecond = p.second;

            pathAndPoint p_path_and_point = make_pair(p,
                                                      make_pair(s.second.first + matrix->getValueOfPoint(p),
                                                                s.first));
            auto closedFind = std::find_if(closed.begin(), closed.end(),
                                           [pointFirst, pointSecond](const pathAndPoint &pap) {
                                               return (pap.first.first == pointFirst &&
                                                       pap.first.second == pointSecond);
                                           });
            if (closedFind == closed.end()) {

                closed.insert(p_path_and_point);
                open.push_back(p_path_and_point);
            }

        }
    }
//    return backtrace(this->goalState);
}

std::string BFS::backtrace(point a_point) {
  string point_str;
  pair<int,int> parent = this->parent_map[a_point];
  if (parent.first > a_point.first) {
    point_str = "Up, ";
  } else if (parent.first < a_point.first) {
    point_str = "Down, ";
  } else if (parent.second > a_point.second) {
    point_str = "Left, ";
  } else {
    point_str = "Right, ";
  }

  if (a_point.first==this->initialState.first&&a_point.second==this->initialState.second) {
    return "";
  }
  else {
    return backtrace(this->parent_map[a_point]) + point_str;
    }
}
