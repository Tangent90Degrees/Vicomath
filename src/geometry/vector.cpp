#include "vector.hpp"
#include "../utils/random.hpp"

namespace math
{

    vector::vector() = default;

    vector::vector(const num_vec &entries)
        : linear_base(entries)
    {
    }

    vector::vector(num x, num y, num z)
        : linear_base(static_cast<num>(0), x, y, z)
    {
    }

    vector vector::random(num min, num max)
    {
        return vector(random::uniform_real(min, max), random::uniform_real(min, max), random::uniform_real(min, max));
    }

    vector vector::random_in_sphere(num radius)
    {
        while (true)
        {
            auto p = random(-radius, radius);
            if (magnitude(p) < radius * radius)
            {
                return p;
            }
        }
    }

    vector vector::random_on_shell(num radius)
    {
        return normalized(random_in_sphere(radius));
    }

    vector vector::random_on_hemisphere(const vector &normal)
    {
        auto on_unit_sphere = random_on_shell(1);
        return dot(on_unit_sphere, normal) < 0 ? -on_unit_sphere : on_unit_sphere;
    }

    INLINE num dot(const vector &left, const vector &right)
    {
        return left[X] * right[X] + left[Y] * right[Y] + left[Z] * right[Z];
    }

    INLINE num sqr_magnitude(const vector &v)
    {
        return v[X] * v[X] + v[Y] * v[Y] + v[Z] * v[Z];
    }

    INLINE num magnitude(const vector &v)
    {
        return sqrt(sqr_magnitude(v));
    }

    INLINE vector normalized(const vector &v)
    {
        return v / magnitude(v);
    }

} // namespace math
