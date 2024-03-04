#pragma once

#include "tuple_base.hpp"

namespace math {

    /// @brief The index for accessing linear objects like vectors and quaternions.
    enum index {
        W = 0,
        X = 1,
        Y = 2,
        Z = 3
    };

    /// @brief The base struct for objects with linear operations.
    /// @tparam SELF The type of derived class.
    /// @tparam DIM The dimension of this vector.
    template<typename SELF, size_t DIM> requires is_power_of_2<DIM>
    struct linear_base : public tuple_base<DIM> {

        typedef tuple_base<DIM> tuple;
        typedef tuple::num_vec num_vec;

        /// @brief The default constructor.
        inline linear_base() = default;

        /// @brief Constructs a linear object using a compiler builtin vector.
        /// @param entries The compiler builtin vector.
        inline linear_base(const num_vec &entries) : tuple(entries) {};

        /// @brief Constructs a linear object using vec.
        template<typename... ARGS>
        inline linear_base(ARGS... args) : tuple{args...} {};

        /// @brief Adds two linear objects by entry-wise addition.
        friend inline SELF operator+(const linear_base &left, const linear_base &right) {
            return left.vec + right.vec;
        }

        /// @brief Subtracts two linear objects by entry-wise subtraction.
        friend inline SELF operator-(const linear_base &left, const linear_base &right) {
            return left.vec - right.vec;
        }

        /// @brief Scalar multiplication.
        friend inline SELF operator*(const linear_base &left, num right) {
            return left.vec * right;
        }

        /// @brief Scalar multiplication.
        friend inline SELF operator*(num left, const linear_base &right) {
            return left * right.vec;
        }

        /// @brief Scalar division.
        friend inline SELF operator/(const linear_base &left, num right) {
            return left.vec * (1 / right);
        }
    };

} // namespace math
