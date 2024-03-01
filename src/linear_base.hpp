#pragma once

#include <array>

#include "utils/core.hpp"

namespace math
{
    /// @brief The index for accessing linear objects like vectors and quaternions.
    enum index
    {
        W = 0,
        X = 1,
        Y = 2,
        Z = 3
    };

    /// @brief The base class for objects with linear operations.
    /// @tparam SELF The type of derived class.
    template <typename SELF>
    class linear_base
    {
        /// @brief Data members of this linear object.
        union
        {
            /// @brief Access the data by a compiler builtin vector for faster operations.
            num4 entries;
            /// @brief Access the data by an array for faster entry accessing.
            std::array<num, 4> array;
        };

    public:
        /// @brief The default constructor.
        inline linear_base(){};

        /// @brief Constructs a linear object using a compiler builtin vector.
        /// @param entries The compiler builtin vector.
        inline linear_base(const num4 &entries) : entries(entries){};

        /// @brief Constructs a linear object using entries.
        inline linear_base(num w, num x, num y, num z) : array{w, x, y, z} {};

        /// @brief Accesses the entry at the specified position.
        /// @param off The specified index.
        /// @return The read-only value of the entry.
        inline constexpr num operator[](index off) const noexcept { return array[off]; }

        /// @brief Accesses the entry at the specified position.
        /// @param off The specified index.
        /// @return The reference of the entry.
        inline constexpr num &operator[](index off) noexcept { return array[off]; }

        inline constexpr const num *begin() const noexcept { return array.begin(); }
        inline constexpr num *begin() noexcept { return array.begin(); }
        inline constexpr const num *end() const noexcept { return array.end(); }
        inline constexpr num *end() noexcept { return array.end(); }

        template <typename _SELF>
        friend _SELF operator+(const linear_base<_SELF> &left, const linear_base<_SELF> &right);

        template <typename _SELF>
        friend _SELF operator-(const linear_base<_SELF> &left, const linear_base<_SELF> &right);

        template <typename _SELF>
        friend _SELF operator*(const linear_base<_SELF> &left, num right);

        template <typename _SELF>
        friend _SELF operator*(num left, const linear_base<_SELF> &right);

        template <typename _SELF>
        friend _SELF operator/(const linear_base<_SELF> &left, num right);
    };

    template <typename SELF>
    inline SELF operator+(const linear_base<SELF> &left, const linear_base<SELF> &right)
    {
        return left.entries + right.entries;
    }

    template <typename SELF>
    inline SELF operator-(const linear_base<SELF> &left, const linear_base<SELF> &right)
    {
        return left.entries - right.entries;
    }

    template <typename _SELF>
    inline _SELF operator*(const linear_base<_SELF> &left, num right)
    {
        return left.entries * right;
    }

    template <typename _SELF>
    inline _SELF operator*(num left, const linear_base<_SELF> &right)
    {
        return left * right.entries;
    }

    template <typename _SELF>
    inline _SELF operator/(const linear_base<_SELF> &left, num right)
    {
        return left.entries * (1 / right);
    }

} // namespace math
