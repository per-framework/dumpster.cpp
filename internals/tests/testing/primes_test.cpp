#include "dumpster_v1/primes.hpp"

#include "testing_v1/test.hpp"

using namespace testing_v1;

#define VERIFY_IS_PRIME_OR_1 0

#if VERIFY_IS_PRIME_OR_1
#include <cmath>

static bool is_prime(uint64_t n) {
  if (n <= 3)
    return n > 1;
  else if (n % 2 == 0 || n % 3 == 0)
    return false;
  else
    for (uint64_t i = 5, m = static_cast<uint64_t>(sqrt(n) + 1); i <= m; i += 6)
      if (n % i == 0 || n % (i + 2) == 0)
        return false;
  return true;
}
#endif

template <class T> static void test() {
  for (int i = 0; i < static_cast<int>(sizeof(T) * 8); ++i) {
    T n = static_cast<T>(1) << i;
    T p = dumpster_v1::prime_less_than_next_pow_2_or_1(n);
#if VERIFY_IS_PRIME_OR_1
    verify(1 == p || is_prime(p));
#endif
    verify(n <= p && p <= n * 2 - 1);
  }
}

auto primes_test = test([]() {
  test<uint32_t>();
  test<uint64_t>();
});
