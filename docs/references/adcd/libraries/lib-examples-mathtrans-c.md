---
title: lib_examples/mathtrans.c
manual: libraries
chapter: libraries
section: lib-examples-mathtrans-c
functions: []
libraries: []
---

# lib_examples/mathtrans.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

#include <exec/types.h>
#include <libraries/mathffp.h>

#include <clib/mathffp_protos.h>
#include <clib/mathtrans_protos.h>

struct Library *MathTransBase;

VOID main()
{
FLOAT f1, f2, f3;
FLOAT i1;

if (MathTransBase = OpenLibrary("mathtrans.library",33))
```c
    {
    f1 = SPAsin(f2);        /* Call SPAsin entry */
    f1 = SPAcos(f2);        /* Call SPAcos entry */
    f1 = SPAtan(f2);        /* Call SPAtan entry */

    f1 = SPSin(f2);         /* Call SPSin entry */
    f1 = SPCos(f2);         /* Call SPCos entry */
    f1 = SPTan(f2);         /* Call SPTan entry */
    f1 = SPSincos(&f3, f2); /* Call SPSincos entry */

    f1 = SPSinh(f2);        /* Call SPSinh entry */
    f1 = SPCosh(f2);        /* Call SPCosh entry */
    f1 = SPTanh(f2);        /* Call SPTanh entry */

    f1 = SPExp(f2);         /* Call SPExp entry */
    f1 = SPLog(f2);         /* Call SPLog entry */
    f1 = SPLog10(f2);       /* Call SPLog10 entry */
    f1 = SPPow(f2);         /* Call SPPow entry */
    f1 = SPSqrt(f2);        /* Call SPSqrt entry */

    i1 = SPTieee(f2);       /* Call SPTieee entry */
    f1 = SPFieee(i1);       /* Call SPFieee entry */

    CloseLibrary(MathTransBase);
    }
```
else
```c
    printf("Can't open mathtrans.library\n");
```
}

