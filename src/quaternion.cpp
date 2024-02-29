#include "quaternion.hpp"

namespace math
{
    quaternion::quaternion()
    {
    }

    quaternion::quaternion(const num4 &entries)
        : linear_base(entries)
    {
    }

    quaternion::quaternion(num w, num x, num y, num z)
        : linear_base(w, x, y, z)
    {
    }

} // namespace math
