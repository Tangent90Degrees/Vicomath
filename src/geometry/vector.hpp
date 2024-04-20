#pragma once

#include "../linear/linear_base.hpp"

namespace math
{

    /// @brief A type that describes coordinates as a 3-dimensional vector.
    struct vector : public linear_base<vector, 4>
    {
        typedef linear_base::num_vec num_vec;

        /// @brief The default constructor.
        vector();

        /// @brief Constructs a vector by specified vec.
        vector(const num_vec &entries);

        /// @brief Constructs a vector by x, y, and z vec.
        vector(num x, num y, num z);

        static const vector ZERO;
        static const vector FRONT;
        static const vector BACK;

        static vector random(num min, num max);
        static vector random_in_sphere(num radius);
        static vector random_on_shell(num radius);
        static vector random_on_hemisphere(const vector &normal);
    };

    /// @brief Gets the scalar product of two vectors.
    INLINE num dot(const vector &left, const vector &right);

    INLINE num sqr_magnitude(const vector &v);

    INLINE num magnitude(const vector &v);

    INLINE vector normalized(const vector &v);

} // namespace math
