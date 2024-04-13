#pragma once

#include "../geometry/point.hpp"
#include "../geometry/quaternion.hpp"

using math::num;

class scene_object
{
public:
    scene_object(const math::point &position, const math::quaternion &rotation);

    /// @brief The virtual destructor.
    virtual ~scene_object() = default;

    math::point position;
    math::quaternion rotation;
};
