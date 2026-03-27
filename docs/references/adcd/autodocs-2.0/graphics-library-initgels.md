---
title: graphics.library/InitGels
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-initgels
functions: []
libraries: []
---

# graphics.library/InitGels

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    InitGels -- initialize a gel list; must be called before using gels.
```
SYNOPSIS

```c
    InitGels(head, tail, GInfo)
             A0    A1    A2

    void InitGels(struct [VSprite](autodocs-2.0/includes-graphics-gels-h.md) *, struct [VSprite](autodocs-2.0/includes-graphics-gels-h.md) *, struct [GelsInfo](autodocs-2.0/includes-graphics-rastport-h.md) *);
```
FUNCTION

```c
    Assigns the VSprites as the head and tail of the gel list in [GfxBase](autodocs-2.0/includes-graphics-gfxbase-h.md).
    Links these two gels together as the keystones of the list.
    If the collHandler vector points to some memory array, sets
    the BORDERHIT vector to NULL.
```
INPUTS

```c
    head  = pointer to the [VSprite](autodocs-2.0/includes-graphics-gels-h.md) structure to be used as the
            gel list head
    tail  = pointer to the [VSprite](autodocs-2.0/includes-graphics-gels-h.md) structure to be used as the
            gel list tail
    GInfo = pointer to the [GelsInfo](autodocs-2.0/includes-graphics-rastport-h.md) structure to be initialized
```
RESULT

BUGS

SEE ALSO

```c
    [graphics/gels.h](autodocs-2.0/includes-graphics-gels-h.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```
