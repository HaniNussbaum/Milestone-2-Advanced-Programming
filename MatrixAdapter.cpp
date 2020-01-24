//
// Created by noa on 19/01/2020.
//

#include "MatrixAdapter.h"

Matrix* MatrixAdapter::adapt(string mat_str) {
  vector<string> lines;
  stringstream str_stream(mat_str);
  string line;
  //breaking string into lines
  while (getline(str_stream, line, '\n')) {
    line = line.substr(0, line.length() - 1);
    lines.push_back(line);
    line.clear();
  }
  //last line is destination
  auto dst = this->getPoint(lines.back());
  lines.pop_back();
  //now last line is source
  auto src = this->getPoint(lines.back());
  lines.pop_back();
  Matrix* matrix = new Matrix(src, dst, lines.size());
  hash<string> str_hash;
  matrix->setHashNum(str_hash(mat_str));
  //filling the matrix
  int j = 0, k = 0;
  for (string row : lines) {
    regex pattern("[0-9-]+");
    auto words_begin = sregex_iterator(row.begin(), row.end(), pattern);
    auto words_end = sregex_iterator();
    k = 0;
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
      smatch match = *i;
      int value = stoi(match.str());
      if (value == -1) {
        matrix->addBlockedPoint(make_pair(j, k));
      } else {
        matrix->setPoint(make_pair(j, k), value);
      }
      k++;
    }
    j++;
  }
  return matrix;
}

pair<int,int> MatrixAdapter::getPoint(string point) {
  regex pattern("[0-9-]+");
  auto words_begin = sregex_iterator(point.begin(), point.end(), pattern);
  auto words_end = sregex_iterator();
  sregex_iterator i = words_begin;
  smatch match = *i;
  int x = stoi(match.str());
  i++;
  match = *i;
  int y = stoi(match.str());
  return make_pair(x, y);
}