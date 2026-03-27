---
title: utility.library/SDivMod32
manual: autodocs-2.0
chapter: autodocs-2.0
section: utility-library-sdivmod32
functions: []
libraries: []
---

# utility.library/SDivMod32

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SDivMod32 -- Signed 32 by 32 bit division and modulus. (V36)
```
SYNOPSIS

```c
    Quotient:Remainder = SDivMod32( Dividend, Divisor )
    D0       D1                     D0        D1

    LONG SDivMod32( LONG, LONG );
```
FUNCTION

    Divides the signed 32 bit dividend by the signed 32 bit divisor
       and returns a signed 32 bit quotient and remainder.
INPUTS

    Dividend        - signed 32 bit dividend.
    Divisor         - signed 32 bit divisor.
RESULTS

    Quotient        - signed 32 quotient of the division.
    Remainder       - signed 32 remainder of the division.
NOTES

SEE ALSO

```c
    [SMult32()](autodocs-2.0/utility-library-smult32.md), [UDivMod32()](autodocs-2.0/utility-library-udivmod32.md), [UMult32()](autodocs-2.0/utility-library-umult32.md)
```
BUGS

