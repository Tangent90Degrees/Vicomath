#include "angle.hpp"

namespace math {
    angle::degree_type::operator num() const {
        return radius * 180 / PI;
    }

    angle::degree_type &angle::degree_type::operator=(num degree) {
        radius = degree * PI / 180;
        return *this;
    }

    angle::angle() {
    }

    angle::angle(num radius)
            : radius(radius) {
    }

} // namespace math
