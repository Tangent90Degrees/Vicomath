#pragma once

#include "core.hpp"

namespace math
{
    struct interval
    {
        INLINE interval(num min, num max);

        INLINE bool contains(num value) const;

        readonly_field<num, interval> min;
        readonly_field<num, interval> max;

        static const interval UNIVERSE;
    };

    INLINE bool operator==(const interval& left, const interval& right);
    INLINE bool operator!=(const interval& left, const interval& right);

    /// @brief 
    /// @param left 
    /// @param right 
    /// @return The union of the two intervals.
    INLINE interval operator+(const interval& left, const interval& right);

    /// @brief 
    /// @param left 
    /// @param right 
    /// @return The intersection of the two intervals.
    INLINE interval operator*(const interval& left, const interval& right);
}