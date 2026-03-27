---
title: amiga.lib/RemTOF
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-remtof
functions: []
libraries: []
---

# amiga.lib/RemTOF

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RemTOF - remove a task from the VBlank interrupt server chain.
SYNOPSIS

```c
    RemTOF(i);

    VOID RemTOF(struct [Isrvstr](autodocs-2.0/includes-graphics-graphint-h.md) *);
```
FUNCTION

    Removes a task from the vertical-blanking interval interrupt server
    chain.
INPUTS

```c
    i - pointer to an [Isrvstr](autodocs-2.0/includes-graphics-graphint-h.md) structure
```
SEE ALSO

```c
    [AddTOF()](autodocs-2.0/amiga-lib-addtof.md), [<graphics/graphint.h>](autodocs-2.0/includes-graphics-graphint-h.md)
```
