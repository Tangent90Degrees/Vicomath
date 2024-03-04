#pragma once

#include "../utils/core.hpp"
#include "../linear/linear_base.hpp"

namespace math {

    /// @brief The vector type.
    struct vector : public linear_base<vector, 4> {

        typedef linear_base::num_vec num_vec;

        /// @brief The default constructor.
        vector();

        /// @brief Constructs a vector by specified vec.
        vector(const num_vec &entries);

        /// @brief Constructs a vector by x, y, and z vec.
        vector(num x, num y, num z);

        friend INLINE num dot(const vector &left, const vector &right);

        friend INLINE num sqr_magnitude(const vector &v);
        friend INLINE num magnitude(const vector &v);
        friend INLINE vector normalized(const vector &v);
    };

} // namespace math
