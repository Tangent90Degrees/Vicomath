#pragma once

#include <tuple>
#include "../linear/linear_base.hpp"
#include "../geometry/vector.hpp"

namespace graphic
{
    using math::num;

    enum color_index
    {
        A,
        R,
        G,
        B
    };

    struct color : math::linear_base<color, 4>
    {
        typedef linear_base::num_vec num_vec;
        typedef std::tuple<int, int, int> bits_24_color;

        static constexpr const num bits_24_channel = 255.999;

        /// @brief The default constructor.
        INLINE color();

        /// @brief Constructs a vector by specified vec.
        INLINE color(const num_vec &entries);

        /// @brief Constructs a vector by x, y, and z vec.
        INLINE color(num r, num g, num b, num a = 1);

        INLINE color(const math::vector &normal);

        friend INLINE bits_24_color bits_24(const color &color);

        static const color WHITE;
        static const color BLACK;
        static const color RED;
    };

    INLINE color::bits_24_color bits_24(const color &color);

    /// @brief Mix two colors linearly.
    /// @param from The color when the factor is zero.
    /// @param to The color when the factor is one.
    /// @param factor The mix factor.
    /// @return The mixed color.
    INLINE color mix(const color &from, const color &to, num factor);
}
