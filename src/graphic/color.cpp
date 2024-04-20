#include "color.hpp"

namespace graphic
{

    color::color() = default;

    color::color(const color::num_vec &entries) : linear_base(entries)
    {
    }

    color::color(num r, num g, num b, num a) : linear_base(a, r, g, b)
    {
    }

    color::color(const math::vector &normal)
        : linear_base((static_cast<num_vec>(normal) + static_cast<num_vec>(WHITE)) / 2)
    {
    }

    color::bits_24_color bits_24(const color &color)
    {
        return {color::bits_24_channel * color[R],
                color::bits_24_channel * color[G],
                color::bits_24_channel * color[B]};
    }

    color mix(const color &from, const color &to, num factor)
    {
        return from * (1 - factor) + to * factor;
    }

    const color color::WHITE(1, 1, 1);
    const color color::BLACK(0, 0, 0);
    const color color::RED(1, 0, 0);
}