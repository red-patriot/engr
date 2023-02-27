#ifndef ENGR_LIB_METRIC_PREFIX_H
#define ENGR_LIB_METRIC_PREFIX_H

#include "../units/SIBase.h"

namespace eng {
  template <SIDimension Dim>
  SIUnit<Dim> giga(const SIUnit<Dim> input) noexcept {
    return input * 1'000'000'000;
  }

  template <SIDimension Dim>
  SIUnit<Dim> mega(const SIUnit<Dim> input) noexcept {
    return input * 1'000'000;
  }

  template <SIDimension Dim>
  SIUnit<Dim> kilo(const SIUnit<Dim> input) noexcept {
    return input * 1'000;
  }

  template <SIDimension Dim>
  SIUnit<Dim> milli(const SIUnit<Dim> input) noexcept {
    return input * 0.001;
  }

  template <SIDimension Dim>
  SIUnit<Dim> micro(const SIUnit<Dim> input) noexcept {
    return input * 0.000'001;
  }

  template <SIDimension Dim>
  SIUnit<Dim> nano(const SIUnit<Dim> input) noexcept {
    return input * 0.000'000'001;
  }
}  // namespace eng

#endif
