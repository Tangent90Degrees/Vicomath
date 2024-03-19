#pragma once

#include "../scene/scene.hpp"
#include "image.hpp"

class renderer {
    void render(graphic::image &output);
    graphic::color shader(const math::ray &ray);

private:
    const scene *scene;
};
