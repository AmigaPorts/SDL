---
title: dos.library/FindDosEntry
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-finddosentry
functions: [AddDosEntry, LockDosList, NextDosEntry, RemDosEntry]
libraries: [dos.library]
---

# dos.library/FindDosEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FindDosEntry -- Finds a specific Dos [List](autodocs-2.0/includes-exec-lists-h.md) entry (V36)
```
SYNOPSIS

```c
    newdlist = FindDosEntry(dlist,name,flags)
    D0                       D1    D2   D3

    struct [DosList](autodocs-2.0/includes-dos-dosextens-h.md) *FindDosEntry(struct [DosList](autodocs-2.0/includes-dos-dosextens-h.md) *,STRPTR,ULONG)
```
FUNCTION

    Locates an entry on the device list.  Starts with the entry dlist.
    NOTE: must be called with the device list locked, no references may be
    made to dlist after unlocking.
INPUTS

```c
    dlist    - The device entry to start with.
    name     - Name of device entry (without ':') to locate.
    flags    - Search control flags.  Use the flags you passed to
               [LockDosList](autodocs-2.0/dos-library-lockdoslist.md), or a subset of them.  LDF_READ/LDF_WRITE are
               not required for this call.
```
RESULT

    newdlist - The device entry or NULL
SEE ALSO

```c
    [AddDosEntry()](autodocs-2.0/dos-library-adddosentry.md), [RemDosEntry()](autodocs-2.0/dos-library-remdosentry.md), [NextDosEntry()](autodocs-2.0/dos-library-nextdosentry.md), [LockDosList()](autodocs-2.0/dos-library-lockdoslist.md),
    [MakeDosEntry()](autodocs-2.0/dos-library-makedosentry.md), [FreeDosEntry()](autodocs-2.0/dos-library-freedosentry.md)
```

---

## See Also

- [AddDosEntry — dos.library](../autodocs/dos.library.md#adddosentry)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [NextDosEntry — dos.library](../autodocs/dos.library.md#nextdosentry)
- [RemDosEntry — dos.library](../autodocs/dos.library.md#remdosentry)
