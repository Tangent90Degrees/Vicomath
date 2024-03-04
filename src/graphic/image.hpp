#pragma once

#include <iostream>
#include <string>
#include "color.hpp"

namespace graphic {

    class image {
    public:

        image(size_t width, size_t height);

        image(const image &im);

        image(image &&im) noexcept;

        ~image();

        INLINE const color &operator[](size_t row, size_t column) const noexcept;
        INLINE color &operator[](size_t row, size_t column) noexcept;

        bool save(const std::string &file_name) const;

        void render();

    private:
        const size_t width;
        const size_t height;
        color *pixels;
    };

}
