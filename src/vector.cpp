#include "vector.hpp"

namespace math {

    vector::vector() {
    }

    vector::vector(const num4 &entries)
            : linear_base(entries) {
    }

    vector::vector(num x, num y, num z)
            : linear_base(static_cast<num>(0), x, y, z) {
    }

} // namespace math
