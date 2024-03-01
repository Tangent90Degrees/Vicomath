#pragma once

#include <algorithm>
#include <cmath>

namespace math {
    typedef double num;
    typedef num num4 __attribute__((ext_vector_type(4)));

    inline constexpr bool is_power_of_2(size_t x) noexcept {
        return !(x & (x - 1));
    }

    template <size_t N>
    concept power_of_2 = is_power_of_2(N);

    static constexpr const num PI = static_cast<num>(M_PI);
} // namespace math
