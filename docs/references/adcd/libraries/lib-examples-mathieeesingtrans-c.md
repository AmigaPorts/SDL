---
title: lib_examples/mathieeesingtrans.c
manual: libraries
chapter: libraries
section: lib-examples-mathieeesingtrans-c
functions: []
libraries: []
---

# lib_examples/mathieeesingtrans.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#include <exec/types.h>
#include <libraries/mathieeesp.h>

#include <clib/mathsingtrans_protos.h>

struct Library *MathIeeeSingTransBase;

VOID main()
{
FLOAT f1, f2, f3;

if (MathIeeeSingTransBase = OpenLibrary("mathieeesingtrans.library",37))
```c
    {
    f1 = IEEEDPAsin(f2);        /* Call IEEESPAsin entry */
    f1 = IEEEDPAcos(f2);        /* Call IEEESPAcos entry */
    f1 = IEEEDPAtan(f2);        /* Call IEEESPAtan entry */
    f1 = IEEEDPSin(f2);         /* Call IEEESPSin entry */
    f1 = IEEEDPCos(f2);         /* Call IEEESPCos entry */
    f1 = IEEEDPTan(f2);         /* Call IEEESPTan entry */
    f1 = IEEEDPSincos(&f3, f2); /* Call IEEESPSincos entry */
    f1 = IEEEDPSinh(f2);        /* Call IEEESPSinh entry */
    f1 = IEEEDPCosh(f2);        /* Call IEEESPCosh entry */
    f1 = IEEEDPTanh(f2);        /* Call IEEESPTanh entry */
    f1 = IEEEDPExp(f2);         /* Call IEEESPExp entry */
    f1 = IEEEDPLog(f2);         /* Call IEEESPLog entry */
    f1 = IEEEDPLog10(f2);       /* Call IEEESPLog10 entry */
    f1 = IEEEDPPow(d2, f3);     /* Call IEEESPPow entry */
    f1 = IEEEDPSqrt(f2);        /* Call IEEESPSqrt entry */

    CloseLibrary(MathIeeeSingTransBase);
    }
```
else printf("Can't open mathieeesingtrans.library\n");
}

