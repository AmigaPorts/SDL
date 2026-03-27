---
title: mathieeesingbas.library/IEEESPCmp
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathieeesingbas-library-ieeespcmp
functions: []
libraries: []
---

# mathieeesingbas.library/IEEESPCmp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IEEESPCmp -- compare two single precision floating point numbers
SYNOPSIS

```c
      c   = IEEESPCmp(  y  ,  z  );
      d0                d0   d1

    float   y,z;
    long    c;
```
FUNCTION

```c
    Compare y with z. Set the condition codes for less, greater, or
    equal. Set return value c to -1 if y<z, or +1 if y>z, or 0 if
    y == z.
```
INPUTS

    y -- IEEE single precision floating point value
    z -- IEEE single precision floating point value
RESULT
   c = 1   cc = gt         for (y > z)
   c = 0   cc = eq         for (y == z)
   c = -1  cc = lt         for (y < z)

BUGS

SEE ALSO

