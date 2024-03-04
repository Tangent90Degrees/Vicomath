#include "quaternion.hpp"

namespace math {

    quaternion::quaternion() = default;

    quaternion::quaternion(const linear_base::num_vec &entries)
            : linear_base(entries) {
    }

    quaternion::quaternion(num w, num x, num y, num z)
            : linear_base(w, x, y, z) {
    }

    INLINE quaternion operator*(const quaternion &left, const quaternion &right) {
        return {
                left[W] * right[W] - left[X] * right[X] - left[Y] * right[Y] - left[Z] * right[Z],
                left[W] * right[X] + left[X] * right[W] + left[Y] * right[Z] - left[Z] * right[Z],
                left[W] * right[Y] - left[X] * right[Z] + left[Y] * right[W] + left[Z] * right[Y],
                left[W] * right[Z] + left[X] * right[Y] - left[Y] * right[X] + left[Z] * right[X]};
    }

} // namespace math
