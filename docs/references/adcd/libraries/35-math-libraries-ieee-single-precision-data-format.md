---
title: 35 Math Libraries / IEEE Single-Precision Data Format
manual: libraries
chapter: libraries
section: 35-math-libraries-ieee-single-precision-data-format
functions: []
libraries: []
---

# 35 Math Libraries / IEEE Single-Precision Data Format

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The IEEE single-precision variables are defined as 32-bit entities with
the following format:


```c
         ______________________________________________
        |                                              |
        | SEEEEEEE    MMMMMMMM    MMMMMMMM    MMMMMMMM |
        | 31          23          15          7        |
        |______________________________________________|


    Hidden Bit In The Mantissa.
    ---------------------------
    There is a "hidden" bit in the mantissa part of the IEEE numbers.
    Since all numbers are normalized, the integer (high) bit of the
    mantissa is dropped off.  The IEEE single-precision range is 1.3E-38
    (1.4E-45 de-normalized) to 3.4E+38.
```
The exponent is the power of two needed to correctly position the mantissa
to reflect the number's true arithmetic value.  If both the exponent and
the mantissa have zero in every position, the value is zero.  If only the
exponent has zero in every position, the value is an unnormal (extremely
small).  If all bits of the exponent are set to 1 the value is either a
positive or negative infinity or a Not a Number (NaN).  NaN is sometimes
used to indicate an uninitialized variable.

