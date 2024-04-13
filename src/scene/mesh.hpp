#pragma once

#include "scene_object.hpp"
#include "../geometry/ray.hpp"

class mesh : public scene_object
{
public:
    struct hit_info
    {
        hit_info(const math::point &point, const math::vector &normal)
            : point(point), normal(normal) {}
        const math::point point;
        const math::vector normal;
    };

    mesh(math::point position, math::quaternion rotation);

    /// @brief The virtual destructor.
    virtual ~mesh() = default;

    virtual std::optional<hit_info> hit(const math::ray &ray) = 0;

private:
};