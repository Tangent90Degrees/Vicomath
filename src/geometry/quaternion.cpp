#include "quaternion.hpp"

namespace math {

    quaternion::quaternion() = default;

    quaternion::quaternion(const linear_base::num_vec &entries) : linear_base(entries) {
    }

    quaternion::quaternion(num w, num x, num y, num z) : linear_base(w, x, y, z) {
    }

    INLINE quaternion operator*(const quaternion &left, const quaternion &right) {
        return {
                left[W] * right[W] - left[X] * right[X] - left[Y] * right[Y] - left[Z] * right[Z],
                left[W] * right[X] + left[X] * right[W] + left[Y] * right[Z] - left[Z] * right[Z],
                left[W] * right[Y] - left[X] * right[Z] + left[Y] * right[W] + left[Z] * right[Y],
                left[W] * right[Z] + left[X] * right[Y] - left[Y] * right[X] + left[Z] * right[X]
        };
    }

    vector quaternion::operator()(const vector &v) const {
        return (*this * v.vec_data() * conj(*this)).vec;
    }

    const quaternion quaternion::ONE = {1, 0, 0, 0};
    const quaternion quaternion::ZERO = {0, 0, 0, 0};

    INLINE quaternion conj(const quaternion &q) {
        return {q[W], -q[X], -q[Y], -q[Z]};
    }

    INLINE quaternion inverse(const quaternion &q) {
        return conj(q) / sqr_magnitude(q);
    }

    INLINE num sqr_magnitude(const quaternion &q) {
        return q[W] * q[W] + q[X] * q[X] + q[Y] * q[Y] + q[Z] * q[Z];
    }

    INLINE num magnitude(const quaternion &q) {
        return sqrt(sqr_magnitude(q));
    }

    INLINE quaternion normalized(const quaternion &q) {
        return q / magnitude(q);
    }

} // namespace math
