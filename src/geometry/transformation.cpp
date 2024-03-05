#include "transformation.hpp"

namespace math {

    transformation::transformation() = default;

    transformation::transformation(const transformation::num_mat &entries) : matrix_base(entries) {
    }

    transformation::transformation(const quaternion &stretching, const vector &shifting) {
    }

    transformation::transformation(
            num ww, num wx, num wy, num wz,
            num xw, num xx, num xy, num xz,
            num yw, num yx, num yy, num yz,
            num zw, num zx, num zy, num zz
    ) : matrix_base(
            ww, wx, wy, wz,
            xw, xx, xy, xz,
            yw, yx, yy, yz,
            zw, zx, zy, zz
    ) {
    }
}