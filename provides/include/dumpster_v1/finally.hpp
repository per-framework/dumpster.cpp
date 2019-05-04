#pragma once

#include "dumpster_v1/synopsis.hpp"

#include <utility>

template <class Action> struct dumpster_v1::finally_t {
  ~finally_t() { m_action(); }

  template <class ForwardableAction>
  finally_t(ForwardableAction &&action)
      : m_action(std::forward<ForwardableAction>(action)) {}

  finally_t(const finally_t &) = delete;
  finally_t operator=(const finally_t &) = delete;

private:
  std::conditional_t<std::is_function_v<Action>, Action *, Action> m_action;
};

template <class Action>
dumpster_v1::finally_t<std::remove_cvref_t<Action>>
dumpster_v1::finally(Action &&action) {
  return finally_t<std::remove_cvref_t<Action>>(std::forward<Action>(action));
}
