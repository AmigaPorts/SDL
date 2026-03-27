---
title: mathieeedoubbas.library/IEEEDPFlt
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathieeedoubbas-library-ieeedpflt
functions: []
libraries: []
---

# mathieeedoubbas.library/IEEEDPFlt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    IEEEDPFlt -- convert integer to IEEE double precision number
SYNOPSIS

```c
      x   = IEEEDPFlt(  y  );
    d0/d1              d0

    double  x;
    long    y;
```
FUNCTION

    Convert a signed 32 bit value to a double precision IEEE value
    and return it in d0/d1. No exceptions can occur with this
    function.
INPUTS

    y -- 32 bit integer in d0
RESULT

    x is a 64 bit double precision IEEE value
BUGS

SEE ALSO

```c
    [IEEEDPFix](autodocs-2.0/mathieeedoubbas-library-ieeedpfix.md)
```
