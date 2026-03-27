---
title: amiga.lib/FastRand
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-fastrand
functions: []
libraries: []
---

# amiga.lib/FastRand

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FastRand - quickly generate a somewhat random integer
SYNOPSIS

```c
    number = FastRand(seed);

    ULONG FastRand(ULONG);
```
FUNCTION

    Seed value is taken from stack, shifted left one position,
    exclusive-or'ed with hex value $1D872B41 and returned.
INPUTS

    seed - a 32-bit integer
RESULT

    number - new random seed, a 32-bit value
SEE ALSO

```c
    [RangeRand()](autodocs-2.0/amiga-lib-rangerand.md)
```
