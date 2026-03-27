---
title: graphics.library/CBump
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-cbump
functions: []
libraries: []
---

# graphics.library/CBump

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CBump -- increment user copper list pointer (bump to next position
             in list).
```
SYNOPSIS

```c
    CBump( c )
          a1

    void CBump( struct [UCopList](autodocs-2.0/includes-graphics-copper-h.md) * );
```
FUNCTION

    Increment pointer to space for next instruction in user copper list.
INPUTS

```c
    c - pointer to [UCopList](autodocs-2.0/includes-graphics-copper-h.md) structure
```
RESULTS

```c
    User copper list pointer is incremented to next position.
    Pointer is repositioned to next user copperlist instruction block
    if the current block is full.

        Note: CBump is usually invoked for the programmer as part of the
              macro definitions [CWAIT](autodocs-2.0/graphics-library-cwait.md) or [CMOVE](autodocs-2.0/graphics-library-cmove.md).
```
BUGS

SEE ALSO

```c
    [CINIT](autodocs-2.0/graphics-library-cinit.md) [CWAIT](autodocs-2.0/graphics-library-cwait.md) [CMOVE](autodocs-2.0/graphics-library-cmove.md) [CEND](autodocs-2.0/graphics-library-cend.md) [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md)
```
