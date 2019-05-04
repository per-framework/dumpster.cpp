#pragma once

#include "polyfill_v1/type_traits.hpp"

namespace dumpster_v1 {

// finally.hpp =================================================================

/// Finalizer that invokes stored action when destroyed.
template <class Action> struct finally_t;

/// Creates a finalizer that invokes the action when destroyed.
template <class Action>
finally_t<std::remove_cvref_t<Action>> finally(Action &&action);

// insertion_sort.hpp ==========================================================

/// Sorts given sentinel terminated sequence to ascending order.  Intended for
/// use cases where sequences are expected to be short, and low overhead and
/// small code size are desired.
template <class RandomIt, class Less, class IsSentinel>
void insertion_sort(RandomIt values, Less less, IsSentinel is_sentinel);

} // namespace dumpster_v1
