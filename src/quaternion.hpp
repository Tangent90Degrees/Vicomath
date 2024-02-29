#pragma once

#include "utils/core.hpp"
#include "angle.hpp"

namespace math
{
    union quaternion
    {
        quaternion();
        quaternion(const num4 &entries);
        quaternion(num w, num x, num y, num z);

        num operator[](index off) const;
        num &operator[](index off);

        friend quaternion operator+(const quaternion &left, const quaternion &right);
        friend quaternion operator-(const quaternion &left, const quaternion &right);
        friend quaternion operator*(const quaternion &left, num right);
        friend quaternion operator*(num left, const quaternion &right);
        friend quaternion operator/(const quaternion &left, num right);

    private:
        num4 entries;
        num array[4];
    };

} // namespace math
