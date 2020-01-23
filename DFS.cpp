//
// Created by hani on 23/01/2020.
//

#include "DFS.h"

std::string DFS::search() {
    pathAndPoint initialStatePoint = make_pair(initialState, make_pair(0, initialState));
    open.push_front(initialStatePoint);
    while (!open.empty()){
        pathAndPoint s = open.front();
        open.pop_front();
        int pointFirst = s.first.first;
        int pointSecond = s.first.second;
        auto closedFind = std::find_if(closed.begin(), closed.end(),
                                       [pointFirst, pointSecond](const pathAndPoint &pap) {
                                           return (pap.first.first == pointFirst &&
                                                   pap.first.second == pointSecond);
                                       });
        if (closedFind!=closed.end()){
            continue;
        }
        closed.insert(s);
        list<point> neighbors = successors(s.first);
        for (auto currPoint = neighbors.rbegin();currPoint!=neighbors.rend();++currPoint){
            pathAndPoint p_path_and_point = make_pair(*currPoint,
                                                      make_pair(s.second.first + matrix->getValueOfPoint(*currPoint), s.first));
            int pointFirst_curr = p_path_and_point.first.first;
            int pointSecond_curr = p_path_and_point.first.second;

            auto closedFind_neighbor = std::find_if(closed.begin(), closed.end(),
                                           [pointFirst_curr, pointSecond_curr](const pathAndPoint &pap) {
                                               return (pap.first.first == pointFirst_curr &&
                                                       pap.first.second == pointSecond_curr);
                                           });
            if (closedFind_neighbor==closed.end()){
                parent_map[p_path_and_point.first]=s.first;
                    open.push_front(p_path_and_point);
            }
        }

    }
    return backtrace(goalState);
}

std::string DFS::backtrace(point a_point) {
    string point_str = to_string(a_point.first) + "," + to_string(a_point.second) + " ; ";
    if (a_point.first == this->initialState.first && a_point.second == this->initialState.second) {
        return point_str;
    } else {
        return backtrace(this->parent_map[a_point]) + point_str;
    }
}
