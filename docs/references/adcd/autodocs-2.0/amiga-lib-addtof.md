---
title: amiga.lib/AddTOF
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-addtof
functions: []
libraries: []
---

# amiga.lib/AddTOF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddTOF - add a task to the VBlank interrupt server chain.
SYNOPSIS

```c
    AddTOF(i,p,a);

    VOID AddTOF(struct [Isrvstr](autodocs-2.0/includes-graphics-graphint-h.md) *, APTR, APTR);
```
FUNCTION

    Adds a task to the vertical-blanking interval interrupt server
    chain. This prevents C programmers from needing to write an
    assembly language stub to do this function.
INPUTS

```c
    i - pointer to an initialized [Isrvstr](autodocs-2.0/includes-graphics-graphint-h.md) structure
    p - pointer to the C-code routine that this server is to call each
        time TOF happens
    a - pointer to the first longword in an array of longwords that
        is to be used as the arguments passed to your routine
        pointed to by p.
```
SEE ALSO

```c
    [RemTOF()](autodocs-2.0/amiga-lib-remtof.md), [<graphics/graphint.h>](autodocs-2.0/includes-graphics-graphint-h.md)
```
