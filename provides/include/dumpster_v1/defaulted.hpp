#pragma once

#include "dumpster_v1/synopsis.hpp"

#include <utility>

template <class Value, auto... defaults>
dumpster_v1::defaulted<Value, defaults...>::defaulted() : value(defaults...) {}

template <class Value, auto... defaults>
template <class... Arguments>
dumpster_v1::defaulted<Value, defaults...>::defaulted(Arguments &&... arguments)
    : value(std::forward<Arguments>(arguments)...) {}

template <class Value, auto... defaults>
dumpster_v1::defaulted<Value, defaults...>::operator const Value &() const {
  return value;
}

template <class Value, auto... defaults>
dumpster_v1::defaulted<Value, defaults...>::operator Value &() {
  return value;
}
