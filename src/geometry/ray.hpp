#pragma once

#include "point.hpp"

namespace math {

    struct ray {

        INLINE ray();

        INLINE ray(const point &origin, const vector &direction);

        point origin;
        vector direction;

        INLINE point operator()(num t) const;
    };

}
