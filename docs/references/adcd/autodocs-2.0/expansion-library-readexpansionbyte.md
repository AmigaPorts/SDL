---
title: expansion.library/ReadExpansionByte
manual: autodocs-2.0
chapter: autodocs-2.0
section: expansion-library-readexpansionbyte
functions: []
libraries: []
---

# expansion.library/ReadExpansionByte

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ReadExpansionByte - read a byte nybble by nybble.
SYNOPSIS

```c
    byte = ReadExpansionByte( board, offset )
    D0                        A0     D0
```
FUNCTION

```c
    (Not typically called by user code)

    ReadExpansionByte reads a byte from a new-style expansion
    board.  These boards have their readable data organized
    as a series of nybbles in memory.  This routine reads
    two nybbles and returns the byte value.

    In general, this routine will only be called by [ReadExpansionRom](autodocs-2.0/expansion-library-readexpansionrom.md).

    The offset is a byte offset, as if into a [ExpansionRom](autodocs-2.0/includes-libraries-configregs-h.md) structure.
    The actual memory address read will be four times larger.
    The macros EROFFSET and ECOFFSET are provided to help get
    these offsets from C.
```
INPUTS

    board - a pointer to the base of a new style expansion board.
    offset - a logical offset from the board base
RESULTS

    byte - a byte of data from the expansion board.
EXAMPLES

```c
    byte = ReadExpansionByte( cd->BoardAddr, EROFFSET( er_Type ) );
    ints = ReadExpansionByte( cd->BoardAddr, ECOFFSET( ec_Interrupt ) );
```
SEE ALSO

```c
    [WriteExpansionByte](autodocs-2.0/expansion-library-writeexpansionbyte.md), [ReadExpansionRom](autodocs-2.0/expansion-library-readexpansionrom.md)
```
