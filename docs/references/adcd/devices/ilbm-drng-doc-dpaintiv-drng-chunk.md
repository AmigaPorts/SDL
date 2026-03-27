---
title: ILBM.DRNG.doc / DPaintIV DRNG chunk
manual: devices
chapter: devices
section: ilbm-drng-doc-dpaintiv-drng-chunk
functions: []
libraries: []
---

# ILBM.DRNG.doc / DPaintIV DRNG chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
       DRNG ::= "DRNG" # { DRange DColor* DIndex* }
```
a <cell> is where the color or register appears within the range

The RNG_ACTIVE flags is set when the range is cyclable. A range
should only have the RNG_ACTIVE if it:
     1> contains at least one color register
     2> has a defined rate
     3> has more than one color and/or color register
If the above conditions are met then RNG_ACTIVE is a user/program
preference.  If the bit is NOT set the program should NOT cycle the
range.

The RNG_DP_RESERVED flags should always be 0!!!

typedef struct {
   UBYTE min;           /* min cell value */
   UBYTE max;           /* max cell value */
   SHORT rate;          /* color cycling rate, 16384 = 60 steps/second */
   SHORT flags;         /* 1=RNG_ACTIVE,4=RNG_DP_RESERVED */
   UBYTE ntrue;         /* number of DColor structs to follow */
   UBYTE nregs;         /* number of DIndex structs to follow */
   } DRange;

typedef struct { UBYTE cell; UBYTE r,g,b; } DColor; /* true color cell */
typedef struct { UBYTE cell; UBYTE index; } DIndex;

                                                /* color register cell */
