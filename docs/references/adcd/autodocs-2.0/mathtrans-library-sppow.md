---
title: mathtrans.library/SPPow
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathtrans-library-sppow
functions: []
libraries: []
---

# mathtrans.library/SPPow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SPPow - raise a number to a power
SYNOPSIS

```c
    result = SPPow(fnum1, fnum2);
                  d1.l    d0.l
    float fnum1, fnum2;
    float result;
```
FUNCTION

    Accepts two floating point numbers and returns the
    result of fnum2 raised to the fnum1 power
INPUTS

    fnum1 - Motorola fast floating point number
    fnum2 - Motorola fast floating point number
RESULT

    result - Motorola fast floating point number
BUGS

    None
SEE ALSO

```c
    [SPExp](autodocs-2.0/mathtrans-library-spexp.md), [SPLog](autodocs-2.0/mathtrans-library-splog.md)
```
