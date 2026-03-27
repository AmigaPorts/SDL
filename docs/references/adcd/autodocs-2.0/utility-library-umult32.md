---
title: utility.library/UMult32
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-umult32
functions: []
libraries: []
---

# utility.library/UMult32

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    UMult32 -- Unsigned 32 by 32 bit multiply with 32 bit result. (V36)
```
SYNOPSIS

```c
    Result = UMult32( Arg1, Arg2 )
    D0                D0    D1

    ULONG UMult32( ULONG, ULONG );
```
FUNCTION

    Returns the unsigned 32 bit result of multiplying Arg1 by Arg2.
INPUTS

    Arg1, Arg2              - unsigned multiplicands.
RESULTS

    Result                  - the unsigned 32 bit result of
                              multiplying Arg1 by Arg2.
NOTES

SEE ALSO

```c
    [SDivMod32()](autodocs-2.0/utility-library-sdivmod32.md), [SMult32()](autodocs-2.0/utility-library-smult32.md), [UDivMod32()](autodocs-2.0/utility-library-udivmod32.md)
```
BUGS

