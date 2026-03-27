---
title: Nonstandard Data Chunks / CCRT
manual: devices
chapter: devices
section: nonstandard-data-chunks-ccrt
functions: []
libraries: []
---

# Nonstandard Data Chunks / CCRT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Commodore's Graphicraft program uses a similar chunk "CCRT" (for Color
Cycling Range and Timing).  This chunk contains a CycleInfo structure.


```c
    typedef struct {
        WORD  direction;    /* 0 = don't cycle.  1 = cycle forwards      */
                            /* (1, 2, 3). -1 = cycle backwards (3, 2, 1) */
        UBYTE start, end;   /* lower and upper color registers selected  */
        LONG  seconds;      /* # seconds between changing colors plus... */
        LONG  microseconds; /* # microseconds between changing colors    */
        WORD  pad;          /* reserved for future use; store 0 here     */
        } CycleInfo;
```
This is very similar to a CRNG chunk.  A program would probably only use
one of these two methods of expressing color cycle data, new programs
should use CRNG.  You could write out both if you want to communicate this
information to both Deluxe Paint and Graphicraft.

