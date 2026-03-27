---
title: E Release 2 Compatibility / General Compatibility Problem Areas
manual: libraries
chapter: libraries
section: e-release-2-compatibility-general-compatibility-problem
functions: []
libraries: []
---

# E Release 2 Compatibility / General Compatibility Problem Areas

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following improper Amiga programming practices are likely to fail on
new ROMs or hardware.

  * Requiring all free RAM.

  * Overwriting memory allocations.  With 32-bit addresses, a 1-byte

```c
    overwrite of a string array can wipe out the high byte of a pointer
    or stack return address.  This bug could go unnoticed on a 24-bit
    address machine (e.g., A500) but crash the system or cause other
    problems on an A3000.
```
  * Improper flags or garbage in system structures.  A bit that means

    nothing under one OS may drastically change the behavior of a
    function in a newer version of the OS.  Clear structures before
    using, and use correct flags.
  * Misuse of function return values.  Use function prototypes and read

```c
    the Autodocs for the functions you are using.  Some system functions
    return just success or failure, or nothing at all (void).  In such
    cases, the value which the function happens to return must not be
    used except as it is documented.
```
  * Depending on unsupported side effects or undocumented behavior.  Be

    sure to read the Autodocs, include file comments and other
    documentation.
  * Assuming current choices, configurations or initial values.  If the

    current possibilities are A, B, or C, do not assume C if it isn't A
    or B.  Check specifically for the choices currently implemented, and
    provide default behavior for unexpected values.
Amiga debugging tools such as Enforcer, Mungwall and Scratch can find many
program bugs that may affect compatibility. A program that is
Enforcer/Mungwall/Scratch clean stands a much better chance of working
well under current and future versions of the OS.

