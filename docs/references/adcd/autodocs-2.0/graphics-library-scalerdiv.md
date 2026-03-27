---
title: graphics.library/ScalerDiv
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-scalerdiv
functions: []
libraries: []
---

# graphics.library/ScalerDiv

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ScalerDiv -- Get the scaling result that [BitMapScale](autodocs-2.0/graphics-library-bitmapscale.md) would. (V36)
```
SYNOPSIS

```c
    result = ScalerDiv(factor, numerator, denominator)
    D0                 D0      D1         D2

    UWORD ScalerDiv(UWORD, UWORD, UWORD);
```
FUNCTION

```c
    Calculate the expression (factor*numerator/denominator) such
    that the result is the same as the width of the destination
    result of [BitMapScale](autodocs-2.0/graphics-library-bitmapscale.md) when the factor here is the width of
    the source, and the numerator and denominator are the
    XDestFactor and XSrcFactor for [BitMapScale](autodocs-2.0/graphics-library-bitmapscale.md).
```
INPUTS

    factor                 - a number in the range 0..16383
    numerator, denominator - numbers in the range 1..16383
RESULT

    this returns factor*numerator/denominator
