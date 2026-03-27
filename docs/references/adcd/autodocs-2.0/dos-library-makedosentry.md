---
title: dos.library/MakeDosEntry
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-makedosentry
functions: [AddDosEntry, AllocDosObject, FindDosEntry, LockDosList, NextDosEntry, RemDosEntry]
libraries: [dos.library]
---

# dos.library/MakeDosEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    MakeDosEntry -- Creates a [DosList](autodocs-2.0/includes-dos-dosextens-h.md) structure (V36)
```
SYNOPSIS

```c
    newdlist = MakeDosEntry(name, type)
    D0                       D1    D2

    struct [DosList](autodocs-2.0/includes-dos-dosextens-h.md) *MakeDosEntry(STRPTR, LONG)
```
FUNCTION

```c
    Create a [DosList](autodocs-2.0/includes-dos-dosextens-h.md) structure, including allocating a name and correctly
    null-terminating the BSTR.  It also sets the dol_Type field, and sets
    all other fields to 0.  This routine should be eliminated and replaced
    by a value passed to AllocDosObject()!
```
INPUTS

    name - name for the device/volume/assign node.
    type - type of node.
RESULT

    newdlist - The new device entry or NULL.
SEE ALSO

```c
    [AddDosEntry()](autodocs-2.0/dos-library-adddosentry.md), [RemDosEntry()](autodocs-2.0/dos-library-remdosentry.md), [FindDosEntry()](autodocs-2.0/dos-library-finddosentry.md), [LockDosList()](autodocs-2.0/dos-library-lockdoslist.md),
    [NextDosEntry()](autodocs-2.0/dos-library-nextdosentry.md), [FreeDosEntry()](autodocs-2.0/dos-library-freedosentry.md)
```

---

## See Also

- [AddDosEntry — dos.library](../autodocs/dos.library.md#adddosentry)
- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [FindDosEntry — dos.library](../autodocs/dos.library.md#finddosentry)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [NextDosEntry — dos.library](../autodocs/dos.library.md#nextdosentry)
- [RemDosEntry — dos.library](../autodocs/dos.library.md#remdosentry)
