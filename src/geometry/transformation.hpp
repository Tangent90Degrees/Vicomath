#pragma once

#include "../linear/matrix_base.hpp"
#include "vector.hpp"
#include "quaternion.hpp"

namespace math {

    struct transformation : matrix_base<transformation, vector, 4> {

        typedef matrix_base::num_mat num_mat;

        INLINE transformation();

        INLINE transformation(const num_mat &entries);

        INLINE transformation(const quaternion &stretching, const vector &shifting);

        INLINE transformation(
                num ww, num wx, num wy, num wz,
                num xw, num xx, num xy, num xz,
                num yw, num yx, num yy, num yz,
                num zw, num zx, num zy, num zz
        );

    };

}
