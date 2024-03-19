//
// Created by Victor Liu on 3/7/24.
//

#include "scene_object.hpp"

scene_object::scene_object(const math::point &position, const math::quaternion &rotation)
    : position(position), rotation(rotation) {
}
