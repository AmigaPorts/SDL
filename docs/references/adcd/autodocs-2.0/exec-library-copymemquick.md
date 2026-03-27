---
title: exec.library/CopyMemQuick
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-copymemquick
functions: []
libraries: []
---

# exec.library/CopyMemQuick

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    CopyMemQuick - optimized memory copy function
SYNOPSIS

```c
    CopyMemQuick( source, dest, size )
                  A0      A1    D0

    void CopyMemQuick(ULONG *,ULONG *,ULONG);
```
FUNCTION

```c
    CopyMemQuick is a highly optimized memory copy function, with
    restrictions on the size and alignment of its arguments. Both the
    source and destination pointers must be longword aligned.  In
    addition, the size must be an integral number of longwords (e.g.
    the size must be evenly divisible by four).

    Arbitrary overlapping copies are not supported.

    The internal implementation of this function will change from system
    to system, and may be implemented via hardware DMA.
```
INPUTS

```c
    source - a pointer to the source data region, long aligned
    dest -  a pointer to the destination data region, long aligned
    size -  the size (in bytes) of the memory area.  Zero copies
            zero bytes.
```
SEE ALSO

```c
    [CopyMem](autodocs-2.0/exec-library-copymem.md)
```
