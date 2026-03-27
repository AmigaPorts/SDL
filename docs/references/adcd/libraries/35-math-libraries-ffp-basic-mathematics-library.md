---
title: 35 Math Libraries / FFP Basic Mathematics Library
manual: libraries
chapter: libraries
section: 35-math-libraries-ffp-basic-mathematics-library
functions: [OpenLibrary]
libraries: [exec.library]
---

# 35 Math Libraries / FFP Basic Mathematics Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The FFP basic math library contains entries for the basic mathematics
functions such as add, subtract and divide.  It resides in ROM and is
opened by calling [OpenLibrary()](libraries/17-introduction-to-exec-libraries-and-devices.md) with "mathffp.library" as the argument.


```c
    #include <exec/types.h>
    #include <libraries/mathffp.h>

    #include <clib/mathffp_protos.h>

    struct Library *MathBase;

    VOID main()
    {
    if (MathBase = OpenLibrary("mathffp.library", 0))
        {
               . . .

        CloseLibrary(MathBase);
        }
    else
        printf("Can't open mathffp.library\n");
    }
```
The global variable MathBase is used internally for all future library
references.

 [FFP Basic Functions](libraries/35-ffp-basic-mathematics-library-ffp-basic-functions.md) 

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
