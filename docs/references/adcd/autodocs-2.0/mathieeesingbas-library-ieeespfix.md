---
title: mathieeesingbas.library/IEEESPFix
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathieeesingbas-library-ieeespfix
functions: []
libraries: []
---

# mathieeesingbas.library/IEEESPFix

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IEEESPFix -- convert IEEE single float to integer
SYNOPSIS

```c
    x   = IEEESPFix(  y  );
    d0               d0

    long    x;
    float   y;
```
FUNCTION

    Convert IEEE single precision argument to a 32 bit signed integer
    and return result.
INPUTS

    y -- IEEE single precision floating point value
RESULT

    if no overflow occured then return
            x -- 32 bit signed integer
    if overflow return largest +- integer
            For round to zero
BUGS

SEE ALSO

```c
    [IEEESPFlt](autodocs-2.0/mathieeesingbas-library-ieeespflt.md)
```
