#pragma once

#include "polyfill_v1/type_traits.hpp"

namespace dumpster_v1 {

template <class Value> struct finalizer;

class Private {
  template <class> friend struct finalizer;

  template <class Value> class finalizer;
};

} // namespace dumpster_v1

template <class Action> class dumpster_v1::Private::finalizer {
  template <class> friend struct dumpster_v1::finalizer;

  ~finalizer();

  template <class ForwardableAction> finalizer(ForwardableAction &&action);

  Action m_action;
};
