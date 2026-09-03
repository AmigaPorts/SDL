/*
  Software IEEE 754 single-precision float operations for AmigaOS 3.x.

  libnix's __divsf3, __mulsf3, __addsf3, __subsf3 call through
  mathieeesingbas.library (IEEESPDiv, IEEESPMul, IEEESPAdd, IEEESPSub).
  These ROM functions crash on FS-UAE due to broken library emulation.

  This file provides pure-integer implementations that work everywhere.
  They override the libnix versions at link time (libSDL2.a comes
  before -lm on the link line).

  Algorithm: standard IEEE 754 binary32 arithmetic via integer math.
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

/* --- __mulsf3: float multiplication --- */

float __mulsf3(float a, float b);

float __mulsf3(float a, float b)
{
    float_bits fa, fb, fr;
    uint32_t sign_r;
    int32_t exp_a, exp_b, exp_r;
    uint32_t mant_a, mant_b;
    uint64_t mant_r64;
    uint32_t mant_r;

    fa.f = a;
    fb.f = b;

    sign_r = (fa.u ^ fb.u) & SP_SIGN_MASK;

    exp_a = (int32_t)((fa.u & SP_EXP_MASK) >> SP_EXP_SHIFT);
    exp_b = (int32_t)((fb.u & SP_EXP_MASK) >> SP_EXP_SHIFT);

    /* Zero */
    if ((fa.u & ~SP_SIGN_MASK) == 0 || (fb.u & ~SP_SIGN_MASK) == 0) {
        fr.u = sign_r;
        return fr.f;
    }
    /* NaN/Inf */
    if (exp_a == 255 || exp_b == 255) {
        if ((fa.u & SP_MANT_MASK) || (fb.u & SP_MANT_MASK)) {
            fr.u = 0x7FC00000U; return fr.f; /* NaN */
        }
        fr.u = SP_EXP_MASK | sign_r; return fr.f; /* Inf */
    }

    mant_a = (fa.u & SP_MANT_MASK) | SP_IMPLICIT_BIT;
    mant_b = (fb.u & SP_MANT_MASK) | SP_IMPLICIT_BIT;

    if (exp_a == 0) { exp_a = 1; mant_a = fa.u & SP_MANT_MASK; }
    if (exp_b == 0) { exp_b = 1; mant_b = fb.u & SP_MANT_MASK; }

    exp_r = exp_a + exp_b - SP_EXP_BIAS;

    mant_r64 = (uint64_t)mant_a * mant_b;
    /* Result has 46 mantissa bits (23+23). Shift right by 23 to get 23. */
    mant_r = (uint32_t)(mant_r64 >> SP_MANT_BITS);

    /* Normalize */
    if (mant_r & (SP_IMPLICIT_BIT << 1)) {
        mant_r >>= 1;
        exp_r++;
    }
    while (mant_r && !(mant_r & SP_IMPLICIT_BIT)) {
        mant_r <<= 1;
        exp_r--;
    }

    if (exp_r >= 255) { fr.u = SP_EXP_MASK | sign_r; return fr.f; }
    if (exp_r <= 0) { fr.u = sign_r; return fr.f; }

    fr.u = sign_r | ((uint32_t)exp_r << SP_EXP_SHIFT) | (mant_r & SP_MANT_MASK);
    return fr.f;
}

/* --- __addsf3: float addition --- */

float __addsf3(float a, float b);

float __addsf3(float a, float b)
{
    float_bits fa, fb, fr;
    int32_t exp_a, exp_b, exp_r;
    int32_t mant_a, mant_b, mant_r;
    int shift;

    fa.f = a;
    fb.f = b;

    /* NaN */
    if (((fa.u & SP_EXP_MASK) == SP_EXP_MASK && (fa.u & SP_MANT_MASK)) ||
        ((fb.u & SP_EXP_MASK) == SP_EXP_MASK && (fb.u & SP_MANT_MASK))) {
        fr.u = 0x7FC00000U; return fr.f;
    }

    /* Zero cases */
    if ((fa.u & ~SP_SIGN_MASK) == 0) return b;
    if ((fb.u & ~SP_SIGN_MASK) == 0) return a;

    /* Extract with sign (as signed mantissa) */
    exp_a = (int32_t)((fa.u & SP_EXP_MASK) >> SP_EXP_SHIFT);
    exp_b = (int32_t)((fb.u & SP_EXP_MASK) >> SP_EXP_SHIFT);
    mant_a = (int32_t)((fa.u & SP_MANT_MASK) | SP_IMPLICIT_BIT);
    mant_b = (int32_t)((fb.u & SP_MANT_MASK) | SP_IMPLICIT_BIT);
    if (exp_a == 0) { exp_a = 1; mant_a = (int32_t)(fa.u & SP_MANT_MASK); }
    if (exp_b == 0) { exp_b = 1; mant_b = (int32_t)(fb.u & SP_MANT_MASK); }
    if (fa.u & SP_SIGN_MASK) mant_a = -mant_a;
    if (fb.u & SP_SIGN_MASK) mant_b = -mant_b;

    /* Align exponents */
    if (exp_a > exp_b) {
        shift = exp_a - exp_b;
        if (shift > 24) mant_b = 0; else mant_b >>= shift;
        exp_r = exp_a;
    } else {
        shift = exp_b - exp_a;
        if (shift > 24) mant_a = 0; else mant_a >>= shift;
        exp_r = exp_b;
    }

    mant_r = mant_a + mant_b;

    if (mant_r == 0) { fr.u = 0; return fr.f; }

    /* Handle sign */
    fr.u = 0;
    if (mant_r < 0) {
        fr.u = SP_SIGN_MASK;
        mant_r = -mant_r;
    }

    /* Normalize */
    while (mant_r & (SP_IMPLICIT_BIT << 1)) {
        mant_r >>= 1;
        exp_r++;
    }
    while (mant_r && !(mant_r & SP_IMPLICIT_BIT)) {
        mant_r <<= 1;
        exp_r--;
    }

    if (exp_r >= 255) { fr.u |= SP_EXP_MASK; return fr.f; }
    if (exp_r <= 0) { fr.u = 0; return fr.f; }

    fr.u |= ((uint32_t)exp_r << SP_EXP_SHIFT) | ((uint32_t)mant_r & SP_MANT_MASK);
    return fr.f;
}

/* --- __subsf3: float subtraction --- */

float __subsf3(float a, float b);

float __subsf3(float a, float b)
{
    float_bits fb;
    fb.f = b;
    fb.u ^= SP_SIGN_MASK; /* negate b */
    return __addsf3(a, fb.f);
}

/* --- __fixsfsi: float to int conversion --- */

int __fixsfsi(float a);

int __fixsfsi(float a)
{
    float_bits fa;
    int32_t exp, mant;

    fa.f = a;
    exp = (int32_t)((fa.u & SP_EXP_MASK) >> SP_EXP_SHIFT) - SP_EXP_BIAS;

    if (exp < 0) return 0;
    if (exp >= 31) return (fa.u & SP_SIGN_MASK) ? (-2147483647 - 1) : 2147483647;

    mant = (int32_t)((fa.u & SP_MANT_MASK) | SP_IMPLICIT_BIT);

    if (exp >= SP_MANT_BITS) {
        mant <<= (exp - SP_MANT_BITS);
    } else {
        mant >>= (SP_MANT_BITS - exp);
    }

    return (fa.u & SP_SIGN_MASK) ? -mant : mant;
}

/* --- __floatsisf: int to float conversion --- */

float __floatsisf(int a);

float __floatsisf(int a)
{
    float_bits fr;
    uint32_t sign = 0;
    uint32_t ua;
    int32_t exp;

    if (a == 0) { fr.u = 0; return fr.f; }

    if (a < 0) { sign = SP_SIGN_MASK; ua = (uint32_t)(-a); }
    else { ua = (uint32_t)a; }

    exp = SP_EXP_BIAS + 31;

    /* Normalize: shift left until bit 31 is set */
    while (!(ua & 0x80000000U)) { ua <<= 1; exp--; }

    /* Round: we have 32 bits, need 23 mantissa + 1 implicit = 24 */
    ua >>= 8; /* shift to get 24 bits */
    exp -= (31 - SP_MANT_BITS - 8); /* adjust exponent... */
    /* Actually: after shifting 32-bit value right by 8, we have 24 bits.
     * The implicit bit is bit 23. exp needs adjustment. */
    exp = SP_EXP_BIAS + SP_MANT_BITS;
    ua = (uint32_t)a;
    if (a < 0) ua = (uint32_t)(-a);

    /* Simple approach: count leading zeros */
    exp = SP_EXP_BIAS + 31;
    while (!(ua & 0x80000000U)) { ua <<= 1; exp--; }
    /* Now bit 31 is set. Shift right by (31-23)=8 to get 24-bit mantissa */
    ua >>= 8;

    fr.u = sign | ((uint32_t)exp << SP_EXP_SHIFT) | (ua & SP_MANT_MASK);
    return fr.f;
}

/* --- __cmpsf2, __eqsf2, __nesf2, __gtsf2, __gesf2, __ltsf2, __lesf2 --- */

int __cmpsf2(float a, float b);

int __cmpsf2(float a, float b)
{
    float_bits fa, fb;
    fa.f = a;
    fb.f = b;

    /* Both zero */
    if ((fa.u & ~SP_SIGN_MASK) == 0 && (fb.u & ~SP_SIGN_MASK) == 0) return 0;

    /* NaN */
    if (((fa.u & SP_EXP_MASK) == SP_EXP_MASK && (fa.u & SP_MANT_MASK)) ||
        ((fb.u & SP_EXP_MASK) == SP_EXP_MASK && (fb.u & SP_MANT_MASK)))
        return 1; /* unordered */

    /* Both positive: compare as integers */
    if (!(fa.u & SP_SIGN_MASK) && !(fb.u & SP_SIGN_MASK)) {
        if (fa.u > fb.u) return 1;
        if (fa.u < fb.u) return -1;
        return 0;
    }
    /* Both negative: reverse comparison */
    if ((fa.u & SP_SIGN_MASK) && (fb.u & SP_SIGN_MASK)) {
        if (fa.u > fb.u) return -1;
        if (fa.u < fb.u) return 1;
        return 0;
    }
    /* Different signs */
    return (fa.u & SP_SIGN_MASK) ? -1 : 1;
}

int __eqsf2(float a, float b);
int __eqsf2(float a, float b) { return __cmpsf2(a, b); }

int __nesf2(float a, float b);
int __nesf2(float a, float b) { return __cmpsf2(a, b); }

int __gtsf2(float a, float b);
int __gtsf2(float a, float b) { return __cmpsf2(a, b); }

int __gesf2(float a, float b);
int __gesf2(float a, float b) { return __cmpsf2(a, b); }

int __ltsf2(float a, float b);
int __ltsf2(float a, float b) { return __cmpsf2(a, b); }

int __lesf2(float a, float b);
int __lesf2(float a, float b) { return __cmpsf2(a, b); }

#endif /* __AMIGAOS3__ */
