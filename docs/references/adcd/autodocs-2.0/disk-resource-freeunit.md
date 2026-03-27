---
title: disk.resource/FreeUnit
manual: autodocs-2.0
chapter: autodocs-2.0
section: disk-resource-freeunit
functions: []
libraries: []
---

# disk.resource/FreeUnit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME
   FreeUnit - deallocate the disk

SYNOPSIS
   FreeUnit( unitNum ), DRResource

```c
              D0         A6

    void FreeUnit(LONG);
```
FUNCTION

```c
    This routine deallocates one of the units of the disk.  It should
    be called when done with the disk.  Do not call it if you did
    no successfully allocate the disk (there is no protection -- you
    will probably crash the disk system).
```
INPUTS

```c
    unitNum -- a legal unit number (zero through three)
```
RESULTS

EXCEPTIONS

SEE ALSO

    FreeUnit
BUGS

    Doesn't check if you own the unit, or even if anyone owns it.
