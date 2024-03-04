#include "ray.hpp"

namespace math {

    INLINE ray::ray() = default;

    INLINE ray::ray(const point &origin, const vector &direction) : origin(origin), direction(direction) {
    }

    INLINE point ray::operator()(num t) const {
        return origin + t * direction;
    }

}