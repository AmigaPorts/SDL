---
title: disk.resource/GetUnitID
manual: autodocs-2.0
chapter: autodocs-2.0
section: disk-resource-getunitid
functions: []
libraries: []
---

# disk.resource/GetUnitID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME
   GetUnitID - find out what type of disk is out there

SYNOPSIS
   idtype = GetUnitID( unitNum ), DRResource

```c
    D0                  D0         A6

    LONG GetUnitID(LONG);
```
FUNCTION

```c
    Gets the drive ID for a given unit.  Note that this value may
    change if someone calls [ReadUnitID](autodocs-2.0/disk-resource-readunitid.md), and the drive id changes.
```
INPUTS

```c
    unitNum -- a legal unit number (zero through three)
```
RESULTS

    idtype -- the type of the disk drive.  Standard types are
            defined in the resource include file.
EXCEPTIONS

SEE ALSO

```c
    [ReadUnitID](autodocs-2.0/disk-resource-readunitid.md)
```
BUGS

