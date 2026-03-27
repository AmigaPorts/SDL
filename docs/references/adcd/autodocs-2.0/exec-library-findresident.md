---
title: exec.library/FindResident
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-findresident
functions: []
libraries: []
---

# exec.library/FindResident

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FindResident - find a resident module by name
SYNOPSIS

```c
    resident = FindResident(name)
    D0                      A1

    struct [Resident](autodocs-2.0/includes-exec-resident-h.md) *FindResident(STRPTR);
```
FUNCTION

```c
    Search the system resident tag list for a resident tag ("ROMTag") with
    the given name.  If found return a pointer to the resident tag
    structure, else return zero.

    [Resident](autodocs-2.0/includes-exec-resident-h.md) modules are used by the system to pull all its parts
    together at startup.  [Resident](autodocs-2.0/includes-exec-resident-h.md) tags are also found in disk based
    devices and libraries.
```
INPUTS

    name - pointer to name string
RESULT

    resident - pointer to the resident tag structure or
            zero if none found.
SEE ALSO

```c
    [exec/resident.h](autodocs-2.0/includes-exec-resident-h.md), [InitResident](autodocs-2.0/exec-library-initresident.md)
```
