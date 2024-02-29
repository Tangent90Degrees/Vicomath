#pragma once

#include "utils/core.hpp"

namespace math
{
    enum index
    {
        W = 0,
        X = 1,
        Y = 2,
        Z = 3
    };

    template <typename SELF>
    class linear_base
    {
        union
        {
            num4 entries;
            num array[4];
        };

    public:
        inline linear_base()
        {
        }

        inline linear_base(const num4 &entries)
            : entries(entries)
        {
        }

        inline linear_base(num w, num x, num y, num z)
            : array{w, x, y, z}
        {
        }

        inline num operator[](index off) const { return array[off]; }
        inline num &operator[](index off) { return array[off]; }

        template <typename _SELF>
        friend _SELF operator+(const linear_base<_SELF> &left, const linear_base<_SELF> &right);
    };

    template <typename SELF>
    inline SELF operator+(const linear_base<SELF> &left, const linear_base<SELF> &right)
    {
        return left.entries + right.entries;
    }

} // namespace math
