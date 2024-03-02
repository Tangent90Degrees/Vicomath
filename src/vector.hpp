#pragma once

#include "utils/core.hpp"
#include "linear/linear_base.hpp"

namespace math {

    /// @brief The vector type.
    struct vector : public linear_base<vector, 4> {

        typedef linear_base::num_vec num_vec;

        /// @brief The default constructor.
        vector();

        /// @brief Constructs a vector by specified entries.
        vector(const num_vec &entries);

        /// @brief Constructs a vector by x, y, and z entries.
        vector(num x, num y, num z);
    };

} // namespace math
