#include "dumpster_v1/finally.hpp"

#include "testing_v1/test.hpp"

using namespace testing_v1;

static bool s_finalized = false;
static void s_function() { s_finalized = true; }

auto finally_function_test = test([]() {
  bool executed = false;

  {
    auto finalizer = dumpster_v1::finally(s_function);
    executed = !s_finalized;
  }

  verify(s_finalized);
  verify(executed);
});
