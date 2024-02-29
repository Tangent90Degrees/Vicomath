#include "vector.hpp"

namespace math
{
    vector::vector()
    {
    }

    vector::vector(const num4 &entries)
        : entries(entries)
    {
    }

    vector::vector(num x, num y, num z)
        : array{0, x, y, z}
    {
    }

    num vector::operator[](index off) const
    {
        return array[off];
    }

    num &vector::operator[](index off)
    {
        return array[off];
    }

} // namespace math
