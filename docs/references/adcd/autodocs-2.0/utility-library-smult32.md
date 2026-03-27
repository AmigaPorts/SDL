---
title: utility.library/SMult32
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-smult32
functions: []
libraries: []
---

# utility.library/SMult32

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SMult32 -- Signed 32 by 32 bit multiply with 32 bit result. (V36)
```
SYNOPSIS

```c
    Result = SMult32( Arg1, Arg2 )
    D0                D0    D1

    LONG SMult32( LONG, LONG );
```
FUNCTION

    Returns the signed 32 bit result of multiplying Arg1 by Arg2.
INPUTS

    Arg1, Arg2      - signed multiplicands.
RESULTS

    Result          - the signed 32 bit result of multiplying
                      Arg1 by Arg2.
NOTES

SEE ALSO

```c
    [SDivMod32()](autodocs-2.0/utility-library-sdivmod32.md), [UDivMod32()](autodocs-2.0/utility-library-udivmod32.md), [UMult32()](autodocs-2.0/utility-library-umult32.md)
```
BUGS

