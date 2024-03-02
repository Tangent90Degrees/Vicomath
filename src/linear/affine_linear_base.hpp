#pragma once

#include "linear_base.hpp"

namespace math {

    /// @brief The base struct for objects in an affine space of some vector space.
    /// @tparam AFFINE The type of derived affine objects.
    /// @tparam VEC The type of vectors.
    /// @tparam DIM The dimension of vectors.
    template<typename AFFINE, typename VEC, size_t DIM> requires is_power_of_2<DIM>
    struct affine_linear_base : public tuple_base<DIM> {

        typedef linear_base<VEC, DIM> linear_base;
        typedef linear_base::tuple tuple;
        typedef linear_base::num_vec num_vec;

        /// @brief The default constructor.
        inline affine_linear_base() = default;

        /// @brief Constructs a point using a compiler builtin vector.
        /// @param entries The compiler builtin vector.
        inline affine_linear_base(const num_vec &entries) : tuple(entries) {};

        /// @brief Constructs a point using entries.
        template<typename... ARGS>
        inline affine_linear_base(ARGS... args) : tuple{args...} {};

        /// @brief Adds two linear objects by entry-wise addition.
        friend AFFINE operator+(const affine_linear_base &left, const linear_base &right) {
            return left.entries + data(right);
        }

        /// @brief Subtracts two linear objects by entry-wise subtraction.
        friend AFFINE operator-(const affine_linear_base &left, const linear_base &right) {
            return left.entries - data(right);
        }

        /// @brief Adds two linear objects by entry-wise addition.
        friend AFFINE operator+(const linear_base &left, const affine_linear_base &right) {
            return data(left) + right.entries;
        }

        /// @brief Subtracts two linear objects by entry-wise subtraction.
        friend VEC operator-(const affine_linear_base &left, const affine_linear_base &right) {
            return left.entries - right.entries;
        }
    };

} // namespace math