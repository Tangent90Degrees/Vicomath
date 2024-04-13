#include "sphere.hpp"

sphere::sphere(math::point origin, num radius)
    : mesh(origin, math::quaternion::ONE), radius(radius)
{
}

std::optional<mesh::hit_info> sphere::hit(const math::ray &ray)
{
    auto oc = position - ray.origin;
    auto a = sqr_magnitude(ray.direction);
    auto h = dot(ray.direction, oc);
    auto c = sqr_magnitude(oc) - radius * radius;
    auto discriminant = h * h - a * c;

    if (discriminant < 0)
    {
        return std::nullopt;
    }

    auto sqrt_d = sqrt(discriminant);
    auto root = (h - sqrt_d) / a;
    if (root < 0)
    {
        root = (h + sqrt_d) / a;
        if (root < 0)
        {
            return std::nullopt;
        }
    }
    
    auto point = ray((h - sqrt(discriminant)) / a);
    return hit_info(point, normalized(point - position));
}
