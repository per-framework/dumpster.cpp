#pragma once

#include "dumpster_v1/synopsis.hpp"

#include <utility>

template <class Action>
dumpster_v1::Private::finalizer<Action>::~finalizer<Action>() {
  m_action();
}

template <class Action>
template <class ForwardableAction>
dumpster_v1::Private::finalizer<Action>::finalizer(ForwardableAction &&action)
    : m_action(std::forward<ForwardableAction>(action)) {}

template <class Action> dumpster_v1::finalizer<Action>::~finalizer<Action>() {}

template <class Action>
template <class ForwardableAction>
dumpster_v1::finalizer<Action>::finalizer(ForwardableAction &&action)
    : Private::finalizer<Action>(std::forward<ForwardableAction>(action)) {}

template <class Action>
dumpster_v1::finalizer<std::decay_t<Action>>
dumpster_v1::finally(Action &&action) {
  return finalizer<std::decay_t<Action>>(std::forward<Action>(action));
}

template <class Action>
std::optional<dumpster_v1::finalizer<std::decay_t<Action>>>
dumpster_v1::finally_with_reset(Action &&action) {
  return std::optional<finalizer<std::decay_t<Action>>>(
      std::forward<Action>(action));
}
