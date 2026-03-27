---
title: exec.library/FreeMem
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-freemem
functions: []
libraries: []
---

# exec.library/FreeMem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FreeMem -- deallocate with knowledge
SYNOPSIS

```c
    FreeMem(memoryBlock, byteSize)
            A1           D0

    void FreeMem(void *,ULONG);
```
FUNCTION

    Free a region of memory, returning it to the system pool from which
    it came.  Freeing partial blocks back into the system pool is
    unwise.
NOTE

```c
    If a block of memory is freed twice, the system will Guru. The
    Alert is AN_FreeTwice ($01000009).   If you pass the wrong pointer,
    you will probably see AN_MemCorrupt $01000005.  Future versions may
    add more sanity checks to the memory lists.
```
INPUTS

```c
    memoryBlock - pointer to the memory block to free
    byteSize - the size of the desired block in bytes.  (The operating
            system will automatically round this number to a multiple of
            the system memory chunk size)
```
SEE ALSO

```c
    [AllocMem](autodocs-2.0/exec-library-allocmem.md)
```
