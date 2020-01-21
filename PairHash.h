//
// Created by noa on 21/01/2020.
//

#ifndef MILESTONE_2_ADVANCED_PROGRAMMING__PAIRHASH_H_
#define MILESTONE_2_ADVANCED_PROGRAMMING__PAIRHASH_H_
#include <utility>
#include <functional>
using namespace std;

struct pair_hash
{
  template <class T1, class T2>
  std::size_t operator() (const std::pair<T1, T2> &pair) const
  {
    return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
  }
};

#endif //MILESTONE_2_ADVANCED_PROGRAMMING__PAIRHASH_H_
