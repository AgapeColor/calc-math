#pragma once

#include <limits.h>

namespace calc_math {

    enum MathCode {
        OK = 0,
        OVERFLOW,
        DIV_BY_ZERO,
        INVALID_INPUT
    };

    inline MathCode add(long long a, long long b, long long& out) {
        if ((b > 0 && a > LLONG_MAX - b) || (b < 0 && a < LLONG_MIN - b))
            return OVERFLOW;
        out = a + b;
        return OK;
    }

    inline MathCode sub(long long a, long long b, long long& out) {
        if ((b > 0 && a < LLONG_MIN + b) || (b < 0 && a > LLONG_MAX + b))
            return OVERFLOW;
        out = a - b;
        return OK;
    }

    inline MathCode mul(long long a, long long b, long long& out) {
        if (a == 0 || b == 0) {
            out = 0;
            return OK;
        }

        if (a > 0) {
            if (b > 0) { if (a > LLONG_MAX / b) return OVERFLOW; }
            else       { if (b < LLONG_MIN / a) return OVERFLOW; }
        }
        else {
            if (b > 0) { if (a < LLONG_MIN / b) return OVERFLOW; }
            else       { if (a < LLONG_MAX / b) return OVERFLOW; }
        }

        out = a * b;
        return OK;
    }

    inline MathCode div(long long a, long long b, long long& out) {
        if (b == 0) 
            return DIV_BY_ZERO;
        if (a == LLONG_MIN && b == -1) 
            return OVERFLOW;
        out = a / b;
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
