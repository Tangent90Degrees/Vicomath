#include "renderer.hpp"

using namespace math;
using namespace graphic;

void renderer::render(image &output)
{
    // Set up the camera.
    camera cam(point::ZERO, quaternion::ONE, 1.0, {16 * 2.0 / 9, 2.0});

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    vector viewport_u(cam.viewport_size.width, 0, 0);
    vector viewport_v(0, -cam.viewport_size.height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / output.width;
    auto pixel_delta_v = viewport_v / output.height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = cam.position - vector(0, 0, cam.focal_length) - viewport_u / 2 - viewport_v / 2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    for (size_t j = 0; j < output.height; j++) {
        for (size_t i = 0; i < output.width; i++) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - cam.position;
            ray r(cam.position, ray_direction);
            output.pixel(j, i) = shader(r);
        }
    }
}

graphic::color renderer::shader(const ray &ray)
{
    auto t = sphere(point(0, 0, -1), 0.5).hit(ray);
    if (t)
    {
        vector normal = t->normal;
        return 0.5 * (color(normal[X], normal[Y], normal[Z]) + color::WHITE);
    }
    
    // return {ray.direction[X], ray.direction[Y], ray.direction[Z]};
    vector unit_direction = normalized(ray.direction);
    num gradiant_factor = 0.5 * (unit_direction[Y] + 1.0);
    return mix(color::WHITE, {0.5, 0.7, 1.0}, gradiant_factor);
}
