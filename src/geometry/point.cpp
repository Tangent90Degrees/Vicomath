#include "point.hpp"

namespace math {

    point::point() = default;

    point::point(const num_vec &entries) : affine_linear_base(entries) {
    }

    point::point(num x, num y, num z) : affine_linear_base(static_cast<num>(1), x, y, z) {
    }
}
