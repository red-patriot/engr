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
    Vector() = default;
    Vector(std::initializer_list<Scalar> elements);

    static constexpr SIDimension unit = Dim;

    Scalar x() const { return Scalar(elements_.x()); }
    Scalar y() const { return Scalar(elements_.y()); }
    Scalar z() const { return Scalar(elements_.z()); }

    Scalar operator[](size_t i) const {
      return Scalar(elements_[i]);
    }

    size_t size() const noexcept { return N; }

   private:
    Eigen::Vector<double, N> elements_;
  };

  template <SIDimension Dim>
  using Vector3 = Vector<Dim, 3>;

  template <SIDimension Dim, size_t N>
  inline Vector<Dim, N>::Vector(std::initializer_list<Scalar> elements) {
    std::transform(elements.begin(), elements.end(), elements_.data(),
                   [](const Scalar& s) {
                     return s.base();
                   });
  }
}  // namespace engr

namespace Eigen {
  template <engr::SIDimension Dim>
  struct NumTraits<engr::SIUnit<Dim>> {
    using Real = engr::SIUnit<Dim>;
    using NonInteger = engr::SIUnit<Dim>;
    using Nested = engr::SIUnit<Dim>;

    enum {
      IsComplex = 0,
      IsInteger = 0,
      IsSigned = 1,
      RequireInitialization = 0,
      ReadCost = 1,
      AddCost = 3,
      MulCost = 3
    };
  };
}  // namespace Eigen

#endif
