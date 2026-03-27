---
title: graphics.library/FreeCprList
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-freecprlist
functions: []
libraries: []
---

# graphics.library/FreeCprList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeCprList -- deallocate hardware copper list
SYNOPSIS

```c
    FreeCprList(cprlist)
                  a0

    void FreeCprList(struct [cprlist](autodocs-2.0/includes-graphics-copper-h.md) *);
```
FUNCTION

```c
    return [cprlist](autodocs-2.0/includes-graphics-copper-h.md) to free memory pool
```
INPUTS

```c
    [cprlist](autodocs-2.0/includes-graphics-copper-h.md) - pointer to [cprlist](autodocs-2.0/includes-graphics-copper-h.md) structure
```
RESULTS

    memory returned and made available to other tasks
BUGS

SEE ALSO

```c
    [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md)
```
