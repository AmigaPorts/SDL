---
title: disk.resource/AllocUnit
manual: autodocs-2.0
chapter: autodocs-2.0
section: disk-resource-allocunit
functions: []
libraries: []
---

# disk.resource/AllocUnit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME
   AllocUnit - allocate a unit of the disk

SYNOPSIS
   Success = AllocUnit( unitNum ), DRResource

```c
    D0                   D0         A6

    BOOL AllocUnit(LONG);
```
FUNCTION

```c
    This routine allocates one of the units of the disk.  It should
    be called before trying to use the disk (via GetUnit).

    In reality, it is perfectly fine to use [GetUnit/GiveUnit](autodocs-2.0/disk-resource-giveunit.md) if AllocUnit
    fails.  Do NOT call [FreeUnit](autodocs-2.0/disk-resource-freeunit.md) if AllocUnit did not succeed.  This
    has been the case for all revisions of disk.resource.
```
INPUTS

```c
    unitNum -- a legal unit number (zero through three)
```
RESULTS

    Success -- nonzero if successful.  zero on failure.
EXCEPTIONS

SEE ALSO

BUGS

