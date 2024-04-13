#include "src/vicomath.h"

using namespace math;
using namespace graphic;

int main()
{
    renderer renderer;
    image image{1920, 1080};
    std::cout << "Image has been created successfully." << std::endl;

    renderer.render(image);
    image.save("image.ppm");
    std::cout << "Rendering tasks finished." << std::endl;
}