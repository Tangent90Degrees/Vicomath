#include "image.hpp"

#include <fstream>

namespace graphic {

    image::image(size_t width, size_t height) : width(width), height(height) {
        pixels = new color[width * height];
    }

    image::image(const image &im) : image(im.width, im.height) {
        memcpy(pixels, im.pixels, width * height);
    }

    image::image(image &&im) noexcept: width(im.width), height(im.height), pixels(im.pixels) {
        im.pixels = nullptr;
    }

    image::~image() {
        delete[] pixels;
    }

    INLINE const color &image::operator[](size_t row, size_t column) const noexcept {
        return pixels[row * width + column];
    }

    INLINE color &image::operator[](size_t row, size_t column) noexcept {
        return pixels[row * width + column];
    }

    bool image::save(const std::string &file_name) const {
        std::ofstream output(file_name, std::ios_base::binary);
        if (!output.is_open()) return false;
        output << "P3\n" << width << ' ' << height << "\n255\n";
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                auto [r, g, b] = bits_24((*this)[i, j]);
                output << r << ' ' << g << ' ' << b << '\n';
            }
        }
        output.close();
        return true;
    }

    void image::render() {
        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                (*this)[i, j] = {static_cast<num>(j) / width, static_cast<num>(i) / height, 1};
    }


}