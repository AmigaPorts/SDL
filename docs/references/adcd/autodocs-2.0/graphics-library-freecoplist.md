---
title: graphics.library/FreeCopList
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-freecoplist
functions: []
libraries: []
---

# graphics.library/FreeCopList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeCopList -- deallocate intermediate copper list
SYNOPSIS

```c
    FreeCopList(coplist)
                  a0

    void FreeCopList( struct [CopList](autodocs-2.0/includes-graphics-copper-h.md) *);
```
FUNCTION

    Deallocate all memory associated with this copper list.
INPUTS

```c
    coplist  - pointer to structure [CopList](autodocs-2.0/includes-graphics-copper-h.md)
```
RESULTS

    memory returned to memory manager
BUGS

SEE ALSO

```c
    [graphics/copper.h](autodocs-2.0/includes-graphics-copper-h.md)
```
