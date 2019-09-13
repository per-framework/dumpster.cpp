#include <cinttypes>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <vector>

//

static uint64_t bit(int i) { return static_cast<uint64_t>(1) << i; }

static uint64_t bits(int n) { return bit(n) * 2 - 1; }

//

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

static std::vector<uint64_t> primes_less_than_pow_2(int m) {
  std::vector<uint64_t> results;
  results.reserve(64);
  results.push_back(1);
  for (int i = 1; i < m; ++i) {
    uint64_t n = bits(i);
    while (!is_prime(n))
      n -= 2;
    results.push_back(n);
  }
  return results;
}

//

static void print_table(int n_bits,
                        int keep_bits,
                        std::vector<uint64_t> table,
                        uint64_t de_bruijn_sequence) {
  struct entry {
    int i;
    uint64_t n;
    uint64_t v;
  };

  std::vector<entry> reindexed;
  reindexed.resize(n_bits);

  for (int i = 0; i < n_bits; ++i) {
    uint64_t n = bits(i);
    int j = static_cast<int>((n * de_bruijn_sequence >> (n_bits - keep_bits)) &
                             bits(keep_bits - 1));
    uint64_t v = table[i];
    reindexed[j] = entry{i, n, v};
  }

  for (const auto &e : reindexed)
    fprintf(
        stdout, "0x%016" PRIx64 " - 0x%016" PRIx64 ", // %2d\n", e.n, e.v, e.i);
}

int main() {
  auto primes = primes_less_than_pow_2(64);

  print_table(32, 5, primes, 0x07c4acdd);
  fprintf(stdout, "\n");
  print_table(64, 6, primes, 0x03f08a4c6acb9dbd);

  return 0;
}
