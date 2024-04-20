#include "scene.hpp"

scene::scene() = default;

scene::scene(std::initializer_list<std::shared_ptr<mesh>> meshes)
    : meshes(meshes)
{
}

void scene::add_mesh(const std::shared_ptr<mesh> &mesh)
{
    meshes.push_back(mesh);
}

std::optional<hit_info> scene::hit(const math::ray &ray) const
{
    std::optional<hit_info> closest_hit = std::nullopt;
    for (auto &&mesh : meshes)
    {
        auto hit = mesh->hit(ray);
        if (hit && hit->time > 0.0001 && (!closest_hit || hit->time < closest_hit->time))
        {
            closest_hit = hit;
        }
    }
    return closest_hit;
}
