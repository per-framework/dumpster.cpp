#include "dumpster_v1/finally.hpp"

#include "testing_v1/test.hpp"

using namespace testing_v1;

auto finally_with_reset_test = test([]() {
  int finalized = 0;

  {
    auto finalizer = dumpster_v1::finally_with_reset([&]() { ++finalized; });
    finalizer.reset();
  }

  {
    auto finalizer = dumpster_v1::finally_with_reset([&]() { ++finalized; });
  }

  verify(2 == finalized);
});
