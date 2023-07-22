#ifndef ENGR_LIB_VECTORS_H
#define ENGR_LIB_VECTORS_H

#include <initializer_list>
#include <algorithm>

#include <Eigen/Core>

#include "SIBase.h"
#include "SIDimension.h"

namespace engr {
  template <SIDimension Dim, size_t N>
  class Vector {
   public:
    using Scalar = SIUnit<Dim>;

    static constexpr SIDimension unit = Dim;

    Scalar x() const { return Scalar(elements_.x()); }
    Scalar y() const { return Scalar(elements_.y()); }
    Scalar z() const { return Scalar(elements_.z()); }

    size_t size() const noexcept { return N; }

   private:
    Eigen::Vector<double, N> elements_;
  };

  template <SIDimension Dim>
  using Vector3 = Vector<Dim, 3>;
}  // namespace engr

#endif
