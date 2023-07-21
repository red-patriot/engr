#ifndef ENGR_LIB_SYSTEMS_LOAD_H
#define ENGR_LIB_SYSTEMS_LOAD_H

#include <Eigen/Core>

#include <units/UnitTypes.h>
#include <units/Vector.h>

namespace engr {
  namespace detail {
    class UnknownDirectionT { };
    class UnknownForceT {
     public:
      UnknownForceT(Eigen::Vector3d direction,
                    engr::Vector3<Length::unit> position);
    };
  }  // namespace detail

  static constexpr detail::UnknownDirectionT unknownDirection;

  class Load {
    friend Load unknownForce(detail::UnknownDirectionT unknownDir,
                             engr::Vector3<Length::unit> position);
    friend Load unknownForce(Eigen::Vector3d knownDir,
                             engr::Vector3<Length::unit> position);

   public:
    engr::Vector3<Force::unit> force() const noexcept;

   private:
    Load(const detail::UnknownForceT& loadParams);
  };

  Load unknownForce(detail::UnknownDirectionT unknownDir,
                    Eigen::Vector<Length, 3> position);
  Load unknownForce(Eigen::Vector3d knownDir,
                    Eigen::Vector<Length, 3> position);

}  // namespace engr

#endif
