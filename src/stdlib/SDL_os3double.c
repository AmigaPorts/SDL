/*
  Software IEEE 754 double-precision math operations for AmigaOS 3.x.

  libnix's __divdf3, __muldf3, __adddf3, __subdf3 call through
  mathieeedoubbas.library (IEEEDPDiv, IEEEDPMul, IEEEDPAdd, IEEEDPSub).
  These ROM functions crash on FS-UAE due to broken library emulation.

  This file provides pure-integer implementations that work everywhere.
  They override the libnix versions at link time (libSDL2.a comes
  before -lm on the link line).

  Algorithm: standard IEEE 754 binary64 arithmetic via integer math.
*/

#include "../SDL_internal.h"

#ifdef __AMIGAOS3__

#include <stdint.h>

/* IEEE 754 double-precision (binary64) layout:
 * bit 63: sign
 * bits 62-52: exponent (biased by 1023, 11 bits)
 * bits 51-0: mantissa (52 bits, implicit leading 1 for normals)
 */

#define DP_SIGN_MASK    0x8000000000000000ULL
#define DP_EXP_MASK     0x7FF0000000000000ULL
#define DP_MANT_MASK    0x000FFFFFFFFFFFFFULL
#define DP_EXP_BIAS     1023
#define DP_EXP_SHIFT    52
#define DP_MANT_BITS    52
#define DP_IMPLICIT_BIT (1ULL << DP_MANT_BITS)

typedef union {
    double d;
    uint64_t u;
} double_bits;

/* --- Helper: 64-bit division via bit-by-bit shift-subtract ---
 *
 * Divides a 53-bit dividend (with implicit bit) by a 53-bit divisor,
 * producing a 53-bit quotient with the binary point after bit 52.
 * This gives us the 52 mantissa bits we need.
 *
 * Algorithm: standard binary long division. We shift the dividend
 * left one bit at a time and subtract the divisor when possible.
 * We do this for 53 iterations to get 53 quotient bits.
 */
static uint64_t dp_mant_div(uint64_t dividend, uint64_t divisor)
{
    uint64_t quotient = 0;
    uint64_t remainder = 0;
    int i;

    /* We need 53 bits of quotient (1 integer + 52 fraction).
     * The dividend starts as a 53-bit value (bit 52 = implicit).
     * We process 53 bits of the dividend, then 52 more fraction bits. */
    for (i = 0; i < 53 + 52; i++) {
        remainder <<= 1;
        if (i < 53) {
            /* Feed in bits of dividend from MSB to LSB */
            if (dividend & (1ULL << (52 - i))) {
                remainder |= 1;
            }
        }
        quotient <<= 1;
        if (remainder >= divisor) {
            remainder -= divisor;
            quotient |= 1;
        }
    }
    return quotient;
}

/* --- dp_is_nan: check if double is NaN --- */

static int dp_is_nan(uint64_t u)
{
    return ((u & DP_EXP_MASK) == DP_EXP_MASK) && (u & DP_MANT_MASK);
}

/* --- dp_is_zero: check if double is zero --- */

static int dp_is_zero(uint64_t u)
{
    return (u & ~DP_SIGN_MASK) == 0;
}

/* --- dp_normalize: normalize mantissa and adjust exponent --- */

static void dp_normalize(uint64_t *mant, int32_t *exp)
{
    if (*mant == 0) return;
    while (*mant & (DP_IMPLICIT_BIT << 1)) {
        *mant >>= 1;
        (*exp)++;
    }
    while (*mant && !(*mant & DP_IMPLICIT_BIT)) {
        *mant <<= 1;
        (*exp)--;
    }
}

/* --- dp_pack: assemble sign, exponent, mantissa into double --- */

static double dp_pack(uint64_t sign, int32_t exp, uint64_t mant)
{
    double_bits fr;
    if (exp >= 2047) {
        fr.u = DP_EXP_MASK | sign;
        return fr.d;
    }
    if (exp <= 0) {
        fr.u = sign;
        return fr.d;
    }
    fr.u = sign | ((uint64_t)exp << DP_EXP_SHIFT) | (mant & DP_MANT_MASK);
    return fr.d;
}

/* --- __divdf3: double division --- */

double __divdf3(double a, double b);

double __divdf3(double a, double b)
{
    double_bits fa, fb;
    uint64_t sign_r;
    int32_t exp_a, exp_b, exp_r;
    uint64_t mant_a, mant_b, mant_r;

    fa.d = a;
    fb.d = b;

    sign_r = (fa.u ^ fb.u) & DP_SIGN_MASK;

    exp_a = (int32_t)((fa.u & DP_EXP_MASK) >> DP_EXP_SHIFT);
    exp_b = (int32_t)((fb.u & DP_EXP_MASK) >> DP_EXP_SHIFT);

    /* NaN or Inf inputs */
    if (exp_a == 2047 || exp_b == 2047) {
        double_bits fr;
        if (exp_a == 2047 && exp_b == 2047) {
            fr.u = 0x7FF8000000000000ULL | sign_r;
            return fr.d;
        }
        if (exp_a == 2047) {
            fr.u = fa.u | sign_r;
            return fr.d;
        }
        if (dp_is_nan(fb.u)) { fr.u = fb.u; return fr.d; }
        fr.u = sign_r; /* x / Inf = 0 */
        return fr.d;
    }

    /* Zero dividend */
    if (dp_is_zero(fa.u)) {
        double_bits fr;
        if (dp_is_zero(fb.u)) {
            fr.u = 0x7FF8000000000000ULL;
            return fr.d;
        }
        fr.u = sign_r;
        return fr.d;
    }

    /* Zero divisor */
    if (dp_is_zero(fb.u)) {
        return dp_pack(sign_r, 2047, 0);
    }

    /* Extract mantissas with implicit bit */
    mant_a = (fa.u & DP_MANT_MASK) | DP_IMPLICIT_BIT;
    mant_b = (fb.u & DP_MANT_MASK) | DP_IMPLICIT_BIT;
    if (exp_a == 0) { exp_a = 1; mant_a = fa.u & DP_MANT_MASK; }
    if (exp_b == 0) { exp_b = 1; mant_b = fb.u & DP_MANT_MASK; }

    exp_r = exp_a - exp_b + DP_EXP_BIAS;

    /* Bit-by-bit long division for 52-bit precision */
    mant_r = dp_mant_div(mant_a, mant_b);

    dp_normalize(&mant_r, &exp_r);
    return dp_pack(sign_r, exp_r, mant_r);
}

/* --- __muldf3: double multiplication --- */

/* Helper: multiply two 53-bit mantissas using 32-bit pieces.
 * Returns the upper 53 bits of the 106-bit product. */
static uint64_t dp_mant_mul(uint64_t a, uint64_t b)
{
    /* Split each 53-bit value into high and low 32-bit halves.
     * a = ah * 2^32 + al, b = bh * 2^32 + bl
     * a*b = ah*bh*2^64 + (ah*bl + al*bh)*2^32 + al*bl
     * We need bits [105:52] of the result. */
    uint32_t al = (uint32_t)(a & 0xFFFFFFFFULL);
    uint32_t ah = (uint32_t)(a >> 32);
    uint32_t bl = (uint32_t)(b & 0xFFFFFFFFULL);
    uint32_t bh = (uint32_t)(b >> 32);

    uint64_t ll = (uint64_t)al * bl;
    uint64_t lh = (uint64_t)al * bh;
    uint64_t hl = (uint64_t)ah * bl;
    uint64_t hh = (uint64_t)ah * bh;

    /* Accumulate cross terms with carry */
    uint64_t mid = lh + hl + (ll >> 32);
    uint64_t high = hh + (mid >> 32);

    /* The full product has bits [105:0].
     * high has bits [105:64], mid&0xFFFFFFFF has bits [63:32].
     * We need to shift right by 52 to get 53+1 bits of quotient.
     * Reconstruct bits [105:52]: */
    uint64_t result = (high << 12) | ((mid & 0xFFFFFFFFULL) >> 20);
    return result;
}

double __muldf3(double a, double b);

double __muldf3(double a, double b)
{
    double_bits fa, fb, fr;
    uint64_t sign_r;
    int32_t exp_a, exp_b, exp_r;
    uint64_t mant_a, mant_b, mant_r;

    fa.d = a;
    fb.d = b;

    sign_r = (fa.u ^ fb.u) & DP_SIGN_MASK;

    /* Zero */
    if (dp_is_zero(fa.u) || dp_is_zero(fb.u)) {
        fr.u = sign_r;
        return fr.d;
    }

    exp_a = (int32_t)((fa.u & DP_EXP_MASK) >> DP_EXP_SHIFT);
    exp_b = (int32_t)((fb.u & DP_EXP_MASK) >> DP_EXP_SHIFT);

    /* NaN/Inf */
    if (exp_a == 2047 || exp_b == 2047) {
        if (dp_is_nan(fa.u) || dp_is_nan(fb.u)) {
            fr.u = 0x7FF8000000000000ULL;
            return fr.d;
        }
        fr.u = DP_EXP_MASK | sign_r;
        return fr.d;
    }

    mant_a = (fa.u & DP_MANT_MASK) | DP_IMPLICIT_BIT;
    mant_b = (fb.u & DP_MANT_MASK) | DP_IMPLICIT_BIT;
    if (exp_a == 0) { exp_a = 1; mant_a = fa.u & DP_MANT_MASK; }
    if (exp_b == 0) { exp_b = 1; mant_b = fb.u & DP_MANT_MASK; }

    exp_r = exp_a + exp_b - DP_EXP_BIAS;

    /* Multiply mantissas: 53 * 53 = 106 bits. Take upper 53. */
    mant_r = dp_mant_mul(mant_a, mant_b);

    dp_normalize(&mant_r, &exp_r);
    return dp_pack(sign_r, exp_r, mant_r);
}

/* --- __adddf3: double addition --- */

double __adddf3(double a, double b);

double __adddf3(double a, double b)
{
    double_bits fa, fb, fr;
    int32_t exp_a, exp_b, exp_r;
    int64_t mant_a, mant_b, mant_r;
    int shift;

    fa.d = a;
    fb.d = b;

    /* NaN */
    if (dp_is_nan(fa.u) || dp_is_nan(fb.u)) {
        fr.u = 0x7FF8000000000000ULL;
        return fr.d;
    }

    /* Zero cases */
    if (dp_is_zero(fa.u)) return b;
    if (dp_is_zero(fb.u)) return a;

    /* Extract exponents and signed mantissas */
    exp_a = (int32_t)((fa.u & DP_EXP_MASK) >> DP_EXP_SHIFT);
    exp_b = (int32_t)((fb.u & DP_EXP_MASK) >> DP_EXP_SHIFT);
    mant_a = (int64_t)((fa.u & DP_MANT_MASK) | DP_IMPLICIT_BIT);
    mant_b = (int64_t)((fb.u & DP_MANT_MASK) | DP_IMPLICIT_BIT);
    if (exp_a == 0) { exp_a = 1; mant_a = (int64_t)(fa.u & DP_MANT_MASK); }
    if (exp_b == 0) { exp_b = 1; mant_b = (int64_t)(fb.u & DP_MANT_MASK); }
    if (fa.u & DP_SIGN_MASK) mant_a = -mant_a;
    if (fb.u & DP_SIGN_MASK) mant_b = -mant_b;

    /* Align exponents */
    if (exp_a > exp_b) {
        shift = exp_a - exp_b;
        if (shift > 54) mant_b = 0; else mant_b >>= shift;
        exp_r = exp_a;
    } else {
        shift = exp_b - exp_a;
        if (shift > 54) mant_a = 0; else mant_a >>= shift;
        exp_r = exp_b;
    }

    mant_r = mant_a + mant_b;

    if (mant_r == 0) { fr.u = 0; return fr.d; }

    /* Handle sign */
    fr.u = 0;
    if (mant_r < 0) {
        fr.u = DP_SIGN_MASK;
        mant_r = -mant_r;
    }

    /* Normalize */
    {
        uint64_t umant = (uint64_t)mant_r;
        dp_normalize(&umant, &exp_r);
        fr.u |= ((uint64_t)exp_r << DP_EXP_SHIFT) | (umant & DP_MANT_MASK);
        if (exp_r >= 2047) { fr.u = (fr.u & DP_SIGN_MASK) | DP_EXP_MASK; }
        if (exp_r <= 0) { fr.u &= DP_SIGN_MASK; }
    }

    return fr.d;
}

/* --- __subdf3: double subtraction --- */

double __subdf3(double a, double b);

double __subdf3(double a, double b)
{
    double_bits fb;
    fb.d = b;
    fb.u ^= DP_SIGN_MASK; /* negate b */
    return __adddf3(a, fb.d);
}

/* --- __fixdfsi: double to int conversion --- */

int __fixdfsi(double a);

int __fixdfsi(double a)
{
    double_bits fa;
    int32_t exp;
    int64_t mant;

    fa.d = a;
    exp = (int32_t)((fa.u & DP_EXP_MASK) >> DP_EXP_SHIFT) - DP_EXP_BIAS;

    if (exp < 0) return 0;
    if (exp >= 31) {
        return (fa.u & DP_SIGN_MASK) ? (-2147483647 - 1) : 2147483647;
    }

    mant = (int64_t)((fa.u & DP_MANT_MASK) | DP_IMPLICIT_BIT);

    if (exp >= DP_MANT_BITS) {
        mant <<= (exp - DP_MANT_BITS);
    } else {
        mant >>= (DP_MANT_BITS - exp);
    }

    return (int)((fa.u & DP_SIGN_MASK) ? -mant : mant);
}

/* --- __fixunsdfsi: double to unsigned int conversion --- */

unsigned int __fixunsdfsi(double a);

unsigned int __fixunsdfsi(double a)
{
    double_bits fa;
    int32_t exp;
    uint64_t mant;

    fa.d = a;

    /* Negative -> 0 */
    if (fa.u & DP_SIGN_MASK) return 0;

    exp = (int32_t)((fa.u & DP_EXP_MASK) >> DP_EXP_SHIFT) - DP_EXP_BIAS;

    if (exp < 0) return 0;
    if (exp >= 32) return 0xFFFFFFFFU;

    mant = (fa.u & DP_MANT_MASK) | DP_IMPLICIT_BIT;

    if (exp >= DP_MANT_BITS) {
        mant <<= (exp - DP_MANT_BITS);
    } else {
        mant >>= (DP_MANT_BITS - exp);
    }

    return (unsigned int)mant;
}

/* --- __floatsidf: int to double conversion --- */

double __floatsidf(int a);

double __floatsidf(int a)
{
    double_bits fr;
    uint64_t sign = 0;
    uint32_t ua;
    int32_t exp;

    if (a == 0) { fr.u = 0; return fr.d; }

    if (a < 0) { sign = DP_SIGN_MASK; ua = (uint32_t)(-a); }
    else { ua = (uint32_t)a; }

    /* Normalize: count leading zeros */
    exp = DP_EXP_BIAS + 31;
    while (!(ua & 0x80000000U)) { ua <<= 1; exp--; }

    /* We have 32 bits with MSB set. Shift left to fill 52-bit mantissa.
     * Need to place bit 31 of ua at bit 52 of mantissa. */
    fr.u = sign | ((uint64_t)exp << DP_EXP_SHIFT) |
           (((uint64_t)ua << 21) & DP_MANT_MASK);
    return fr.d;
}

/* --- __floatunsidf: unsigned int to double conversion --- */

double __floatunsidf(unsigned int a);

double __floatunsidf(unsigned int a)
{
    double_bits fr;
    uint32_t ua = a;
    int32_t exp;

    if (a == 0) { fr.u = 0; return fr.d; }

    exp = DP_EXP_BIAS + 31;
    while (!(ua & 0x80000000U)) { ua <<= 1; exp--; }

    fr.u = ((uint64_t)exp << DP_EXP_SHIFT) |
           (((uint64_t)ua << 21) & DP_MANT_MASK);
    return fr.d;
}

/* --- __cmpdf2: double comparison --- */

int __cmpdf2(double a, double b);

int __cmpdf2(double a, double b)
{
    double_bits fa, fb;
    fa.d = a;
    fb.d = b;

    /* Both zero */
    if (dp_is_zero(fa.u) && dp_is_zero(fb.u)) return 0;

    /* NaN -> unordered */
    if (dp_is_nan(fa.u) || dp_is_nan(fb.u)) return 1;

    /* Both positive: compare as integers (IEEE 754 is ordered) */
    if (!(fa.u & DP_SIGN_MASK) && !(fb.u & DP_SIGN_MASK)) {
        if (fa.u > fb.u) return 1;
        if (fa.u < fb.u) return -1;
        return 0;
    }
    /* Both negative: reverse comparison */
    if ((fa.u & DP_SIGN_MASK) && (fb.u & DP_SIGN_MASK)) {
        if (fa.u > fb.u) return -1;
        if (fa.u < fb.u) return 1;
        return 0;
    }
    /* Different signs */
    return (fa.u & DP_SIGN_MASK) ? -1 : 1;
}

int __eqdf2(double a, double b);
int __eqdf2(double a, double b) { return __cmpdf2(a, b); }

int __nedf2(double a, double b);
int __nedf2(double a, double b) { return __cmpdf2(a, b); }

int __gtdf2(double a, double b);
int __gtdf2(double a, double b) { return __cmpdf2(a, b); }

int __gedf2(double a, double b);
int __gedf2(double a, double b) { return __cmpdf2(a, b); }

int __ltdf2(double a, double b);
int __ltdf2(double a, double b) { return __cmpdf2(a, b); }

int __ledf2(double a, double b);
int __ledf2(double a, double b) { return __cmpdf2(a, b); }

/* --- __extendsfdf2: float to double conversion --- */

double __extendsfdf2(float a);

double __extendsfdf2(float a)
{
    /* Single-precision constants */
    uint32_t sp_sign_mask = 0x80000000U;
    uint32_t sp_exp_mask = 0x7F800000U;
    uint32_t sp_mant_mask = 0x007FFFFFU;
    int32_t sp_exp_bias = 127;

    double_bits fr;
    union { float f; uint32_t u; } fa;
    uint64_t sign;
    int32_t exp;
    uint64_t mant;

    fa.f = a;
    sign = (fa.u & sp_sign_mask) ? DP_SIGN_MASK : 0;
    exp = (int32_t)((fa.u & sp_exp_mask) >> 23);
    mant = (uint64_t)(fa.u & sp_mant_mask);

    /* Zero */
    if (exp == 0 && mant == 0) {
        fr.u = sign;
        return fr.d;
    }

    /* NaN/Inf */
    if (exp == 255) {
        fr.u = sign | DP_EXP_MASK | (mant << 29);
        return fr.d;
    }

    /* Denormal */
    if (exp == 0) {
        exp = 1;
        while (!(mant & 0x00800000U)) { mant <<= 1; exp--; }
        mant &= sp_mant_mask;
    }

    /* Convert exponent: remove SP bias, add DP bias */
    exp = exp - sp_exp_bias + DP_EXP_BIAS;

    /* Mantissa: 23 bits -> 52 bits (shift left by 29) */
    fr.u = sign | ((uint64_t)exp << DP_EXP_SHIFT) | (mant << 29);
    return fr.d;
}

/* --- __truncdfsf2: double to float conversion --- */

float __truncdfsf2(double a);

float __truncdfsf2(double a)
{
    uint32_t sp_sign_mask = 0x80000000U;
    uint32_t sp_exp_mask = 0x7F800000U;

    double_bits fa;
    union { float f; uint32_t u; } fr;
    uint32_t sign;
    int32_t exp;
    uint32_t mant;

    fa.d = a;
    sign = (fa.u & DP_SIGN_MASK) ? sp_sign_mask : 0;
    exp = (int32_t)((fa.u & DP_EXP_MASK) >> DP_EXP_SHIFT);

    /* Zero */
    if (dp_is_zero(fa.u)) {
        fr.u = sign;
        return fr.f;
    }

    /* NaN/Inf */
    if (exp == 2047) {
        if (dp_is_nan(fa.u)) {
            fr.u = 0x7FC00000U | sign;
            return fr.f;
        }
        fr.u = sp_exp_mask | sign;
        return fr.f;
    }

    /* Convert exponent: remove DP bias, add SP bias */
    exp = exp - DP_EXP_BIAS + 127;

    /* Overflow -> Inf */
    if (exp >= 255) {
        fr.u = sp_exp_mask | sign;
        return fr.f;
    }

    /* Underflow -> 0 */
    if (exp <= 0) {
        fr.u = sign;
        return fr.f;
    }

    /* Mantissa: 52 bits -> 23 bits (shift right by 29) */
    mant = (uint32_t)((fa.u & DP_MANT_MASK) >> 29);

    fr.u = sign | ((uint32_t)exp << 23) | (mant & 0x007FFFFFU);
    return fr.f;
}

#endif /* __AMIGAOS3__ */
