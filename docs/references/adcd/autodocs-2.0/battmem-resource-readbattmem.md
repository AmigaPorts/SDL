---
title: battmem.resource/ReadBattMem
manual: autodocs-2.0
chapter: autodocs-2.0
section: battmem-resource-readbattmem
functions: []
libraries: []
---

# battmem.resource/ReadBattMem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ReadBattMem -- Read a bitstring from nonvolatile ram.  (V36)
```
SYNOPSIS

```c
    Error = ReadBattMem( Buffer, Offset, Len )
    D0                   A0      D0      D1

    ULONG ReadBattMem( APTR, ULONG, ULONG );
```
FUNCTION

    Read a bitstring from nonvolatile ram.
INPUTS

    Buffer          Where to put the bitstring.
    Offset          Bit offset of first bit to read.
    Len             Length of bitstring to read.
RESULTS

    Error           Zero if no error.
NOTES

```c
    The battery-backed memory is checksummed. If a checksum error
    is detected, all bits in the battery-backed memory are
    silently set to zero.

    Bits in the battery-backed memory that do not exist are read
    as zero.

    Partial byte reads (less than 8 bits) result in the bits read
    being put in the low-order bits of the destination byte.
```
SEE ALSO

BUGS

