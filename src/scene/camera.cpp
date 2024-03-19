#include "camera.hpp"

camera::camera(const math::point &position,
               const math::quaternion &rotation,
               math::num focal_length,
               const struct viewport_size &viewport_size)
        : scene_object(position, rotation),
          focal_length(focal_length),
          viewport_size(viewport_size) {
}

math::ray camera::shoot_ray(math::num x, math::num y) const {
    return {
            position,
            rotation({x * viewport_size.width, y * viewport_size.height, focal_length})
    };
}

