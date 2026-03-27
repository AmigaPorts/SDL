---
title: mathieeedoubbas.library/IEEEDPCeil
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathieeedoubbas-library-ieeedpceil
functions: []
libraries: []
---

# mathieeedoubbas.library/IEEEDPCeil

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IEEEDPCeil -- compute Ceil function of IEEE double precision number
SYNOPSIS

```c
      x   = IEEEDPCeil(  y  );
    d0/d1              d0/d1

    double  x,y;
```
FUNCTION

```c
    Calculate the least integer greater than or equal to x and return it.
    This value may have more than 32 bits of significance.
    This identity is true.  Ceil(x) = -Floor(-x).
```
INPUTS

    y -- IEEE double precision floating point value
RESULT

    x -- IEEE double precision floating point value
BUGS

SEE ALSO

```c
    [IEEEDPFloor](autodocs-2.0/mathieeedoubbas-library-ieeedpfloor.md)
```
