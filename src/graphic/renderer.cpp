#include "renderer.hpp"
#include "../utils/random.hpp"

using namespace math;
using namespace graphic;

void renderer::render(image &output)
{
    // Set up the camera.
    camera cam(point::ZERO, quaternion::ONE, 1.0, {16 * 2.0 / 9, 2.0});

    num pixel_size = cam.viewport_size.width / output.width;

    // Set up scene.
    scene scene;
    scene.add_mesh(std::make_shared<sphere>(point(0, 0, -1), 0.5));
    scene.add_mesh(std::make_shared<sphere>(point(0, -100.5, -1), 100));

    for (size_t j = 0; j < output.height; j++) {
        for (size_t i = 0; i < output.width; i++) {
            // auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            // auto ray_direction = pixel_center - cam.position;
            // ray r(cam.position, ray_direction);
            ray r = cam.shoot_ray((i + 0.5) / output.width - 0.5, 0.5 - (j + 0.5) / output.height);
            // output.pixel(j, i) = shader(r, scene);

            color pixel_color_sum = color::BLACK;
            for (size_t sample_times = 0; sample_times < samples_per_pixel; sample_times++)
            {
                ray random_ray = {r.origin, r.direction + pixel_size * vector(random::uniform_real(-0.5, 0.5), random::uniform_real(-0.5, 0.5), 0)};
                pixel_color_sum = pixel_color_sum + shader(random_ray, scene);
            }
            output.pixel(j, i) = pixel_color_sum / samples_per_pixel;
        }
    }
}

graphic::color renderer::shader(const ray &ray, const scene &scene)
{
    // auto ray_hit = sphere(point(0, 0, -1), 0.5).hit(ray);
    auto ray_hit = scene.hit(ray);
    if (ray_hit)
    {
        vector normal = ray_hit->normal;
        return 0.5 * (color(normal[X], normal[Y], normal[Z]) + color::WHITE);
    }
    
    // World sky.
    vector unit_direction = normalized(ray.direction);
    num gradiant_factor = 0.5 * (unit_direction[Y] + 1.0);
    return mix(color::WHITE, {0.5, 0.7, 1.0}, gradiant_factor);
}
