#include "dumpster_v1/finally.hpp"

#include "testing_v1/test.hpp"

using namespace testing_v1;

auto finally_lambda_test = test([]() {
  bool finalized = false;
  bool executed = false;

  {
    auto finalizer = dumpster_v1::finally([&]() { finalized = true; });
    executed = true;
  }

  verify(finalized);
  verify(executed);
});

static bool s_finalized = false;
static void s_function() { s_finalized = true; }

auto finally_function_test = test([]() {
  bool executed = false;

  {
    auto finalizer = dumpster_v1::finally(s_function);
    executed = true;
  }

  verify(s_finalized);
  verify(executed);
});
