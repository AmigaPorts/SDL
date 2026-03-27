---
title: mathieeedoubbas.library/IEEEDPTst
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathieeedoubbas-library-ieeedptst
functions: []
libraries: []
---

# mathieeedoubbas.library/IEEEDPTst

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IEEEDPTst -- compare IEEE double precision value to 0.0
SYNOPSIS

```c
      c   = IEEEDPTst(  y  );
      d0              d0/d1

    double  y;
    long    c;
```
FUNCTION

    Compare y to 0.0, set the condition codes for less than, greater
    than, or equal to 0.0.  Set the return value c to -1 if less than,
    to +1 if greater than, or 0 if equal to 0.0.
INPUTS

    y -- IEEE double precision floating point value
RESULT

```c
    c = 1   cc = gt         for (y > 0.0)
    c = 0   cc = eq         for (y == 0.0)
    c = -1  cc = lt         for (y < 0.0)
```
BUGS

SEE ALSO

