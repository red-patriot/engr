#ifndef ENGR_LIB_METRIC_PREFIX_H
#define ENGR_LIB_METRIC_PREFIX_H

#include "../units/SIBase.h"

namespace engr {
  template <SIDimension Dim>
  inline SIUnit<Dim> giga(const SIUnit<Dim> input) noexcept {
    return input * 1'000'000'000;
  }

  template <SIDimension Dim>
  inline SIUnit<Dim> mega(const SIUnit<Dim> input) noexcept {
    return input * 1'000'000;
  }

  template <SIDimension Dim>
  inline SIUnit<Dim> kilo(const SIUnit<Dim> input) noexcept {
    return input * 1'000;
  }

  template <SIDimension Dim>
  inline SIUnit<Dim> milli(const SIUnit<Dim> input) noexcept {
    return input * 0.001;
  }

  template <SIDimension Dim>
  inline SIUnit<Dim> micro(const SIUnit<Dim> input) noexcept {
    return input * 0.000'001;
  }

  template <SIDimension Dim>
  inline SIUnit<Dim> nano(const SIUnit<Dim> input) noexcept {
    return input * 0.000'000'001;
  }
}  // namespace engr

#endif
