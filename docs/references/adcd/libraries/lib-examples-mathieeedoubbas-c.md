---
title: lib_examples/mathieeedoubbas.c
manual: libraries
chapter: libraries
section: lib-examples-mathieeedoubbas-c
functions: []
libraries: []
---

# lib_examples/mathieeedoubbas.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#include <exec/types.h>
#include <libraries/mathieeedp.h>

#include <clib/mathieeedoubbas_protos.h>

struct Library *MathIeeeDoubBasBase;

VOID main()
{
DOUBLE d1, d2, d3;
LONG   i1;

if (MathIeeeDoubBasBase = OpenLibrary("mathieeedoubbas.library",34))
```c
    {

    i1 = IEEEDPFix(d1);                /* Call IEEEDPFix entry */
    fi = IEEEDPFlt(i1);                /* Call IEEEDPFlt entry */
    switch (IEEEDPCmp(d1, d2)) {};     /* Call IEEEDPCmp entry */
    switch (IEEEDPTst(d1)) {};         /* Call IEEEDPTst entry */
    d1 = IEEEDPAbs(d2);                /* Call IEEEDPAbs entry */
    d1 = IEEEDPNeg(d2);                /* Call IEEEDPNeg entry */
    d1 = IEEEDPAdd(d2, d3);            /* Call IEEEDPAdd entry */
    d1 = IEEEDPSub(d2, d3);            /* Call IEEEDPSub entry */
    d1 = IEEEDPMul(d2, d3);            /* Call IEEEDPMul entry */
    d1 = IEEEDPDiv(d2, d3);            /* Call IEEEDPDiv entry */
    d1 = IEEEDPCeil(d2);               /* Call IEEEDPCeil entry */
    d1 = IEEEDPFloor(d2);              /* Call IEEEDPFloor entry */

    CloseLibrary(MathIeeeDoubBasBase);
    }
```
else printf("Can't open mathieeedoubbas.library\n");
}

