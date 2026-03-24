#pragma once

#include <limits.h>

namespace calc_math {

    enum MathCode {
        OK = 0,
        OVERFLOW,
        DIV_BY_ZERO,
        INVALID_INPUT
    };

    inline MathCode add(long long first, long long second, long long& out) {
        if (__builtin_add_overflow(first, second, &out))
            return OVERFLOW;
        return OK;
    }

    inline MathCode sub(long long first, long long second, long long& out) {
        if (__builtin_sub_overflow(first, second, &out))
            return OVERFLOW;
        return OK;
    }

    inline MathCode mul(long long first, long long second, long long& out) {
        if (__builtin_mul_overflow(first, second, &out))
            return OVERFLOW;
        return OK;
    }

    inline MathCode div(long long first, long long second, long long& out) {
        if (second == 0) 
            return DIV_BY_ZERO;
        if (first == LLONG_MIN && second == -1) 
            return OVERFLOW;
        out = first / second;
        return OK;
    }

    inline MathCode pow(long long base, long long exp, long long& out) {
        if (exp < 0)
            return INVALID_INPUT;

        long long result = 1;
        MathCode code;
        for (long long i = 0; i < exp; ++i) {
            code = mul(result, base, result);
            if (code != OK)
                return code;
        }
        out = result;
        return OK;
    }

    inline MathCode fact(long long n, long long& out) {
        if (n < 0)
            return INVALID_INPUT;

        if (n == 0 || n == 1) {
            out = 1;
            return OK;
        }

        long long prev = 0;
        MathCode code = fact(n - 1, prev);
        if (code != OK)
            return code;

        return mul(n, prev, out);
    }

}
