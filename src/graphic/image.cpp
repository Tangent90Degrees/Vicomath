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

    void image::for_each_pixels(const std::function<void(const color &)> &func) const
    {
        std::for_each(pixels.begin(), pixels.end(), func);
    }

    void image::for_each_pixels(const std::function<void(color &)> &func)
    {
        std::for_each(pixels.begin(), pixels.end(), func);
    }

    void image::for_each_pixels(const std::function<void(const color &, size_t row, size_t column)> &func) const
    {
        for (size_t i = 0; i < width; i++)
        {
            for (size_t j = 0; j < height; j++)
            {
                func(pixel(i, j), i, j);
            }
        }
    }

    void image::for_each_pixels(const std::function<void(color &, size_t row, size_t column)> &func)
    {
        for (size_t i = 0; i < width; i++)
        {
            for (size_t j = 0; j < height; j++)
            {
                func(pixel(i, j), i, j);
            }
        }
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
        for_each_pixels([&](const color &c)
                        { auto [r, g, b] = bits_24(c);
                          output << r << ' ' << g << ' ' << b << '\n'; });
        output.close();
        return true;
    }

}