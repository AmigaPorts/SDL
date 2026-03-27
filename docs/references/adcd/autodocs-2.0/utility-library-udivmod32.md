---
title: utility.library/UDivMod32
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-udivmod32
functions: []
libraries: []
---

# utility.library/UDivMod32

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    UDivMod32 -- Unsigned 32 by 32 bit division and modulus. (V36)
```
SYNOPSIS

```c
    Quotient:Remainder = UDivMod32( Dividend, Divisor )
    D0       D1                     D0        D1

    ULONG UDivMod32( ULONG, ULONG );
```
FUNCTION

    Divides the unsigned 32 bit dividend by the unsigned 32 bit divisor
    and returns a unsigned 32 bit quotient and remainder.
INPUTS

    Dividend        - unsigned 32 bit dividend.
    Divisor         - unsigned 32 bit divisor.
RESULTS

    Quotient        - unsigned 32 quotient of the division.
    Remainder       - unsigned 32 remainder of the division.
NOTES

SEE ALSO

```c
    [SDivMod32()](autodocs-2.0/utility-library-sdivmod32.md), [SMult32()](autodocs-2.0/utility-library-smult32.md), [UMult32()](autodocs-2.0/utility-library-umult32.md)
```
BUGS

