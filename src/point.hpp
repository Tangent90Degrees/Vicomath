#pragma once

#include "linear/affine_linear_base.hpp"
#include "vector.hpp"

namespace math {

    struct point : affine_linear_base<point, vector, 4> {

        typedef affine_linear_base::num_vec num_vec;

        /// @brief The default constructor.
        point();

        /// @brief Constructs a point by specified entries.
        point(const num_vec &entries);

        /// @brief Constructs a point by x, y, and z entries.
        point(num x, num y, num z);

    };

} // math
