---
title: mathieeedoubbas.library/IEEEDPMul
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathieeedoubbas-library-ieeedpmul
functions: []
libraries: []
---

# mathieeedoubbas.library/IEEEDPMul

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IEEEDPMul -- multiply one double precision IEEE number by another
SYNOPSIS

```c
      x   = IEEEDPMul(  y  ,  z  );
    d0/d1             d0/d1 d2/d3

    double  x,y,z;
```
FUNCTION

```c
    Compute x = y * z in IEEE double precision.
```
INPUTS

    y -- IEEE double precision floating point value
    z -- IEEE double precision floating point value
RESULT

    x -- IEEE double precision floating point value
BUGS

SEE ALSO

```c
    [IEEEDPDiv](autodocs-2.0/mathieeedoubbas-library-ieeedpdiv.md)
```
