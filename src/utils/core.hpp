#pragma once

#include <algorithm>
#include <cmath>

#define INLINE __attribute__((__always_inline__))
#define VEC_TYPE(x) __attribute__((ext_vector_type(x)))

namespace math {
    typedef double num;

    template <size_t N>
    concept is_power_of_2 = !(N & (N - 1));

    static constexpr const num PI = static_cast<num>(M_PI);
} // namespace math
