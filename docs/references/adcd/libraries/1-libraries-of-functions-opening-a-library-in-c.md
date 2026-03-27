---
title: 1 / / Libraries of Functions / Opening a Library in C
manual: libraries
chapter: libraries
section: 1-libraries-of-functions-opening-a-library-in-c
functions: [OpenLibrary]
libraries: [exec.library]
---

# 1 / / Libraries of Functions / Opening a Library in C

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Call [OpenLibrary()](libraries/1-programming-in-the-amiga-environment-libraries-of.md) to open an Amiga function library. OpenLibrary()
returns the address of the library structure (or library base) which you
must assign to a specific global system variable as specified in the
[table above](libraries/1-programming-in-the-amiga-environment-libraries-of.md) (case is important).

If the library cannot open for some reason, the [OpenLibrary()](libraries/1-programming-in-the-amiga-environment-libraries-of.md) function
returns zero.  Here's a brief example showing how it's used in C.


```c
     [easy.c](libraries/lib-examples-easy-c.md) 
```

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
