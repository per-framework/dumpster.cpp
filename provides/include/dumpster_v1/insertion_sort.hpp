#pragma once

#include "dumpster_v1/insertion_sort_synopsis.hpp"

#include <cstddef>

template <class RandomIt, class Less, class IsSentinel>
void dumpster_v1::insertion_sort(RandomIt values, Less less,
                                 IsSentinel is_sentinel) {
  size_t i = 0;
  while (!is_sentinel(values[++i])) {
    auto elem = values[i];
    size_t j = i;
    while (0 < j && less(elem, values[j - 1])) {
      values[j] = values[j - 1];
      j = j - 1;
    }
    if (i != j)
      values[j] = elem;
  }
}
