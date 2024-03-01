#pragma once

#include <array>
#include "utils/core.hpp"

namespace math {

    /// @brief The index for accessing linear objects like vectors and quaternions.
    enum index {
        W = 0,
        X = 1,
        Y = 2,
        Z = 3
    };

    /// @brief The base class for objects with linear operations.
    /// @tparam SELF The type of derived class.
    template<typename SELF, size_t DIM> requires power_of_2<DIM>
    class linear_base {

        typedef num num_vec __attribute__((ext_vector_type(DIM)));

        /// @brief Data members of this linear object.
        union {
            /// @brief Access the data by a compiler builtin vector for faster operations.
            num_vec entries;
            /// @brief Access the data by an array for faster entry accessing.
            std::array<num, DIM> array;
        };

    public:

        /// @brief The default constructor.
        inline linear_base() {};

        /// @brief Constructs a linear object using a compiler builtin vector.
        /// @param entries The compiler builtin vector.
        inline linear_base(const num_vec &entries) : entries(entries) {};

        /// @brief Constructs a linear object using entries.
        template<typename... ARGS>
        inline linear_base(ARGS... args) : array{args...} {};

        /// @brief Accesses an entry at a specified position.
        /// @param off Position of element to access.
        /// @return The value of the entry.
        inline constexpr num operator[](index off) const noexcept { return array[off]; }

        /// @brief Accesses an entry at a specified position.
        /// @param off Position of element to access.
        /// @return The reference of the entry.
        inline constexpr num &operator[](index off) noexcept { return array[off]; }

        /// @brief Designates the beginning of the constant controlled sequence.
        [[nodiscard]] inline constexpr const num *begin() const noexcept { return array.begin(); }

        /// @brief Designates the beginning of the controlled sequence.
        inline constexpr num *begin() noexcept { return array.begin(); }

        /// @brief Designates the end of the controlled sequence.
        [[nodiscard]] inline constexpr const num *end() const noexcept { return array.end(); }

        /// @brief Designates the end of the controlled sequence.
        inline constexpr num *end() noexcept { return array.end(); }

        /// @brief Adds two linear objects by entry-wise addition.
        friend SELF operator+(const linear_base<SELF, DIM> &left, const linear_base<SELF, DIM> &right) {
            return left.entries + right.entries;
        }

        /// @brief Subtracts two linear objects by entry-wise subtraction.
        friend SELF operator-(const linear_base<SELF, DIM> &left, const linear_base<SELF, DIM> &right) {
            return left.entries - right.entries;
        }

        /// @brief Scalar multiplication.
        friend SELF operator*(const linear_base<SELF, DIM> &left, num right) {
            return left.entries * right;
        }

        friend SELF operator*(num left, const linear_base<SELF, DIM> &right) {
            return left * right.entries;
        }

        friend SELF operator/(const linear_base<SELF, DIM> &left, num right) {
            return left.entries * (1 / right);
        }
    };

} // namespace math
