---
title: 35 Math Libraries / IEEE Single-Precision Basic Math Library
manual: libraries
chapter: libraries
section: 35-math-libraries-ieee-single-precision-basic-math-library
functions: [OpenLibrary]
libraries: [exec.library]
---

# 35 Math Libraries / IEEE Single-Precision Basic Math Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The ROM-based IEEE single-precision basic math library was introduced in
V36.  This library contains entries for the basic IEEE single-precision
mathematics functions, such as add, subtract, and divide.  (Note,
registered developers can license a disk-based version of this library
from [CATS](libraries/1-introduction-commodore-applications-and-technical-support.md), for usage with V33).

The library is opened by making calling [OpenLibrary()](libraries/17-introduction-to-exec-libraries-and-devices.md) with
"mathieeesingbas.library" as the argument.  Do not share the library base
pointer between tasks -- [see note](libraries/35-math-libraries.md) at beginning of chapter for details.


```c
    #include <exec/types.h>
    #include <libraries/mathieeesp.h>

    #include <clib/mathsingbas_protos.h>

    struct Library *MathIeeeSingBasBase;

    VOID main()
    {
        /* do not share base pointer between tasks. */
    if (MathIeeeSingBasBase = OpenLibrary("mathieeesingbas.library", 37))
        {
               .
               .
               .
        CloseLibrary(MathIeeeSingBasBase);
        }
    else
        printf("Can't open mathieeesingbas.library\n");
    }
```
The global variable MathIeeeSingBasBase is used internally for all future
library references.

If an 680X0/68881/68882 processor combination is available, it will be
used by the IEEE single-precision basic library instead of the software
emulation.  Also, if an autoconfigured math resource is available, that
will be used.  Typically this is a 68881 designed as a 16 bit I/O port,
but it could be another device as well.

 [SP IEEE Basic Functions (V36 or Greater)](libraries/35-sp-basic-math-library-sp-ieee-basic-functions-v36-or.md) 

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
