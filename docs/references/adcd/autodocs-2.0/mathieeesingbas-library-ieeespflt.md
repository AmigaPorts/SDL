---
title: mathieeesingbas.library/IEEESPFlt
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathieeesingbas-library-ieeespflt
functions: []
libraries: []
---

# mathieeesingbas.library/IEEESPFlt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IEEESPFlt -- convert integer to IEEE single precision number
SYNOPSIS

```c
      x   = IEEESPFlt(  y  );
     d0                d0

    float   x;
    long    y;
```
FUNCTION

    Convert a signed 32 bit value to a single precision IEEE value
    and return it in d0. No exceptions can occur with this
    function.
INPUTS

    y -- 32 bit integer in d0
RESULT

    x is a 32 bit single precision IEEE value
BUGS

SEE ALSO

```c
    [IEEESPFix](autodocs-2.0/mathieeesingbas-library-ieeespfix.md)
```
