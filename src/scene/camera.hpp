#pragma once

#include <tuple>
#include "../geometry/ray.hpp"
#include "scene_object.hpp"

class camera : public scene_object {
public:
    struct viewport_size {
        math::num width;
        math::num height;
    };

    camera(const math::point &position,
           const math::quaternion &rotation,
           math::num focal_length,
           const viewport_size &viewport_size);

    math::ray shoot_ray(math::num x, math::num y) const;

private:
    math::num focal_length;
    viewport_size viewport_size;
};
