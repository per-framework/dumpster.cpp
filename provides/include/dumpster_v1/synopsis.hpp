#pragma once

#include "polyfill_v1/type_traits.hpp"

namespace dumpster_v1 {

// finally.hpp -----------------------------------------------------------------

template <class Action> struct finally_t;

template <class Action>
finally_t<std::remove_cvref_t<Action>> finally(Action &&action);

// insertion-sort.hpp ----------------------------------------------------------

template <class RandomIt, class Less, class IsSentinel>
void insertion_sort(RandomIt values, Less less, IsSentinel is_sentinel);

} // namespace dumpster_v1
