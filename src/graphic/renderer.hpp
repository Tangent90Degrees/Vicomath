#pragma once

#include "../scene/scene.hpp"
#include "../scene/sphere.hpp"
#include "image.hpp"

class renderer
{
public:
    void render(graphic::image &output);
    graphic::color shader(const math::ray &ray);

private:
    // const scene *scene;
};
