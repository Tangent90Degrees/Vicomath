#pragma once

#include "../utils/core.hpp"
#include "../angle.hpp"
#include "vector.hpp"

namespace math {

    struct quaternion : public linear_base<quaternion, 4> {

        quaternion();

        quaternion(const linear_base::num_vec &entries);

        quaternion(num w, num x, num y, num z);

        INLINE vector operator()(const vector &v) const;

        friend INLINE quaternion operator*(const quaternion &left, const quaternion &right);

        static const quaternion ONE;
        static const quaternion ZERO;
    };

    INLINE quaternion conj(const quaternion &q);

    INLINE quaternion inverse(const quaternion &q);

    INLINE num sqr_magnitude(const quaternion &q);
    INLINE num magnitude(const quaternion &q);
    INLINE quaternion normalized(const quaternion &q);

} // namespace math
