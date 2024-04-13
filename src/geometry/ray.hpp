#pragma once

#include "point.hpp"

namespace math
{
    /// @brief Represents the ray with an origin and a direction.
    struct ray
    {
        /// @brief Constructs a ray.
        ray();
        /// @brief Constructs a ray with the specified origin and direction.
        /// @param origin The origin of the ray.
        /// @param direction The direction of the ray.
        ray(const point &origin, const vector &direction);

        /// @brief Gets a point on the ray.
        /// @param t The duration time from the origin to the point on the ray.
        /// @return The point on the ray.
        INLINE point operator()(num t) const;

        /// @brief The origin of the ray.
        point origin;

        /// @brief The direction of the ray.
        vector direction;
    };
}
