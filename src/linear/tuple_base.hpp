#pragma once

#include <array>
#include "../utils/core.hpp"

namespace math {

    /// @brief The base struct for objects with multiple entries.
    /// @tparam N The number of vec.
    template<size_t N> requires is_power_of_2<N>
    struct tuple_base {

        /// @brief The builtin vector type.
        typedef num num_vec VEC_TYPE(N);

        /// @brief The builtin matrix type.
        typedef num num_mat MAT_TYPE(N, 1);

        /// @brief The default constructor.
        inline tuple_base() = default;

        /// @brief Constructs a tuple using a compiler builtin vector.
        /// @param entries The compiler builtin vector.
        inline tuple_base(const num_vec &entries) : vec(entries) {};

        /// @brief Constructs a tuple using a compiler builtin matrix.
        /// @param entries The compiler builtin matrix.
        inline tuple_base(const num_mat &entries) : mat(entries) {};

        /// @brief Constructs a tuple using vec.
        template<typename... ARGS>
        inline tuple_base(ARGS... args) : array{args...} {};

        /// @brief Accesses an entry at a specified position.
        /// @param off Position of element to access.
        /// @return The value of the entry.
        inline constexpr num operator[](size_t off) const noexcept { return array[off]; }

        /// @brief Accesses an entry at a specified position.
        /// @param off Position of element to access.
        /// @return The reference of the entry.
        inline constexpr num &operator[](size_t off) noexcept { return array[off]; }

        /// @brief Accesses all vec data.
        /// @return The builtin vector type of data.
        inline const num_vec &vec_data() const noexcept { return vec; }

        /// @brief Accesses all mat data.
        /// @return The builtin matrix type of data.
        inline const num_mat &mat_data() const noexcept { return mat; }

        /// @brief Designates the beginning of the constant controlled sequence.
        [[nodiscard]] inline constexpr const num *begin() const noexcept { return array.begin(); }

        /// @brief Designates the beginning of the controlled sequence.
        inline constexpr num *begin() noexcept { return array.begin(); }

        /// @brief Designates the end of the controlled sequence.
        [[nodiscard]] inline constexpr const num *end() const noexcept { return array.end(); }

        /// @brief Designates the end of the controlled sequence.
        inline constexpr num *end() noexcept { return array.end(); }

    protected:

        /// @brief Data members of this linear object.
        union {
            /// @brief Access the data by a compiler builtin vector for faster operations.
            num_vec vec;
            /// @brief Access the data by a compiler builtin matrix for faster operations.
            num_mat mat;
            /// @brief Access the data by an array for faster entry accessing.
            std::array<num, N> array;
        };
    };

} // namespace math
