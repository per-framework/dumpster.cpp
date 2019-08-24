#pragma once

#include "dumpster_v1/synopsis.hpp"

inline uint32_t dumpster_v1::ranqd1(uint32_t seed) {
  return seed * 1664525 + 1013904223;
}
