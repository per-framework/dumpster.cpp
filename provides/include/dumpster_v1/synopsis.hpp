#pragma once

#include <cstdint>

#include "dumpster_v1/private.hpp"

namespace dumpster_v1 {

// defaulted.hpp ===============================================================

// Default initializes a value with the given arguments.
template <class Value, auto... defaults> struct defaulted {
  /// Default constructor initializes value with the defaults given as template
  /// arguments.
  defaulted();

  /// Non-default constructor initializes value with given arguments.
  template <class... Arguments> defaulted(Arguments &&... arguments);

  /// Implicit conversion to const reference for convenience.
  operator const Value &() const;

  /// Implicit conversion to reference for convenience.
  operator Value &();

  /// Assigns given `rhs` to `value` member.
  template <class Forwardable> Value &operator=(Forwardable &&rhs);

  /// The value is directly accessible as there is no reason to hide it.
  Value value;
};

// Zero initializes a value of the given type.
template <class Value> using zeroed = defaulted<Value, static_cast<Value>(0)>;

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

// primes.hpp ==================================================================

/// Returns the largest prime that is less than the given value rounded to the
/// next power of 2 or 1.
uint32_t prime_less_than_next_pow_2_or_1(uint32_t x);

/// Returns the largest prime that is less than the given value rounded to the
/// next power of 2 or 1.
uint64_t prime_less_than_next_pow_2_or_1(uint64_t x);

/// Returns the largest prime that is less than the given value rounded to the
/// next power of 2 or 1.
template <class UnsignedType,
          class = std::enable_if_t<(std::is_unsigned_v<UnsignedType> &&
                                    sizeof(UnsignedType) <= sizeof(uint64_t))>>
UnsignedType prime_less_than_next_pow_2_or_1(UnsignedType x);

// ranqd1.hpp ==================================================================

/// The `ranqd1` generator from Numerical Recipes in C, 2nd Edition.
uint32_t ranqd1(uint32_t seed);

} // namespace dumpster_v1
