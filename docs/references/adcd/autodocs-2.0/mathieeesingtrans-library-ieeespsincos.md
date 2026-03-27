---
title: mathieeesingtrans.library/IEEESPSincos
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathieeesingtrans-library-ieeespsincos
functions: []
libraries: []
---

# mathieeesingtrans.library/IEEESPSincos

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IEEESPSincos -- compute the arc tangent of a floating point number
SYNOPSIS

```c
      x   = IEEESPSincos( z ,  y  );
    d0                   a0  d0

    float   x,y,*z;
```
FUNCTION

    Compute sin and cosine of y in IEEE single precision.
    Store the cosine in *z. Return the sine of y.
INPUTS

    y - IEEE single precision floating point value
    z - pointer to IEEE single precision floating point number
RESULT

    x - IEEE single precision floating point value
BUGS

SEE ALSO

```c
    [IEEESPSin()](autodocs-2.0/mathieeesingtrans-library-ieeespsin.md), [IEEESPCos()](autodocs-2.0/mathieeesingtrans-library-ieeespcos.md)
```
