#pragma once

#include "utils/core.hpp"
#include "linear_base.hpp"

namespace math
{
    struct vector: public linear_base<vector>
    {
        vector();
        vector(const num4 &entries);
        vector(num x, num y, num z);
    };

} // namespace math
