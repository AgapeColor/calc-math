#pragma once

#include <limits.h>

namespace calc_math {

    enum MathCode {
        OK = 0,
        OVERFLOW,
        DIV_BY_ZERO,
        INVALID_INPUT
    };

    inline MathCode add(int first, int second, int& out) {
        if (__builtin_add_overflow(first, second, &out))
            return OVERFLOW;
        return OK;
    }

    inline MathCode sub(int first, int second, int& out) {
        if (__builtin_sub_overflow(first, second, &out))
            return OVERFLOW;
        return OK;
    }

    inline MathCode mul(int first, int second, int& out) {
        if (__builtin_mul_overflow(first, second, &out))
            return OVERFLOW;
        return OK;
    }

    inline MathCode div(int first, int second, int& out) {
        if (second == 0) 
            return DIV_BY_ZERO;
        if (first == INT_MIN && second == -1) 
            return OVERFLOW;
        out = first / second;
        return OK;
    }

    inline MathCode pow(int base, int exp, int& out) {
        if (exp < 0)
            return INVALID_INPUT;

        int result = 1;
        MathCode code;
        for (int i = 0; i < exp; ++i) {
            code = mul(result, base, result);
            if (code != OK)
                return code;
        }
        out = result;
        return OK;
    }

    inline MathCode fact(int n, int& out) {
        if (n < 0)
            return INVALID_INPUT;

        if (n == 0 || n == 1) {
            out = 1;
            return OK;
        }

        int prev = 0;
        MathCode code = fact(n - 1, prev);
        if (code != OK)
            return code;

        return mul(n, prev, out);
    }

}
