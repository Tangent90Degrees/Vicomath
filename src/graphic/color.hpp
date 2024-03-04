#pragma once

#include <tuple>
#include "../linear/linear_base.hpp"

namespace graphic {

    using math::num;

    enum color_index {
        A,
        R,
        G,
        B
    };

    struct color : math::linear_base<color, 4> {

        typedef linear_base::num_vec num_vec;
        typedef std::tuple<int, int, int> bits_24_color;

        static constexpr const num bits_24_channel = 255.999;

        /// @brief The default constructor.
        INLINE color();

        /// @brief Constructs a vector by specified vec.
        INLINE color(const num_vec &entries);

        /// @brief Constructs a vector by x, y, and z vec.
        INLINE color(num r, num g, num b, num a = 1);

        friend INLINE bits_24_color bits_24(const color &color);

    };

    INLINE color::bits_24_color bits_24(const color &color);

}
