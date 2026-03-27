---
title: 8SVX IFF 8-Bit Sampled Voice / Appendix C. Fibonacci Delta Compression
manual: devices
chapter: devices
section: 8svx-iff-8-bit-sampled-voice-appendix-c-fibonacci-delta
functions: []
libraries: []
---

# 8SVX IFF 8-Bit Sampled Voice / Appendix C. Fibonacci Delta Compression

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is Steve Hayes' Fibonacci Delta sound compression technique.  It's
like the traditional delta encoding but encodes each delta in a mere 4
bits.  The compressed data is half the size of the original data plus a
2-byte overhead for the initial value.  This much compression introduces
some distortion, so try it out and use it with discretion.

To achieve a reasonable slew rate, this algorithm looks up each stored
4-bit value in a table of Fibonacci numbers.  So very small deltas are
encoded precisely while larger deltas are approximated.  When it has to
make approximations, the compressor should adjust all the values (forwards
and backwards in time) for minimum overall distortion.

Here is the decompressor written in the C programming language.


```c
    /* Fibonacci delta encoding for sound data. */
    BYTE codeToDelta[16] = {-34,-21,-13,-8,-5,-3,-2,-1,0,1,2,3,5,8,13,21};

    /* Unpack Fibonacci-delta encoded data from n byte source buffer into
     * 2*n byte dest buffer, given initial data value x.  It returns the
     * last data value x so you can call it several times to incrementally
     * decompress the data.                                             */
    short D1Unpack(source, n, dest, x)
        BYTE source[], dest[];
        LONG n;
        BYTE x;
        {
        BYTE d;
        LONG i, lim;

        lim = n << 1;
        for (i = 0; i < lim; ++i)
                { /* Decode a data nybble; high nybble then low nybble. */
                d = source[i >> 1];     /* get a pair of nybbles        */
                if (i & 1)              /* select low or high nybble?   */
                        d &= 0xf;       /* mask to get the low nybble   */
                else
                        d >>= 4;        /* shift to get the high nybble */
                x += codeToDelta[d];    /* add in the decoded delta     */
                dest[i] = x;            /* store a 1-byte sample        */
                }
        return(x);
        }

    /* Unpack Fibonacci-delta encoded data from n byte source buffer into
     * 2*(n-2) byte dest buffer. Source buffer has a pad byte, an 8-bit
     * initial value, followed by n-2 bytes comprising 2*(n-2) 4-bit
     * encoded samples.                                                 */

    void DUnpack(source, n, dest)
        BYTE source[], dest[];
        LONG n;
        {
          D1Unpack(source + 2, n - 2, dest, source[1]);
        }
```
