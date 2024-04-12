#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "color.hpp"

namespace graphic
{

    /// @brief Image stores its size and pixel data.
    class image
    {
    public:
        image(size_t width, size_t height);
        image(const image &other);
        image(image &&other) noexcept;

        INLINE const color &pixel(size_t row, size_t column) const noexcept;
        INLINE color &pixel(size_t row, size_t column) noexcept;

        INLINE void for_each_pixels(const std::function<void(const color &)> &func) const;
        INLINE void for_each_pixels(const std::function<void(color &)> &func);

        INLINE void for_each_pixels(const std::function<void(const color &, size_t row, size_t column)> &func) const;
        INLINE void for_each_pixels(const std::function<void(color &, size_t row, size_t column)> &func);

        bool save(const std::string &file_name) const;

        const size_t width;
        const size_t height;
    private:
        std::vector<color> pixels;
    };

}
