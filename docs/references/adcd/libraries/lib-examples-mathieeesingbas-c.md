---
title: lib_examples/mathieeesingbas.c
manual: libraries
chapter: libraries
section: lib-examples-mathieeesingbas-c
functions: []
libraries: []
---

# lib_examples/mathieeesingbas.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#include <exec/types.h>
#include <libraries/mathieeesp.h>

#include <clib/mathsingbas_protos.h>

struct Library *MathIeeeSingBasBase;

VOID main()
{
FLOAT f1, f2, f3;
LONG   i1;

if (MathIeeeSingBasBase = OpenLibrary("mathieeesingbas.library",37))
```c
    {
    i1 = IEEESPFix(f1);                /* Call IEEESPFix entry */
    fi = IEEESPFlt(i1);                /* Call IEEESPFlt entry */
    switch (IEEESPCmp(f1, f2)) {};     /* Call IEEESPCmp entry */
    switch (IEEESPTst(f1)) {};         /* Call IEEESPTst entry */
    f1 = IEEESPAbs(f2);                /* Call IEEESPAbs entry */
    f1 = IEEESPNeg(f2);                /* Call IEEESPNeg entry */
    f1 = IEEESPAdd(f2, f3);            /* Call IEEESPAdd entry */
    f1 = IEEESPSub(f2, f3);            /* Call IEEESPSub entry */
    f1 = IEEESPMul(f2, f3);            /* Call IEEESPMul entry */
    f1 = IEEESPDiv(f2, f3);            /* Call IEEESPDiv entry */
    f1 = IEEESPCeil(f2);               /* Call IEEESPCeil entry */
    f1 = IEEESPFloor(f2);              /* Call IEEESPFloor entry */

    CloseLibrary(MathIeeeSingBasBase);
    }
```
else
```c
    printf("Can't open mathieeesingbas.library\n");
```
}

