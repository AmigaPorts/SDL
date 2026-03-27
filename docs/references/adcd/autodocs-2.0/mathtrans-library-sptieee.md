---
title: mathtrans.library/SPTieee
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathtrans-library-sptieee
functions: []
libraries: []
---

# mathtrans.library/SPTieee

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SPTieee - convert FFP number to single precision ieee
SYNOPSIS

```c
    ieeenum = SPTieee(fnum);
                     d0.l
    float ieeenum;
    float fnum;
```
FUNCTION

    Accepts a Motorola fast floating point number and
    returns the same number, converted into IEEE
    standard single precision format
INPUTS

    fnum - Motorola fast floating point number
RESULT

    ieeenum - IEEE Single Precision Floating Point
BUGS

    None
SEE ALSO

```c
    [SPFieee](autodocs-2.0/mathtrans-library-spfieee.md)
```
