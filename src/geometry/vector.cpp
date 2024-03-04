#include "vector.hpp"

namespace math {

    vector::vector() = default;

    vector::vector(const num_vec &entries)
            : linear_base(entries) {
    }

    vector::vector(num x, num y, num z)
            : linear_base(static_cast<num>(0), x, y, z) {
    }

    INLINE num dot(const vector &left, const vector &right) {
        return left[X] * right[X] + left[Y] * right[Y] + left[Z] * right[Z];
    }

    INLINE num sqr_magnitude(const vector &v) {
        return v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z];
    }

    INLINE num magnitude(const vector &v) {
        return sqrt(sqr_magnitude(v));
    }

    INLINE vector normalized(const vector &v) {
        return v / magnitude(v);
    }

} // namespace math
