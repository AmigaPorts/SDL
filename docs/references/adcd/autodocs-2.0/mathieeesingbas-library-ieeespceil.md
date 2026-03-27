---
title: mathieeesingbas.library/IEEESPCeil
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathieeesingbas-library-ieeespceil
functions: []
libraries: []
---

# mathieeesingbas.library/IEEESPCeil

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IEEESPCeil -- compute Ceil function of IEEE single precision number
SYNOPSIS

```c
      x   = IEEESPCeil(  y  );
     d0                  d0

    float   x,y;
```
FUNCTION

```c
    Calculate the least integer greater than or equal to x and return it.
    This identity is true.  Ceil(x) = -Floor(-x).
```
INPUTS

    y -- IEEE single precision floating point value
RESULT

    x -- IEEE single precision floating point value
BUGS

SEE ALSO

```c
    [IEEESPFloor](autodocs-2.0/mathieeesingbas-library-ieeespfloor.md)
```
