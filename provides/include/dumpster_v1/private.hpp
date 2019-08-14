#pragma once

#include "polyfill_v1/type_traits.hpp"

namespace dumpster_v1 {

template <class Value> struct finally_t;

class Private {
  template <class> friend struct finally_t;

  template <class Value> class finally_t;
};

} // namespace dumpster_v1

template <class Action> class dumpster_v1::Private::finally_t {
  template <class> friend struct dumpster_v1::finally_t;

  ~finally_t();

  template <class ForwardableAction> finally_t(ForwardableAction &&action);

  std::conditional_t<std::is_function_v<Action>, Action *, Action> m_action;
};
