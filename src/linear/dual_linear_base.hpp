#pragma once

#include "linear_base.hpp"

namespace math {

    template<typename DUAL, typename VEC, size_t DIM> requires is_power_of_2<DIM>
    struct dual_linear_base : linear_base<DUAL, DIM> {

        typedef linear_base<DUAL, DIM> tuple;
        typedef linear_base<VEC, DIM> linear_base;
        typedef tuple::num_vec num_vec;

        /// @brief The default constructor.
        inline dual_linear_base() = default;

        /// @brief Constructs a point using a compiler builtin vector.
        /// @param entries The compiler builtin vector.
        inline dual_linear_base(const num_vec &entries) : tuple(entries) {};

        /// @brief Constructs a point using vec.
        template<typename... ARGS>
        inline dual_linear_base(ARGS... args) : tuple{args...} {};

        inline num operator()(const linear_base &v) const {
            return 0;
        }

    };

}
