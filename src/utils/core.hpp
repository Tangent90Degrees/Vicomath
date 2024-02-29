#pragma once

#include <algorithm>
#include <math.h>

namespace math
{
    typedef double num;
    typedef num num4 __attribute__((ext_vector_type(4)));

    enum index
    {
        W = 0,
        X = 1,
        Y = 2,
        Z = 3
    };

    static constexpr const num PI = static_cast<num>(M_PI);

} // namespace math
