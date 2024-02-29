#pragma once

#include "utils/core.hpp"

namespace math
{
    union vector
    {
        vector();
        vector(const num4 &entries);
        vector(num x, num y, num z);

        num operator[](index off) const;
        num &operator[](index off);

    private:
        num4 entries;
        num array[4];
    };

} // namespace math
