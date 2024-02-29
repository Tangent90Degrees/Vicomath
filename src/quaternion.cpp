#include "quaternion.hpp"

namespace math
{
    quaternion::quaternion()
    {
    }

    quaternion::quaternion(const num4 &entries)
        : entries(entries)
    {
    }

    quaternion::quaternion(num w, num x, num y, num z)
        : array{w, x, y, z}
    {
    }

    num quaternion::operator[](index off) const
    {
        return array[off];
    }

    num &quaternion::operator[](index off)
    {
        return array[off];
    }

    quaternion operator+(const quaternion &left, const quaternion &right)
    {
        return left.entries + right.entries;
    }

    quaternion operator-(const quaternion &left, const quaternion &right)
    {
        return left.entries - right.entries;
    }

    quaternion operator*(const quaternion &left, num right)
    {
        return left.entries * right;
    }

    quaternion operator*(num left, const quaternion &right)
    {
        return left * right.entries;
    }

    quaternion operator/(const quaternion &left, num right)
    {
        return left.entries * (1 / right);
    }

} // namespace math
