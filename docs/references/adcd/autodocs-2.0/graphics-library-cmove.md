---
title: graphics.library/CMOVE
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-cmove
functions: []
libraries: []
---

# graphics.library/CMOVE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CMOVE -- append copper move instruction to user copper list.
SYNOPSIS

```c
    CMOVE( c , a , v )

    CMove( c , a , v )
          a1  d0  d1
    CBump( c )
          a1

    void CMove( struct [UCopList](autodocs-2.0/includes-graphics-copper-h.md) *, void *, WORD );
```
FUNCTION

    Add instruction to move value v to hardware register a.
INPUTS

```c
    c - pointer to [UCopList](autodocs-2.0/includes-graphics-copper-h.md) structure
    a - hardware register
    v - 16 bit value to be written
```
RESULTS

```c
    This is actually a macro that calls CMove(c,&a,v)
    and then calls CBump(c) to bump the local pointer
    to the next instruction. Watch out for macro side affects.
```
BUGS

SEE ALSO

```c
    [CINIT](autodocs-2.0/graphics-library-cinit.md) [CWAIT](autodocs-2.0/graphics-library-cwait.md) [CEND](autodocs-2.0/graphics-library-cend.md) [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md)
```
