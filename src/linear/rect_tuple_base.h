#pragma once

#include <array>
#include "../utils/core.hpp"

namespace math {

    /// @brief The base struct for objects with block of entries.
    /// @tparam M The number of vec.
    /// @tparam N The number of vec.
    template<size_t M, size_t N> requires is_power_of_2<M> && is_power_of_2<N>
    struct rect_tuple_base {

        /// @brief The builtin matrix type.
        typedef num num_mat MAT_TYPE(M, N);

        /// @brief The default constructor.
        inline rect_tuple_base() = default;

        /// @brief Constructs a tuple using a compiler builtin vector.
        /// @param entries The compiler builtin vector.
        inline rect_tuple_base(const num_mat &entries) : mat(entries) {};

        /// @brief Constructs a tuple using vec.
        template<typename... ARGS>
        inline rect_tuple_base(ARGS... args) : array{args...} {};

        /// @brief Accesses an entry at a specified position.
        /// @param row Position of element to access.
        /// @return The value of the entry.
        inline constexpr num operator[](size_t row, size_t column) const noexcept { return array[row][column]; }

        /// @brief Accesses an entry at a specified position.
        /// @param row Position of element to access.
        /// @return The reference of the entry.
        inline constexpr num &operator[](size_t row, size_t column) noexcept { return array[row][column]; }

        /// @brief Accesses all mat data.
        /// @return The builtin matrix type of data.
        inline const num_mat &mat_data() const noexcept { return mat; }

        /// @brief Designates the beginning of the constant controlled sequence.
        [[nodiscard]] inline const std::array<num, N> *begin() const noexcept { return array.begin(); }

        /// @brief Designates the beginning of the controlled sequence.
        inline std::array<num, N> *begin() noexcept { return array.begin(); }

        /// @brief Designates the end of the controlled sequence.
        [[nodiscard]] inline const std::array<num, N> *end() const noexcept { return array.end(); }

        /// @brief Designates the end of the controlled sequence.
        inline std::array<num, N> *end() noexcept { return array.end(); }

    protected:

        /// @brief Data members of this linear object.
        union {
            /// @brief Access the data by a compiler builtin matrix for faster operations.
            num_mat mat;
            /// @brief Access the data by an array for faster entry accessing.
            std::array<std::array<num, N>, M> array;
        };
    };

} // namespace math
