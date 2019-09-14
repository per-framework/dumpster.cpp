#include "dumpster_v1/ranqd1.hpp"

#include "testing_v1/test.hpp"

using namespace testing_v1;
using namespace dumpster_v1;

auto ranqd1_test = test([]() {
  uint32_t seed = 0;
  verify((seed = ranqd1(seed)) == 0x3c6ef35f);
  verify((seed = ranqd1(seed)) == 0x47502932);
  verify((seed = ranqd1(seed)) == 0xd1ccf6e9);
  verify((seed = ranqd1(seed)) == 0xaaf95334);
  verify((seed = ranqd1(seed)) == 0x6252e503);
  verify((seed = ranqd1(seed)) == 0x9f2ec686);
  verify((seed = ranqd1(seed)) == 0x57fe6c2d);
  verify((seed = ranqd1(seed)) == 0xa3d95fa8);
  verify((seed = ranqd1(seed)) == 0x81fdbee7);
  verify((seed = ranqd1(seed)) == 0x94f0af1a);
  verify((seed = ranqd1(seed)) == 0xcbf633b1);
});
