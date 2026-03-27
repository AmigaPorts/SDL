---
title: mathtrans.library/SPTanh
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathtrans-library-sptanh
functions: []
libraries: []
---

# mathtrans.library/SPTanh

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SPTanh - obtain the hyperbolic tangent of the floating point number
SYNOPSIS

```c
    fnum2 = SPTanh(fnum1);
                   d0.l
    float fnum2;
    float fnum1;
```
FUNCTION

    Accepts a floating point number representing an angle
    in radians and returns the hyperbolic tangent of said angle.
INPUTS

    fnum1 - Motorola fast floating point number
RESULT

    fnum2 - Motorola fast floating point number
BUGS

    None
SEE ALSO

```c
    [SPSinh](autodocs-2.0/mathtrans-library-spsinh.md), [SPCosh](autodocs-2.0/mathtrans-library-spcosh.md)
```
