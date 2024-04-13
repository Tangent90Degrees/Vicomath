#pragma once

#include "scene_object.hpp"
#include "../geometry/ray.hpp"

/// @brief Hit information including hit point and normal.
struct hit_info
{
    hit_info(const math::point &point, const math::vector &normal, num time)
        : point(point), normal(normal), time(time) {}

    bool is_front_face(const math::ray &ray) const { return math::dot(ray.direction, normal) >= 0; }

    math::point point;
    math::vector normal;
    num time;
};

/// @brief Represents a 3D solid mesh.
class mesh : public scene_object
{
public:
    mesh(math::point position, math::quaternion rotation);

    /// @brief The virtual destructor.
    virtual ~mesh() = default;

    /// @brief Calculates if the specified ray can hit the surface.
    /// @param ray The specified ray.
    /// @return Hit information including hit point and normal.
    virtual std::optional<hit_info> hit(const math::ray &ray) = 0;

private:
};