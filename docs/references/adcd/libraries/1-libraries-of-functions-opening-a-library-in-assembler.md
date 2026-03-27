---
title: 1 / / Libraries of Functions / Opening a Library in Assembler
manual: libraries
chapter: libraries
section: 1-libraries-of-functions-opening-a-library-in-assembler
functions: [OpenLibrary]
libraries: [exec.library]
---

# 1 / / Libraries of Functions / Opening a Library in Assembler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's the same example written in 68000 assembler.  The principles are
the same as with : you must always open a library before using any of its
functions.  However, in assembler, library bases are treated a little
differently than in C.  In C, you assign the library base you get from
[OpenLibrary()](libraries/1-programming-in-the-amiga-environment-libraries-of.md) to a global variable and forget about it (the system handles
the rest).  In assembler, the library base must always be in [register](libraries/26-interrupt-handlers-interrupt-handler-register-usage.md) A6
whenever calling any of the functions in the library.

You get the library base for any library except [Exec](libraries/1-dynamic-memory-architecture-exec-the-system-executive.md), by calling
[OpenLibrary()](libraries/1-programming-in-the-amiga-environment-libraries-of.md).  For Exec, you get the library base from the longword in
memory location 4 ($0000 0004). Exec is opened automatically by the system
at boot time, and its library base is stored there.


```c
     [easy.asm](libraries/lib-examples-easy-asm.md) 
```
The Amiga library functions are set up to accept parameters in certain
68000 [registers](libraries/26-interrupt-handlers-interrupt-handler-register-usage.md) and always return results in data register D0.  This
allows programs and functions written in assembler to communicate quickly.
It also eliminates the dependence on the stack frame conventions of any
particular language.

Amiga library functions use [registers](libraries/26-interrupt-handlers-interrupt-handler-register-usage.md) D0, D1, A0 and A1 for work space and
use register A6 to hold the library base.  Do not expect these registers
to be the same after calling a function.  All routines return a full 32
bit longword unless noted otherwise.

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
