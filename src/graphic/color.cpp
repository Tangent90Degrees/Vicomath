#include "color.hpp"

namespace graphic {

    color::color() = default;

    color::color(const color::num_vec &entries) : linear_base(entries) {
    }

    color::color(num r, num g, num b, num a) : linear_base(a, r, g, b) {
    }

    color::bits_24_color bits_24(const color &color) {
        return {
                color::bits_24_channel * color[R],
                color::bits_24_channel * color[G],
                color::bits_24_channel * color[B]
        };
    }
}