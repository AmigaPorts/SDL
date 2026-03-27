---
title: battmem.resource/WriteBattMem
manual: autodocs-2.0
chapter: autodocs-2.0
section: battmem-resource-writebattmem
functions: []
libraries: []
---

# battmem.resource/WriteBattMem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    WriteBattMem -- Write a bitstring to nonvolatile ram.  (V36)
```
SYNOPSIS

```c
    Error = WriteBattMem( Buffer, Offset, Len )
    D0                    A0      D0      D1

    ULONG WriteBattMem( APTR, ULONG, ULONG );
```
FUNCTION

    Write a bitstring to the nonvolatile ram.
INPUTS

    Buffer          Where to get the bitstring.
    Offset          Bit offset of first bit to write.
    Len             Length of bitstring to write.
RESULTS

    Error           Zero if no error.
NOTES

```c
    The battery-backed memory is checksummed. If a checksum error
    is detected, all bits in the battery-backed memory are
    silently set to zero.

    Partial byte writes (less than 8 bits) result in the bits
    written being read from the low-order bits of the source byte.
```
SEE ALSO

BUGS

