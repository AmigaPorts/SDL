---
title: Nonstandard Data Chunks / CRNG
manual: devices
chapter: devices
section: nonstandard-data-chunks-crng
functions: []
libraries: []
---

# Nonstandard Data Chunks / CRNG

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A "CRNG" chunk contains "color register range" information.  It's used by
Electronic Arts' Deluxe Paint program to identify a contiguous range of
color registers for a "shade range" and color cycling.  There can be zero
or more CRNG chunks in an ILBM, but all should appear before the [BODY](devices/standard-body-data-chunk-body.md)
chunk. Deluxe Paint normally writes 4 CRNG chunks in an ILBM when the user
asks it to "Save Picture".


```c
    typedef struct {
        WORD  pad1;      /* reserved for future use; store 0 here    */
        WORD  rate;      /* color cycle rate                         */
        WORD  flags;     /* see below                                */
        UBYTE low, high; /* lower and upper color registers selected */
        } CRange;
```
The bits of the flags word are interpreted as follows: if the low bit is
set then the cycle is "active", and if this bit is clear it is not active.
Normally, color cycling is done so that colors move to the next higher
position in the cycle, with the color in the high slot moving around to
the low slot.  If the second bit of the flags word is set, the cycle moves
in the opposite direction.  As usual, the other bits of the flags word are
reserved for future expansion.  Here are the masks to test these bits:

	#define RNG_ACTIVE  1
	#define RNG_REVERSE 2

The fields low and high indicate the range of color registers (color
numbers) selected by this CRange.

The field active indicates whether color cycling is on or off.  Zero means
off.

The field rate determines the speed at which the colors will step when
color cycling is on.  The units are such that a rate of 60 steps per
second is represented as 2^14 = 16384.  Slower rates can be obtained by
linear scaling: for 30 steps/second, rate = 8192; for 1 step/second, rate
= 16384/60 * 273.

