#include "coordinate.hpp"

namespace math {

    coordinate::coordinate(point origin, quaternion rotation)
            : origin(origin), rotation(rotation) {
    }

    vector coordinate::coordinate_vec(num x, num y, num z) const {
        return rotation(vector(x, y, z));
    }

    point coordinate::coordinate_point(num x, num y, num z) const {
        return origin + coordinate_vec(x, y, z);
    }

}