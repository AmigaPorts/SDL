---
title: graphics.library/CWAIT
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-cwait
functions: []
libraries: []
---

# graphics.library/CWAIT

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CWAIT -- Append copper wait instruction to user copper list.
SYNOPSIS

```c
    CWAIT( c , v , h )

    CWait( c , v , h )
           a1  d0  d1
    CBump( c )
          a1

    void CWait( struct [UCopList](autodocs-2.0/includes-graphics-copper-h.md) *, WORD, WORD)
```
FUNCTION

    Add instruction to wait for vertical beam position v and
    horizontal position h to this intermediate copper list.
INPUTS

```c
    c - pointer to [UCopList](autodocs-2.0/includes-graphics-copper-h.md) structure
    v - vertical beam position (relative to top of viewport)
    h - horizontal beam position
```
RESULTS

```c
    this is actually a macro that calls CWait(c,v,h)
    and then calls CBump(c) to bump the local pointer
    to the next instruction.
```
BUGS

    User waiting for horizontal values of greater than 222 decimal
    is illegal.
SEE ALSO

```c
    [CINIT](autodocs-2.0/graphics-library-cinit.md) [CMOVE](autodocs-2.0/graphics-library-cmove.md) [CEND](autodocs-2.0/graphics-library-cend.md) [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md)
```
