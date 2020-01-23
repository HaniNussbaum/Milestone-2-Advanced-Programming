//
// Created by noa on 23/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__SEARCHER_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__SEARCHER_H_
#include "Searchable.h"

template <typename T>
class Searcher {
  virtual T search(Searchable<T> s) = 0;
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__SEARCHER_H_
