#pragma once

#include "../scene/scene.hpp"
#include "../scene/sphere.hpp"
#include "image.hpp"

class renderer
{
public:
    void render(graphic::image &output);
    graphic::color shader(const math::ray &ray, const scene &scene);

private:
    // const scene *scene;
    size_t samples_per_pixel = 10;
};
