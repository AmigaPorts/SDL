---
title: mathieeedoubtrans.library/IEEEDPSincos
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathieeedoubtrans-library-ieeedpsincos
functions: []
libraries: []
---

# mathieeedoubtrans.library/IEEEDPSincos

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IEEEDPSincos -- compute the arc tangent of a floating point number
SYNOPSIS

```c
      x   = IEEEDPSincos( z ,  y  );
    d0/d1                a0  d0/d1

    double  x,y,*z;
```
FUNCTION

    Compute sin and cosine of y in IEEE double precision.
    Store the cosine in *z. Return the sine of y.
INPUTS

    y - IEEE double precision floating point value
    z - pointer to IEEE double precision floating point number
RESULT

    x - IEEE double precision floating point value
BUGS

SEE ALSO

```c
    [IEEEDPSin()](autodocs-2.0/mathieeedoubtrans-library-ieeedpsin.md), [IEEEDPCos()](autodocs-2.0/mathieeedoubtrans-library-ieeedpcos.md)
```
