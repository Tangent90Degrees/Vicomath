#include "renderer.hpp"

#include <algorithm>

using namespace math;
using namespace graphic;

void renderer::render(image &output) {
    num delta_x = ONE / output.width;
    num delta_y = ONE / output.height;
    num left_upper_corner_x = -0.5, left_upper_corner_y = 0.5;
    for (int i = 0; i < output.height; ++i) {
        for (int j = 0; j < output.width; ++j) {
            output[i, j] = shader(
                    scene->camera->shoot_ray(
                            left_upper_corner_x + i * delta_x,
                            left_upper_corner_y - j * delta_y
                    )
            );
        }
    }
}

graphic::color renderer::shader(const ray &ray) {
    return graphic::color();
}
