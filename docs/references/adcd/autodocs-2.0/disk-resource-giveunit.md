---
title: disk.resource/GiveUnit
manual: autodocs-2.0
chapter: autodocs-2.0
section: disk-resource-giveunit
functions: []
libraries: []
---

# disk.resource/GiveUnit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME
   GiveUnit - Free the disk back up

SYNOPSIS
   GiveUnit(), DRResource

```c
                A6

    void GiveUnit();
```
FUNCTION

    This routine frees the disk after a driver is done with it.
    If others are waiting, it will notify them.
INPUTS

RESULTS

EXCEPTIONS

SEE ALSO

```c
    [GetUnit](autodocs-2.0/disk-resource-getunit.md)
```
BUGS

    In pre-V36, GiveUnit didn't check if you owned the unit.  A patch
    for this was part of 1.3.1 SetPatch.  Fixed in V36.
