#include "dumpster_v1/primes.hpp"

// Using de Bruijn Sequences to Index a 1 in a Computer Word
// by Leiserson, Prokop, and Randall

uint32_t dumpster_v1::prime_less_than_next_pow_2_or_1(uint32_t x) {
  alignas(32) static const uint8_t delta[] = {
      0x0000000000000001 - 0x0000000000000001, //  0
      0x00000000000003ff - 0x00000000000003fd, //  9
      0x0000000000000003 - 0x0000000000000003, //  1
      0x00000000000007ff - 0x00000000000007f7, // 10
      0x0000000000003fff - 0x0000000000003ffd, // 13
      0x00000000003fffff - 0x00000000003ffffd, // 21
      0x0000000000000007 - 0x0000000000000007, //  2
      0x000000003fffffff - 0x000000003fffffdd, // 29
      0x0000000000000fff - 0x0000000000000ffd, // 11
      0x0000000000007fff - 0x0000000000007fed, // 14
      0x000000000001ffff - 0x000000000001ffff, // 16
      0x000000000007ffff - 0x000000000007ffff, // 18
      0x00000000007fffff - 0x00000000007ffff1, // 22
      0x0000000003ffffff - 0x0000000003fffffb, // 25
      0x000000000000000f - 0x000000000000000d, //  3
      0x000000007fffffff - 0x000000007fffffff, // 30
      0x00000000000001ff - 0x00000000000001fd, //  8
      0x0000000000001fff - 0x0000000000001fff, // 12
      0x00000000001fffff - 0x00000000001ffff7, // 20
      0x000000001fffffff - 0x000000001ffffffd, // 28
      0x000000000000ffff - 0x000000000000fff1, // 15
      0x000000000003ffff - 0x000000000003fffb, // 17
      0x0000000001ffffff - 0x0000000001ffffd9, // 24
      0x00000000000000ff - 0x00000000000000fb, //  7
      0x00000000000fffff - 0x00000000000ffffd, // 19
      0x000000000fffffff - 0x000000000fffffc7, // 27
      0x0000000000ffffff - 0x0000000000fffffd, // 23
      0x000000000000007f - 0x000000000000007f, //  6
      0x0000000007ffffff - 0x0000000007ffffd9, // 26
      0x000000000000003f - 0x000000000000003d, //  5
      0x000000000000001f - 0x000000000000001f, //  4
      0x00000000ffffffff - 0x00000000fffffffb, // 31
  };

  static_assert(sizeof(delta) == 32);

  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;

  return x - delta[x * 0x07c4acdd >> (32 - 5)];
}

uint64_t dumpster_v1::prime_less_than_next_pow_2_or_1(uint64_t x) {
  alignas(64) static const uint8_t delta[] = {
      0x0000000000000001 - 0x0000000000000001, //  0
      0x0000000000000fff - 0x0000000000000ffd, // 11
      0x0000000000000003 - 0x0000000000000003, //  1
      0x0000000000001fff - 0x0000000000001fff, // 12
      0x000000000001ffff - 0x000000000001ffff, // 16
      0x000000003fffffff - 0x000000003fffffdd, // 29
      0x0000000000000007 - 0x0000000000000007, //  2
      0x0000000000003fff - 0x0000000000003ffd, // 13
      0x00000000007fffff - 0x00000000007ffff1, // 22
      0x000000000003ffff - 0x000000000003fffb, // 17
      0x000003ffffffffff - 0x000003fffffffff5, // 41
      0x0000000003ffffff - 0x0000000003fffffb, // 25
      0x000000007fffffff - 0x000000007fffffff, // 30
      0x0001ffffffffffff - 0x0001ffffffffffaf, // 48
      0x000000000000000f - 0x000000000000000d, //  3
      0x3fffffffffffffff - 0x3fffffffffffffc7, // 61
      0x0000000000007fff - 0x0000000000007fed, // 14
      0x00000000001fffff - 0x00000000001ffff7, // 20
      0x0000000000ffffff - 0x0000000000fffffd, // 23
      0x000000000007ffff - 0x000000000007ffff, // 18
      0x00000007ffffffff - 0x00000007ffffffe1, // 34
      0x0000001fffffffff - 0x0000001fffffffe7, // 36
      0x000007ffffffffff - 0x000007ffffffffc7, // 42
      0x0000000007ffffff - 0x0000000007ffffd9, // 26
      0x0000007fffffffff - 0x0000007ffffffff9, // 38
      0x00000000ffffffff - 0x00000000fffffffb, // 31
      0x003fffffffffffff - 0x003fffffffffffdf, // 53
      0x00001fffffffffff - 0x00001fffffffffc9, // 44
      0x0003ffffffffffff - 0x0003ffffffffffe5, // 49
      0x01ffffffffffffff - 0x01fffffffffffff3, // 56
      0x000000000000001f - 0x000000000000001f, //  4
      0x7fffffffffffffff - 0x7fffffffffffffe7, // 62
      0x00000000000007ff - 0x00000000000007f7, // 10
      0x000000000000ffff - 0x000000000000fff1, // 15
      0x000000001fffffff - 0x000000001ffffffd, // 28
      0x00000000003fffff - 0x00000000003ffffd, // 21
      0x000001ffffffffff - 0x000001ffffffffeb, // 40
      0x0000000001ffffff - 0x0000000001ffffd9, // 24
      0x0000ffffffffffff - 0x0000ffffffffffc5, // 47
      0x1fffffffffffffff - 0x1fffffffffffffff, // 60
      0x00000000000fffff - 0x00000000000ffffd, // 19
      0x00000003ffffffff - 0x00000003ffffffd7, // 33
      0x0000000fffffffff - 0x0000000ffffffffb, // 35
      0x0000003fffffffff - 0x0000003fffffffd3, // 37
      0x001fffffffffffff - 0x001fffffffffff91, // 52
      0x00000fffffffffff - 0x00000fffffffffef, // 43
      0x00ffffffffffffff - 0x00fffffffffffffb, // 55
      0x00000000000003ff - 0x00000000000003fd, //  9
      0x000000000fffffff - 0x000000000fffffc7, // 27
      0x000000ffffffffff - 0x000000ffffffffa9, // 39
      0x00007fffffffffff - 0x00007fffffffff8d, // 46
      0x0fffffffffffffff - 0x0fffffffffffffa3, // 59
      0x00000001ffffffff - 0x00000001fffffff7, // 32
      0x000fffffffffffff - 0x000fffffffffffd1, // 51
      0x007fffffffffffff - 0x007fffffffffffc9, // 54
      0x00000000000001ff - 0x00000000000001fd, //  8
      0x00003fffffffffff - 0x00003fffffffffeb, // 45
      0x07ffffffffffffff - 0x07ffffffffffffc9, // 58
      0x0007ffffffffffff - 0x0007ffffffffff7f, // 50
      0x00000000000000ff - 0x00000000000000fb, //  7
      0x03ffffffffffffff - 0x03ffffffffffffe5, // 57
      0x000000000000007f - 0x000000000000007f, //  6
      0x000000000000003f - 0x000000000000003d, //  5
      0xffffffffffffffff - 0xffffffffffffffc5, // 63
  };

  static_assert(sizeof(delta) == 64);

  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  x |= x >> 32;

  return x - delta[x * 0x03f08a4c6acb9dbd >> (64 - 6)];
}
