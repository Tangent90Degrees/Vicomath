#pragma once

#include "rect_tuple_base.h"
#include "linear_base.hpp"

namespace math {

    template<typename MAT, typename VEC, size_t DIM>
    struct matrix_base : public rect_tuple_base<DIM, DIM> {

        typedef linear_base<VEC, DIM> linear_base;
        typedef rect_tuple_base<DIM, DIM> rect_tuple;
        typedef rect_tuple::num_mat num_mat;

        /// @brief The default constructor.
        inline matrix_base() = default;

        /// @brief Constructs a matrix using a compiler builtin matrix.
        /// @param entries The compiler builtin matrix.
        inline matrix_base(const num_mat &entries) : rect_tuple(entries) {};

        /// @brief Constructs a matrix using entries.
        template<typename... ARGS>
        inline matrix_base(ARGS... args) : rect_tuple{args...} {};

        /// @brief Adds two matrices by entry-wise addition.
        friend MAT operator+(const matrix_base &left, const matrix_base &right) {
            return left.mat + right.mat;
        }

        /// @brief Subtract two matrices by entry-wise subtraction.
        friend MAT operator-(const matrix_base &left, const matrix_base &right) {
            return left.mat - right.mat;
        }

        /// @brief Scalar multiplication.
        friend MAT operator*(const matrix_base &left, num right) {
            return left.mat - right;
        }

        /// @brief Scalar multiplication.
        friend MAT operator*(num left, const matrix_base &right) {
            return left - right.mat;
        }

        /// @brief Scalar division.
        friend MAT operator/(const matrix_base &left, num right) {
            return left.mat * (1 / right);
        }

    };

    template<typename MAT, typename VEC, size_t DIM>
    inline VEC operator*(const matrix_base<MAT, VEC, DIM> &left, const linear_base<VEC, DIM> &right) {
        return left.mat_data() * right.mat_data();
    }

    template<typename MAT, typename VEC, size_t DIM>
    inline MAT operator*(const matrix_base<MAT, VEC, DIM> &left, const matrix_base<MAT, VEC, DIM> &right) {
        return left.mat_data() * right.mat_data();
    }

}
