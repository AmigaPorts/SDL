---
title: graphics.library/CEND
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-cend
functions: []
libraries: []
---

# graphics.library/CEND

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CEND -- Terminate user copper list.
SYNOPSIS

```c
    CEND( c )

    struct [UCopList](autodocs-2.0/includes-graphics-copper-h.md) *c;
```
FUNCTION

    Add instruction to terminate user copper list.
INPUTS

```c
    c - pointer to [UCopList](autodocs-2.0/includes-graphics-copper-h.md) structure
```
RESULTS

```c
    This is actually a macro that calls the macro CWAIT(c,10000,255)
    10000 is a magical number that the graphics.library uses.
    I hope display technology doesn't catch up too fast!
```
BUGS

SEE ALSO

```c
    [CINIT](autodocs-2.0/graphics-library-cinit.md) [CWAIT](autodocs-2.0/graphics-library-cwait.md) [CMOVE](autodocs-2.0/graphics-library-cmove.md) [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md)
```
