---
title: mathtrans.library/SPLog10
manual: autodocs-2.0
chapter: autodocs-2.0
section: mathtrans-library-splog10
functions: []
libraries: []
---

# mathtrans.library/SPLog10

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SPLog10 - obtain the naperian logarithm(base 10) of the
              floating point number
```
SYNOPSIS

```c
    fnum2 = SPLog10(fnum1);
                    d0.l
    float fnum2;
    float fnum1;
```
FUNCTION

```c
    Accepts a floating point number and returns the naperian
    logarithm (base 10) of said number
```
INPUTS

    fnum1 - Motorola fast floating point number
RESULT

    fnum2 - Motorola fast floating point number
BUGS

    None
SEE ALSO

```c
    [SPExp](autodocs-2.0/mathtrans-library-spexp.md), SpLog
```
