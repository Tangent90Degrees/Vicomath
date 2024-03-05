#pragma once

#include "../utils/core.hpp"
#include "../angle.hpp"
#include "../linear/linear_base.hpp"

namespace math {
    struct quaternion : public linear_base<quaternion, 4> {

        quaternion();

        quaternion(const linear_base::num_vec &entries);

        quaternion(num w, num x, num y, num z);

        friend INLINE quaternion operator*(const quaternion &left, const quaternion &right);
    };

    INLINE quaternion conj(const quaternion &q);

    INLINE quaternion inverse(const quaternion &q);

    INLINE num sqr_magnitude(const quaternion &q);
    INLINE num magnitude(const quaternion &q);
    INLINE quaternion normalized(const quaternion &q);

} // namespace math
