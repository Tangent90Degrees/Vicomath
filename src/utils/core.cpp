#include "core.hpp"

namespace math
{

    INLINE num inv_sqrt(num x)
    {
        long i;
        float x2, y;
        const float three_halves = 1.5f;
        x2 = x * 0.5f;
        y = x;
        i = *(long *)&y;           // Evil floating point bit level hacking
        i = 0x5f3759df - (i >> 1); // What the fuck?
        y = *(float *)&i;
        y = y * (three_halves - (x2 * y * y)); // 1st iteration
        // y  = y * ( three_halves - ( x2 * y * y ) );   // 2nd iteration, this can be removed
        return y;
    }

}