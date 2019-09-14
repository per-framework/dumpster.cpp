#pragma once

#include "dumpster_v1/synopsis.hpp"

template <class UnsignedType, class>
UnsignedType dumpster_v1::prime_less_than_next_pow_2_or_1(UnsignedType x) {
  if constexpr (sizeof(UnsignedType) <= sizeof(uint32_t))
    return static_cast<UnsignedType>(
        prime_less_than_next_pow_2_or_1(static_cast<uint32_t>(x)));
  else
    return static_cast<UnsignedType>(
        prime_less_than_next_pow_2_or_1(static_cast<uint64_t>(x)));
}
