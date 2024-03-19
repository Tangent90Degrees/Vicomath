#pragma once

#include "point.hpp"
#include "quaternion.hpp"

namespace math {

    struct coordinate {

        INLINE coordinate(point origin, quaternion rotation);

        [[nodiscard]] INLINE vector coordinate_vec(num x, num y, num z) const;
        [[nodiscard]] INLINE point coordinate_point(num x, num y, num z) const;

    private:
        point origin;
        quaternion rotation;
    };

}