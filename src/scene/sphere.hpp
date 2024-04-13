#pragma once

#include "mesh.hpp"

struct sphere : public mesh
{
    sphere(math::point origin, num radius);

    std::optional<hit_info> hit(const math::ray &ray) override;

    num radius;
};
