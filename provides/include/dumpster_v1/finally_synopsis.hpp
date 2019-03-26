#pragma once

#include "polyfill_v1/type_traits.hpp"

namespace dumpster_v1 {

template <class Action> struct finally_t;

template <class Action>
finally_t<std::remove_cvref_t<Action>> finally(Action &&action);

} // namespace dumpster_v1
