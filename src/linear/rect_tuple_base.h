#pragma once

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

        /// @brief Destructs this 2D tuple.
        inline virtual ~rect_tuple_base() = default;

        /// @brief Accesses an entry at a specified position.
        /// @param off Position of element to access.
        /// @return The value of the entry.
        inline constexpr auto operator[](size_t off) const noexcept -> const num (&)[N] { return array[off]; }

        /// @brief Accesses an entry at a specified position.
        /// @param off Position of element to access.
        /// @return The reference of the entry.
        inline constexpr auto operator[](size_t off) noexcept -> num (&)[N] { return array[off]; }

        /// @brief Accesses all mat data.
        /// @return The builtin matrix type of data.
        inline explicit operator num_mat() const noexcept { return mat; }

        /// @brief Designates the beginning of the constant controlled sequence.
        [[nodiscard]] inline auto begin() const noexcept -> const num (*)[N] { return array; }

        /// @brief Designates the beginning of the controlled sequence.
        inline auto begin() noexcept -> num (*)[N] { return array; }

        /// @brief Designates the end of the controlled sequence.
        [[nodiscard]] inline auto end() const noexcept -> const num (*)[N] { return array + M; }

        /// @brief Designates the end of the controlled sequence.
        inline auto end() noexcept -> num (*)[N] { return array + M; }

    protected:

        /// @brief Data members of this linear object.
        union {
            /// @brief Access the data by a compiler builtin matrix for faster operations.
            num_mat mat;
            /// @brief Access the data by an array for faster entry accessing.
            num array[M][N];
        };
    };

} // namespace math
