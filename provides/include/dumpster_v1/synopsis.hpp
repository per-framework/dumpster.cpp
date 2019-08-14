#pragma once

#include "dumpster_v1/private.hpp"

namespace dumpster_v1 {

// finally.hpp =================================================================

/// Finalizer that invokes stored action when destroyed.
template <class Action> struct finally_t : Private::finally_t<Action> {
  /// Calls the finalizing action given to the constructor.
  ~finally_t();

  /// Constructs a finalizer from the given finalizing action.
  template <class ForwardableAction> finally_t(ForwardableAction &&action);

  /// Finalizers are not CopyConstructible.
  finally_t(const finally_t &) = delete;

  /// Finalizers are not CopyAssignable.
  finally_t &operator=(const finally_t &) = delete;
};

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
