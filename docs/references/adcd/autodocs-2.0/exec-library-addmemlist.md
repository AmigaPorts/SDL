---
title: exec.library/AddMemList
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-addmemlist
functions: []
libraries: []
---

# exec.library/AddMemList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddMemList - add memory to the system free pool
SYNOPSIS

```c
    AddMemList( size, attributes, pri, base, name )
                 D0      D1        D2   A0    A1

    void AddMemList(ULONG, ULONG, LONG, APTR, STRPTR);
```
FUNCTION

```c
    Add a new region of memory to the system free pool.  The first few
    bytes will be used to hold the [MemHeader](autodocs-2.0/includes-exec-memory-h.md) structure.  The remainder
    will be made available to the rest of the world.
```
INPUTS

```c
    size - the size (in bytes) of the memory area
    attributes - the attributes word that the memory pool will have
    pri  - the priority for this memory.  CHIP memory has a pri of -10,
           16 bit expansion memory has a priority of 0.  The higher the
           priority, the closer to the head of the memory list it will
           be placed.
    base - the base of the new memory area
    name - the name that will be used in the memory header, or NULL
           if no name is to be provided.  This name is not copied, so it
           must remain valid for as long as the memory header is in the
           system.
```
SEE ALSO

```c
    [AllocMem](autodocs-2.0/exec-library-allocmem.md), [exec/memory.h](autodocs-2.0/includes-exec-memory-h.md)
```
