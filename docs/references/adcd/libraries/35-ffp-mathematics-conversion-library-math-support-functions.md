---
title: 35 / FFP Mathematics Conversion Library / Math Support Functions
manual: libraries
chapter: libraries
section: 35-ffp-mathematics-conversion-library-math-support-functions
functions: []
libraries: []
---

# 35 / FFP Mathematics Conversion Library / Math Support Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[afp()](autodocs-2.0/amiga-lib-afp.md)    FLOAT afp( BYTE *string );

    Convert ASCII string into FFP equivalent.
[arnd()](autodocs-2.0/amiga-lib-arnd.md)   VOID arnd( LONG place, LONG exp, BYTE *string);

    Round ASCII representation of FFP number.
[dbf()](autodocs-2.0/amiga-lib-dbf.md)    FLOAT dbf( ULONG exp, ULONG mant);

    Convert FFP dual-binary number to FFP equivalent.
[fpa()](autodocs-2.0/amiga-lib-fpa.md)    LONG fpa( FLOAT fnum, BYTE *string);

    Convert FFP variable into ASCII equivalent.
Be sure to include proper data type definitions, as shown in the example
below.  Print statements have been included to help clarify the format of
the math conversion function calls.


```c
     [mathffp.c](libraries/lib-examples-mathffp-c.md) 
```
