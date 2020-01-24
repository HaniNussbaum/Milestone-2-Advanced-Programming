//
// Created by noa on 23/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__SEARCHER_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__SEARCHER_H_
#include "Searchable.h"

template <typename T, typename P>
class Searcher {
 public:
  virtual T search(Searchable<P>* s) = 0;
  virtual string getClassName() = 0;
  virtual Searcher<T,P> *clone()=0;
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__SEARCHER_H_
