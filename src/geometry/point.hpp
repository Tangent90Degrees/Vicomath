#pragma once

#include "../linear/affine_linear_base.hpp"
#include "vector.hpp"

namespace math
{

    /// @brief A structure that describes coordinates as a point in 3-dimensional space.
    struct point : public affine_linear_base<point, vector, 4>
    {

        typedef affine_linear_base::num_vec num_vec;

        /// @brief The default constructor.
        point();

        /// @brief Constructs a point by specified vector.
        point(const num_vec &entries);

        /// @brief Constructs a point by x, y, and z.
        point(num x, num y, num z);

        static const point ZERO;
    };

} // math
