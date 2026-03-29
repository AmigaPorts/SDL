/*
  Software IEEE 754 single-precision float division for AmigaOS 3.x.

  libnix's __divsf3 calls mathieeesingbas.library IEEESPDiv which
  crashes on FS-UAE (both A4000/040 and A1200/030 configs). The ROM
  library's jump table or FPU detection is broken under emulation.

  This file provides a pure-integer __divsf3 that works everywhere.
  It overrides the libnix version at link time (our .o comes from
  libSDL2.a which is listed before -lm on the link line).

  Algorithm: standard IEEE 754 binary32 division via integer math.
*/

#include "../SDL_internal.h"

#ifdef __AMIGAOS3__

#include <stdint.h>

/* IEEE 754 single-precision layout:
 * bit 31: sign
 * bits 30-23: exponent (biased by 127)
 * bits 22-0: mantissa (implicit leading 1)
 */

#define SP_SIGN_MASK    0x80000000U
#define SP_EXP_MASK     0x7F800000U
#define SP_MANT_MASK    0x007FFFFFU
#define SP_EXP_BIAS     127
#define SP_EXP_SHIFT    23
#define SP_MANT_BITS    23
#define SP_IMPLICIT_BIT (1U << SP_MANT_BITS)

typedef union {
    float f;
    uint32_t u;
} float_bits;

float __divsf3(float a, float b);

float __divsf3(float a, float b)
{
    float_bits fa, fb, fr;
    uint32_t sign_a, sign_b, sign_r;
    int32_t exp_a, exp_b, exp_r;
    uint32_t mant_a, mant_b;
    uint64_t mant_a64;
    uint32_t mant_r;

    fa.f = a;
    fb.f = b;

    sign_a = fa.u & SP_SIGN_MASK;
    sign_b = fb.u & SP_SIGN_MASK;
    sign_r = sign_a ^ sign_b;

    exp_a = (int32_t)((fa.u & SP_EXP_MASK) >> SP_EXP_SHIFT);
    exp_b = (int32_t)((fb.u & SP_EXP_MASK) >> SP_EXP_SHIFT);

    /* Handle special cases */

    /* NaN or Inf inputs */
    if (exp_a == 255 || exp_b == 255) {
        if (exp_a == 255 && exp_b == 255) {
            /* Inf/Inf or NaN/NaN = NaN */
            fr.u = 0x7FC00000U | sign_r;
            return fr.f;
        }
        if (exp_a == 255) {
            /* Inf/x or NaN/x */
            fr.u = fa.u | sign_r;
            return fr.f;
        }
        /* x/Inf or x/NaN */
        if (fb.u & SP_MANT_MASK) {
            fr.u = fb.u; /* NaN */
            return fr.f;
        }
        /* x / Inf = 0 */
        fr.u = sign_r;
        return fr.f;
    }

    /* Zero dividend */
    if ((fa.u & ~SP_SIGN_MASK) == 0) {
        if ((fb.u & ~SP_SIGN_MASK) == 0) {
            /* 0/0 = NaN */
            fr.u = 0x7FC00000U;
            return fr.f;
        }
        fr.u = sign_r; /* 0 */
        return fr.f;
    }

    /* Zero divisor */
    if ((fb.u & ~SP_SIGN_MASK) == 0) {
        /* x/0 = Inf */
        fr.u = SP_EXP_MASK | sign_r;
        return fr.f;
    }

    /* Normal division */
    mant_a = (fa.u & SP_MANT_MASK) | SP_IMPLICIT_BIT;
    mant_b = (fb.u & SP_MANT_MASK) | SP_IMPLICIT_BIT;

    /* Handle denormals (exp == 0) */
    if (exp_a == 0) { exp_a = 1; mant_a = fa.u & SP_MANT_MASK; }
    if (exp_b == 0) { exp_b = 1; mant_b = fb.u & SP_MANT_MASK; }

    /* Compute result exponent */
    exp_r = exp_a - exp_b + SP_EXP_BIAS;

    /* Mantissa division: shift dividend left by 23 bits for precision */
    mant_a64 = (uint64_t)mant_a << SP_MANT_BITS;
    mant_r = (uint32_t)(mant_a64 / mant_b);

    /* Normalize: if mant_r >= 2.0 (bit 24 set), shift right */
    if (mant_r & (SP_IMPLICIT_BIT << 1)) {
        mant_r >>= 1;
        exp_r++;
    }
    /* If mant_r < 1.0 (bit 23 not set), shift left */
    while (mant_r && !(mant_r & SP_IMPLICIT_BIT)) {
        mant_r <<= 1;
        exp_r--;
    }

    /* Overflow -> Inf */
    if (exp_r >= 255) {
        fr.u = SP_EXP_MASK | sign_r;
        return fr.f;
    }

    /* Underflow -> 0 */
    if (exp_r <= 0) {
        fr.u = sign_r;
        return fr.f;
    }

    /* Assemble result */
    fr.u = sign_r | ((uint32_t)exp_r << SP_EXP_SHIFT) | (mant_r & SP_MANT_MASK);
    return fr.f;
}

#endif /* __AMIGAOS3__ */
