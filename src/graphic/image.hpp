#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "color.hpp"

namespace graphic
{

    /// @brief Represents an image with array of pixels.
    class image
    {
    public:
        image(size_t width, size_t height);
        image(const image &other);
        image(image &&other) noexcept;

        INLINE const color &pixel(size_t row, size_t column) const noexcept;
        INLINE color &pixel(size_t row, size_t column) noexcept;

        bool save(const std::string &file_name) const;

        const size_t width;
        const size_t height;
    private:
        std::vector<color> pixels;
    };

}
