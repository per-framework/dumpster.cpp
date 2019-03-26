#include "dumpster_v1/insertion_sort.hpp"

#include "testing_v1/test.hpp"

using namespace testing_v1;

auto insertion_sort_test = test([]() {
  int values[] = {3, 1, 4, 1, 5, 9, 2, -1};

  dumpster_v1::insertion_sort(
      values, [](auto lhs, auto rhs) { return lhs < rhs; },
      [](auto x) { return x == -1; });

  int sorted[] = {1, 1, 2, 3, 4, 5, 9, -1};

  for (size_t i = 0; i < sizeof(sorted) / sizeof(*sorted); ++i)
    verify(values[i] == sorted[i]);
});
