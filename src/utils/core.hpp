#pragma once

#include <algorithm>
#include <cmath>

#define INLINE __attribute__((__always_inline__))
#define VEC_TYPE(x) __attribute__((ext_vector_type(x)))
#define MAT_TYPE(x, y) __attribute__((matrix_type(x, y)))

namespace math {
    typedef double num;

    template <size_t N>
    concept is_power_of_2 = !(N & (N - 1));

    static constexpr const num ZERO = static_cast<num>(0);
    static constexpr const num ONE = static_cast<num>(1);
    static constexpr const num PI = static_cast<num>(M_PI);
} // namespace math
