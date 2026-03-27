---
title: dos.library/Info
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-info
functions: [Info]
libraries: [dos.library]
---

# dos.library/Info

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Info -- Returns information about the disk
SYNOPSIS

```c
    success = Info( lock, parameterBlock )
    D0              D1    D2

    BOOL Info(BPTR, struct [InfoData](autodocs-2.0/includes-dos-dos-h.md) *)
```
FUNCTION

```c
    Info() can be used to find information about any disk in use.
    'lock' refers to the disk, or any file on the disk. The parameter
    block is returned with information about the size of the disk,
    number of free blocks and any soft errors.
```
INPUTS

```c
    lock           - BCPL pointer to a lock
    parameterBlock - pointer to an [InfoData](autodocs-2.0/includes-dos-dos-h.md) structure
                     (longword aligned)
```
RESULTS

    success - boolean
SPECIAL NOTE:

```c
    Note that [InfoData](autodocs-2.0/includes-dos-dos-h.md) structure must be longword aligned.
```

---

## See Also

- [Info — dos.library](../autodocs/dos.library.md#info)
