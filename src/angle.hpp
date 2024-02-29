#pragma once

#include "utils/core.hpp"

namespace math
{
    union angle
    {
    private:
        union degree_type
        {
            operator num() const;
            degree_type &operator=(num degree);

        private:
            num radius;
        };

    public:
        num radius;
        degree_type degree;

        angle();
        angle(num radius);
    };

} // namespace math