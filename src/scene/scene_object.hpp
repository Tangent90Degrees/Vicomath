#pragma once

#include "../geometry/point.hpp"
#include "../geometry/quaternion.hpp"

class scene_object {
public:

    scene_object(const math::point &position, const math::quaternion &rotation);

    math::point position;
    math::quaternion rotation;
};
