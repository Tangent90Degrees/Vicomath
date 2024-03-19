#include "vicomath.h"

using namespace math;
using namespace graphic;

int main() {
    image image = {1920, 1080};
    image.render();
    image.save("image.ppm");
}