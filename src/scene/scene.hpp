#pragma once

#include <vector>
#include "camera.hpp"
#include "mesh.hpp"

class scene
{
public:
    scene();
    
    scene(std::initializer_list<std::shared_ptr<mesh>> meshes);

    void add_mesh(const std::shared_ptr<mesh> &mesh);

    std::optional<hit_info> hit(const math::ray &ray) const;

private:
    std::vector<std::shared_ptr<mesh>> meshes;
};
