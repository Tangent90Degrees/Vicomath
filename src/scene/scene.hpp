#pragma once

#include <vector>
#include "camera.hpp"

class scene {
public:
    scene(const camera *camera);

    const camera *camera;
private:
    std::vector<scene_object *> objects;
};
