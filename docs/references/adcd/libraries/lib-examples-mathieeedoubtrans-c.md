---
title: lib_examples/mathieeedoubtrans.c
manual: libraries
chapter: libraries
section: lib-examples-mathieeedoubtrans-c
functions: []
libraries: []
---

# lib_examples/mathieeedoubtrans.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#include <exec/types.h>
#include <libraries/mathieeedp.h>
#include <clib/mathdoubtrans_protos.h>

struct Library *MathIeeeDoubTransBase;

VOID main()
{
DOUBLE d1, d2, d3;
FLOAT f1;

if (MathIeeeDoubTransBase = OpenLibrary("mathieeedoubtrans.library",34))
```c
    {
    d1 = IEEEDPAsin(d2);        /* Call IEEEDPAsin entry */
    d1 = IEEEDPAcos(d2);        /* Call IEEEDPAcos entry */
    d1 = IEEEDPAtan(d2);        /* Call IEEEDPAtan entry */
    d1 = IEEEDPSin(d2);         /* Call IEEEDPSin entry */
    d1 = IEEEDPCos(d2);         /* Call IEEEDPCos entry */
    d1 = IEEEDPTan(d2);         /* Call IEEEDPTan entry */
    d1 = IEEEDPSincos(&d3, d2); /* Call IEEEDPSincos entry */
    d1 = IEEEDPSinh(d2);        /* Call IEEEDPSinh entry */
    d1 = IEEEDPCosh(d2);        /* Call IEEEDPCosh entry */
    d1 = IEEEDPTanh(d2);        /* Call IEEEDPTanh entry */
    d1 = IEEEDPExp(d2);         /* Call IEEEDPExp entry */
    d1 = IEEEDPLog(d2);         /* Call IEEEDPLog entry */
    d1 = IEEEDPLog10(d2);       /* Call IEEEDPLog10 entry */
    d1 = IEEEDPPow(d2, d3);     /* Call IEEEDPPow entry */
    d1 = IEEEDPSqrt(d2);        /* Call IEEEDPSqrt entry */
    f1 = IEEEDPTieee(d2);       /* Call IEEEDPTieee entry */
    d1 = IEEEDPFieee(f1);       /* Call IEEEDPFieee entry */

    CloseLibrary(MathIeeeDoubTransBase);
    }
```
else printf("Can't open mathieeedoubtrans.library\n");
}

