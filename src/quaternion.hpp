#pragma once

#include "utils/core.hpp"
#include "angle.hpp"
#include "linear_base.hpp"

namespace math {
    struct quaternion : public linear_base<quaternion> {

        quaternion();

        quaternion(const num4 &entries);

        quaternion(num w, num x, num y, num z);

        friend quaternion operator*(const quaternion &left, const quaternion &right);
    };

} // namespace math
