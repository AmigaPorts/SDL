---
title: mathieeesingbas.library/IEEESPDiv
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathieeesingbas-library-ieeespdiv
functions: []
libraries: []
---

# mathieeesingbas.library/IEEESPDiv

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IEEESPDiv -- divide one single precision IEEE by another
SYNOPSIS

```c
      x   = IEEESPDiv(  y  ,  z  );
     d0                d0    d1

    float   x,y,z;
```
FUNCTION

```c
    Compute x = y / z in IEEE single precision.
    Note that the Motorola fast floating point Div routine reverses
    the order of the arguments for the C interface, although the
    dividend is still in d0 and the divisor is in d1.
```
INPUTS

    y -- IEEE single precision floating point value
    z -- IEEE single precision floating point value
RESULT

    x -- IEEE single precision floating point value
BUGS

SEE ALSO

```c
    [IEEESPMul](autodocs-2.0/mathieeesingbas-library-ieeespmul.md)
```
