#pragma once

#include <random>
#include "core.hpp"
#include "interval.hpp"

namespace math
{
    class random
    {
    public:
        INLINE static num uniform_real(num min, num max);
    private:
        random() = delete;
        random(const random &other) = delete;

        /// @brief The random engine.
        static std::random_device rd;
    };
} // namespace math
