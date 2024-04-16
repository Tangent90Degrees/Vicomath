#include "random.hpp"

namespace math
{
    num random::uniform_real(num min, num max)
    {
        return std::uniform_real_distribution<num>(min, max)(rd);
    }

    std::random_device random::rd{};
}
