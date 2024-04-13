#pragma once

#include <algorithm>
#include <memory>
#include <cmath>
#include <optional>

/// @brief Forces compiler to make the function inline.
#define INLINE __attribute__((__always_inline__))

/// @brief Vector of number type parameters.
#define VEC_TYPE(x) __attribute__((ext_vector_type(x)))

/// @brief Matrix of number type parameters.
#define MAT_TYPE(x, y) __attribute__((matrix_type(x, y)))

namespace math
{
    
    /// @brief Floating-point type represents float or double.
    typedef float num;

    /// @brief If an unsigned integer is power of 2.
    template <size_t N>
    concept is_power_of_2 = !(N & (N - 1));

    /// @brief Floating-point value of 0.
    static constexpr const num ZERO = static_cast<num>(0);

    /// @brief Floating-point value of 1.
    static constexpr const num ONE = static_cast<num>(1);

    /// @brief Floating-point value of Pi.
    static constexpr const num PI = static_cast<num>(M_PI);

} // namespace math
