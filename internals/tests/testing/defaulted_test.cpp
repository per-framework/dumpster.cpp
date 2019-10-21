#include "dumpster_v1/defaulted.hpp"

#include "testing_v1/test.hpp"

using namespace testing_v1;

auto defaulted_test = test([]() {
  {
    dumpster_v1::defaulted<int, 42> x;
    verify(x.value == 42);
    x = 101;
    verify(x == 101);
  }
  {
    dumpster_v1::defaulted<short, 42> x(short(101));
    verify(x == 101);
  }
  {
    const dumpster_v1::zeroed<std::size_t> x;
    verify(x == 0);
  }
  {
    dumpster_v1::zeroed<char *> x;
    verify(x == nullptr);
  }
  {
    dumpster_v1::zeroed<uint8_t> x;
    dumpster_v1::zeroed<uint8_t> y = x;
    y += 1;
    x = y;
    x = 2 * y + 1;
    verify(3 == x);
  }
});
