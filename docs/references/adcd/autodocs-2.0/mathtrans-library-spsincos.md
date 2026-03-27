---
title: mathtrans.library/SPSincos
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathtrans-library-spsincos
functions: []
libraries: []
---

# mathtrans.library/SPSincos

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SPSincos - obtain the sine and cosine of a number
SYNOPSIS

```c
    fnum3 = SPSincos(pfnum2, fnum1);
                     d1.l,   d0.l
    float *pfnum2;
    float fnum1;
    float fnum3;
```
FUNCTION

```c
    Accepts a floating point number (fnum1) representing
    an angle in radians and a pointer to another floating
    point number (pfnum2). It computes the cosine and places it in
    *pfnum2. It computes the sine and returns it as a result.
```
INPUTS

    fnum1 - Motorola fast floating point number
    pfnum2 - pointer to Motorola fast floating point number
RESULT

```c
    *pfnum2 - Motorola fast floating point number (cosine)
    fnum3 - Motorola fast floating point number (sine)
```
BUGS

    None
SEE ALSO

```c
    [SPSin](autodocs-2.0/mathtrans-library-spsin.md), [SPCos](autodocs-2.0/mathtrans-library-spcos.md)
```
