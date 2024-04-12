#include "renderer.hpp"

using namespace math;
using namespace graphic;

void renderer::render(image &output)
{
    for (int i = 0; i < output.height; ++i)
        for (int j = 0; j < output.width; ++j)
            output.pixel(i, j) = {static_cast<num>(j) / output.width, static_cast<num>(i) / output.height, 1};

    // num delta_x = ONE / output.width;
    // num delta_y = ONE / output.height;
    // num left_upper_corner_x = -0.5, left_upper_corner_y = 0.5;
    // output.for_each_pixels([&](color &c, size_t x, size_t y)
    //                        { c = shader(
    //                              scene->camera->shoot_ray(
    //                                  left_upper_corner_x + x * delta_x,
    //                                  left_upper_corner_y - y * delta_y)); });
}

// graphic::color renderer::shader(const ray &ray)
// {
//     return graphic::color();
// }
