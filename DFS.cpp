//
// Created by hani on 23/01/2020.
//

#include "DFS.h"

std::string DFS::search(Searchable<pair<int,int>> *a_matrix) {
    this->matrix=a_matrix;
    this->initialState = a_matrix->getInitialState();
    this->goalState = a_matrix->getGoal();
    pathAndPoint initialStatePoint = make_pair(initialState, make_pair(0, initialState));
    open.push_front(initialStatePoint);
    //the start of the algorithm after adding the initialState node to the queue.
    while (!open.empty()){
        pathAndPoint s = open.front();
        open.pop_front();
        if (s.first.first == goalState.first && s.first.second == goalState.second) {
            return backtrace(s.first);
        }
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
        //marks the node as visited by adding it to closed.
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
                parent_map_track[p_path_and_point.first]=p_path_and_point.second.first;
                open.push_front(p_path_and_point);
            }
        }

    }
    return "";
}

std::string DFS::backtrace(point a_point) {
    //Returns a string of the path by tracing the goal node back to the original.
    string point_str;
    pair<int,int> parent = this->parent_map[a_point];
    if (parent.first > a_point.first) {
        point_str = "Up("+to_string(parent_map_track[a_point])+"), ";
    } else if (parent.first < a_point.first) {
        point_str = "Down("+to_string(parent_map_track[a_point])+"), ";
    } else if (parent.second > a_point.second) {
        point_str = "Left("+to_string(parent_map_track[a_point])+"), ";
    } else {
        point_str = "Right("+to_string(parent_map_track[a_point])+"), ";
    }

    if (a_point.first==this->initialState.first&&a_point.second==this->initialState.second) {
        return "";
    }
    else {
        return backtrace(this->parent_map[a_point]) + point_str;
    }
}
