---
title: dos.library/FreeDosEntry
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-freedosentry
functions: [AddDosEntry, FindDosEntry, FreeDosObject, LockDosList, NextDosEntry, RemDosEntry]
libraries: [dos.library]
---

# dos.library/FreeDosEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeDosEntry -- Frees an entry created by [MakeDosEntry](autodocs-2.0/dos-library-makedosentry.md) (V36)
```
SYNOPSIS

```c
    FreeDosEntry(dlist)
                   D1

    void FreeDosEntry(struct [DosList](autodocs-2.0/includes-dos-dosextens-h.md) *)
```
FUNCTION

```c
    Frees an entry created by [MakeDosEntry()](autodocs-2.0/dos-library-makedosentry.md).  This routine should be
    eliminated and replaced by a value passed to FreeDosObject()!
```
INPUTS

```c
    dlist - [DosList](autodocs-2.0/includes-dos-dosextens-h.md) to free.
```
SEE ALSO

```c
    [AddDosEntry()](autodocs-2.0/dos-library-adddosentry.md), [RemDosEntry()](autodocs-2.0/dos-library-remdosentry.md), [FindDosEntry()](autodocs-2.0/dos-library-finddosentry.md), [LockDosList()](autodocs-2.0/dos-library-lockdoslist.md),
    [NextDosEntry()](autodocs-2.0/dos-library-nextdosentry.md), [MakeDosEntry()](autodocs-2.0/dos-library-makedosentry.md)
```

---

## See Also

- [AddDosEntry — dos.library](../autodocs/dos.library.md#adddosentry)
- [FindDosEntry — dos.library](../autodocs/dos.library.md#finddosentry)
- [FreeDosObject — dos.library](../autodocs/dos.library.md#freedosobject)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [NextDosEntry — dos.library](../autodocs/dos.library.md#nextdosentry)
- [RemDosEntry — dos.library](../autodocs/dos.library.md#remdosentry)
