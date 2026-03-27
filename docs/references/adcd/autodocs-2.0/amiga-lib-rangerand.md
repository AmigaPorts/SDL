---
title: amiga.lib/RangeRand
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-rangerand
functions: []
libraries: []
---

# amiga.lib/RangeRand

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RangeRand - generate a random number within a specific integer range
SYNOPSIS

```c
    number = RangeRand(maxValue);

    UWORD RangeRand(UWORD);
```
FUNCTION

```c
    RangeRand() accepts a value from 0 to 65535, and returns a value
    within that range.

    maxValue is passed on stack as a 32-bit integer but used as though
    it is only a 16-bit integer. Variable named RangeSeed is available
    beginning with V33 that contains the global seed value passed from
    call to call and thus can be changed in a program by declaring:

      extern ULONG RangeSeed;
```
INPUTS

    maxValue - the returned random number will be in the range
               [0..maxValue-1]
RESULT

    number - pseudo random number in the range of [0..maxValue-1].
SEE ALSO

```c
    [FastRand()](autodocs-2.0/amiga-lib-fastrand.md)
```
