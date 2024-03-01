#pragma once

#include "utils/core.hpp"
#include "linear_base.hpp"

namespace math {

    /// @brief The vector type.
    struct vector : public linear_base<vector, 4> {

        /// @brief The default constructor.
        vector();

        /// @brief Constructs a vector by specified entries.
        vector(const num4 &entries);

        /// @brief Constructs a vector by x, y, and z entries.
        vector(num x, num y, num z);
    };

} // namespace math
