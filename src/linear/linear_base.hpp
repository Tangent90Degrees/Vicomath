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
        typedef tuple::num_mat num_mat;

        /// @brief The default constructor.
        inline linear_base() = default;

        /// @brief Constructs a linear object using a compiler builtin vector.
        /// @param entries The compiler builtin vector.
        inline linear_base(const num_vec &entries) : tuple(entries) {};

        /// @brief Constructs a linear object using a compiler builtin matrix.
        /// @param entries The compiler builtin matrix.
        inline linear_base(const num_mat &entries) : tuple(entries) {};

        /// @brief Constructs a linear object using vec.
        template<typename... ARGS>
        inline linear_base(ARGS... args) : tuple{args...} {};

    };

    /// @brief Adds two linear objects by entry-wise addition.
    template<typename VEC, size_t DIM>
    inline VEC operator+(const linear_base<VEC, DIM> &left, const linear_base<VEC, DIM> &right) {
        return static_cast<linear_base<VEC, DIM>::num_vec>(left)
               + static_cast<linear_base<VEC, DIM>::num_vec>(right);
    }

    /// @brief Subtracts two linear objects by entry-wise subtraction.
    template<typename VEC, size_t DIM>
    inline VEC operator-(const linear_base<VEC, DIM> &left, const linear_base<VEC, DIM> &right) {
        return static_cast<linear_base<VEC, DIM>::num_vec>(left)
               - static_cast<linear_base<VEC, DIM>::num_vec>(right);
    }

    /// @brief Scalar multiplication.
    template<typename VEC, size_t DIM>
    inline VEC operator*(const linear_base<VEC, DIM> &left, num right) {
        return static_cast<linear_base<VEC, DIM>::num_vec>(left) * right;
    }

    /// @brief Scalar multiplication.
    template<typename VEC, size_t DIM>
    inline VEC operator*(num left, const linear_base<VEC, DIM> &right) {
        return left * static_cast<linear_base<VEC, DIM>::num_vec>(right);
    }

    /// @brief Scalar division.
    template<typename VEC, size_t DIM>
    inline VEC operator/(const linear_base<VEC, DIM> &left, num right) {
        return static_cast<linear_base<VEC, DIM>::num_vec>(left) * (ONE / right);
    }

} // namespace math
