#include "dumpster_v1/finally.hpp"

#include "testing_v1/test.hpp"

using namespace testing_v1;

auto finally_test = test([]() {
  bool finalized = false;
  bool executed = false;

  {
    auto finalizer = dumpster_v1::finally([&]() { finalized = true; });
    executed = true;
  }

  verify(finalized);
  verify(executed);
});
