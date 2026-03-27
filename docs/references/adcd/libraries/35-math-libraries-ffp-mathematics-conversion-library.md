---
title: 35 Math Libraries / FFP Mathematics Conversion Library
manual: libraries
chapter: libraries
section: 35-math-libraries-ffp-mathematics-conversion-library
functions: []
libraries: []
---

# 35 Math Libraries / FFP Mathematics Conversion Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The FFP mathematics conversion library provides functions to convert ASCII
strings to their FFP equivalents and vice versa.

It is accessed by linking code into the executable file being created. The
name of the file to include in the library description of the link command
line is amiga.lib.  When this is included, direct calls are made to the
conversion functions.  Only a C interface exists for the conversion
functions; there is no assembly language interface.  The basic math
library is required in order to access these functions.


```c
    #include <exec/types.h>
    #include <libraries/mathffp.h>

    #include <clib/mathffp_protos.h>

    struct Library *MathBase;

    VOID main()
    {
    if (MathBase = OpenLibrary("mathffp.library", 33))
        {
               . . .

        CloseLibrary(MathBase);
        }
    else
        printf("Can't open mathffp.library\n");
    }
```
 [Math Support Functions](libraries/35-ffp-mathematics-conversion-library-math-support-functions.md) 

