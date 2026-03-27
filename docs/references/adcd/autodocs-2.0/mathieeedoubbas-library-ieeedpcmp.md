---
title: mathieeedoubbas.library/IEEEDPCmp
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathieeedoubbas-library-ieeedpcmp
functions: []
libraries: []
---

# mathieeedoubbas.library/IEEEDPCmp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IEEEDPCmp -- compare two double precision floating point numbers
SYNOPSIS

```c
      c   = IEEEDPCmp(  y  ,  z  );
      d0              d0/d1 d2/d3

    double  y,z;
    long    c;
```
FUNCTION

```c
    Compare y with z. Set the condition codes for less, greater, or
    equal. Set return value c to -1 if y<z, or +1 if y>z, or 0 if
    y == z.
```
INPUTS

    y -- IEEE double precision floating point value
    z -- IEEE double precision floating point value
RESULT
   c = 1   cc = gt         for (y > z)
   c = 0   cc = eq         for (y == z)
   c = -1  cc = lt         for (y < z)

BUGS

SEE ALSO

