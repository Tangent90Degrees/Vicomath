#include "interval.hpp"

namespace math
{
    interval::interval(num min, num max)
        : min(max < min ? INFTY : min), max(max < min ? -INFTY : min)
    {
    }

    bool interval::contains(num value) const
    {
        return min <= value && value <= max;
    }

    const interval interval::UNIVERSE = interval(-INFTY, INFTY);

    bool operator==(const interval &left, const interval &right)
    {
        return left.min == right.min && left.max == right.max;
    }

    bool operator!=(const interval &left, const interval &right)
    {
        return !(left == right);
    }

    interval operator+(const interval &left, const interval &right)
    {
        return interval(std::min(left.min, right.min), std::max(left.max, right.max));
    }

    interval operator*(const interval &left, const interval &right)
    {
        return interval(std::max(left.min, right.min), std::min(left.max, right.max));
    }

} // namespace math
