//
// Created by noa on 19/01/2020.
//

#include "Astar.h"


string Astar::search(Matrix* matrix) {
  stack<cell> stack;
  this->goal = matrix->getGoal();
  this->start = matrix->getInitialState();
  //initializing score array for the matrix, values are set to INT_MAX
  int n = matrix->getSize();
  cell_det** score_mat = new cell_det*[n];
  for(int i = 0; i < n; ++i) {
    score_mat[i] = new cell_det[n];
  }
  //initializing h field (manhattan distance from destination)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      score_mat[i][j].h = this->h_distance(make_pair(i, j));
    }
  }
  priority_queue<cell, vector<cell>, Compare> open;
  //inserting start into queue
  auto start_pair = this->start;
  cell_det* start_cell = &score_mat[start_pair.first][start_pair.second];
  start_cell->g = 0;
  start_cell->f = start_cell->h;
  open.push(make_pair(start_pair, start_cell));

  while (!open.empty()) {
    cell current = open.top();
    open.pop();
    current.second->closed = true;
    if (matrix->isGoalState(current.first)) {
      return this->reconstructPath(goal);
    }
    list<pair<int,int>> neighbors = matrix->getAllPossibleStates(current.first);
    pair<int,int> current_pair = current.first;
    for (auto neighbor : neighbors) {
      int temp_gScore = score_mat[current_pair.first][current_pair.second].g + matrix->getValueOfPoint(neighbor);
      //if the path to neighbor through current is better then the path it has now then keep it
      auto n_struct = &score_mat[neighbor.first][neighbor.second];
      if (n_struct->closed) {
        continue;
      }
      if (temp_gScore < n_struct->g) {
        this->parent_map[neighbor] = current_pair;
        n_struct->g = temp_gScore;
        n_struct->f = temp_gScore + n_struct->h;
        if (n_struct->visited) {
          //if the neighbor is already in open queue, find, remove it, and push again
          cell n_cell = open.top();
          while(n_cell.first != neighbor) {
            stack.push(n_cell);
            open.pop();
            n_cell = open.top();
          }
          open.pop();
          while (!stack.empty()) {
            open.push(stack.top());
            stack.pop();
          }
        }
        open.push(make_pair(neighbor, n_struct));
      }
    }
  }
}

int Astar::h_distance(pair<int, int> point) {
  return abs(point.first - this->goal.first) + abs(point.second + this->goal.second);
}

string Astar::reconstructPath(pair<int,int> point) {
  string point_str = to_string(point.first) + "," + to_string(point.second) + " ; ";
  if (point == this->start) {
    return point_str;
  }
  else {
    return reconstructPath(this->parent_map[point]) + point_str;
  }
}