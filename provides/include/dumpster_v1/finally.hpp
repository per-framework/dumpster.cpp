#pragma once

#include "dumpster_v1/synopsis.hpp"

#include <utility>

template <class Action> dumpster_v1::Private::finally_t<Action>::~finally_t() {
  m_action();
}

template <class Action>
template <class ForwardableAction>
dumpster_v1::Private::finally_t<Action>::finally_t(ForwardableAction &&action)
    : m_action(std::forward<ForwardableAction>(action)) {}

template <class Action> dumpster_v1::finally_t<Action>::~finally_t() {}

template <class Action>
template <class ForwardableAction>
dumpster_v1::finally_t<Action>::finally_t(ForwardableAction &&action)
    : Private::finally_t<Action>(std::forward<ForwardableAction>(action)) {}

template <class Action>
dumpster_v1::finally_t<std::remove_cvref_t<Action>>
dumpster_v1::finally(Action &&action) {
  return finally_t<std::remove_cvref_t<Action>>(std::forward<Action>(action));
}
