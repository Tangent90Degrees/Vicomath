#include "image.hpp"

#include <fstream>

namespace graphic
{

    image::image(size_t width, size_t height)
        : width(width), height(height)
    {
        pixels.resize(width * height);
    }

    image::image(const image &other)
        : width(other.width), height(other.height), pixels(other.pixels)
    {
    }

    image::image(image &&other) noexcept
        : width(other.width), height(other.height), pixels(std::move(other.pixels))
    {
    }

    const color &image::pixel(size_t row, size_t column) const noexcept
    {
        return pixels[row * width + column];
    }

    color &image::pixel(size_t row, size_t column) noexcept
    {
        return pixels[row * width + column];
    }

    bool image::save(const std::string &file_name) const
    {
        std::ofstream output(file_name, std::ios_base::binary);
        if (!output.is_open())
        {
            return false;
        }
        output << "P3\n"
               << width << ' ' << height << "\n255\n";
        for (auto &&color : pixels)
        {
            auto [r, g, b] = bits_24(color);
            output << r << ' ' << g << ' ' << b << '\n';
        }
        output.close();
        return true;
    }

}