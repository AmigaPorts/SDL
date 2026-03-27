---
title: expansion.library/AllocExpansionMem
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-allocexpansionmem
functions: []
libraries: []
---

# expansion.library/AllocExpansionMem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AllocExpansionMem - allocate expansion memory
SYNOPSIS

```c
    startSlot = AllocExpansionMem( numSlots, slotOffset )
    D0                             D0        D1
```
FUNCTION

```c
    (Not typically called by user code)

    This function allocates numslots of expansion space (each slot
    is E_SLOTSIZE bytes).  It returns the slot number of the
    start of the expansion memory.  The EC_MEMADDR macro may be
    used to convert this to a memory address.

    Boards that fit the expansion architecture have alignment
    rules.  Normally a board must be on a binary boundary of its
    size.  Four and Eight megabyte boards have special rules.
    User defined boards might have other special rules.

    If AllocExpansionMem() succeeds, the startSlot will satisfy
    the following equation:

            (startSlot - slotOffset) MOD slotAlign = 0
```
INPUTS

    numSlots - the number of slots required.
    slotOffset - an offset from that boundary for startSlot.
RESULTS

    startSlot - the slot number that was allocated, or -1 for error.
EXAMPLES


```c
            AllocExpansionMem( 2, 0 )

    Tries to allocate 2 slots on a two slot boundary.

            AllocExpansionMem( 64, 32 )

    This is the allocation rule for 4 meg boards.  It allocates
    4 megabytes (64 slots) on an odd 2 meg boundary.
```
EXCEPTIONS

SEE ALSO

```c
    [FreeExpansionMem](autodocs-2.0/expansion-library-freeexpansionmem.md)
```
BUGS

