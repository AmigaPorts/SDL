---
title: dos.library/RemDosEntry
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-remdosentry
functions: [AddDosEntry, FindDosEntry, LockDosList, NextDosEntry]
libraries: [dos.library]
---

# dos.library/RemDosEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemDosEntry -- Removes a Dos [List](autodocs-2.0/includes-exec-lists-h.md) entry from it's list (V36)
```
SYNOPSIS

```c
    success = RemDosEntry(dlist)
    D0                     D1

    BOOL RemDosEntry(struct [DosList](autodocs-2.0/includes-dos-dosextens-h.md) *)
```
FUNCTION

```c
    This removes an entry from the Dos [Device](autodocs-2.0/includes-exec-devices-h.md) list.  The memory associated
    with the entry is NOT freed.  NOTE: you must have locked the Dos [List](autodocs-2.0/includes-exec-lists-h.md)
    with the appropriate flags before calling this routine.  Handler
    writers should see the [AddDosEntry()](autodocs-2.0/dos-library-adddosentry.md) caveats about locking and use
    a similar workaround to avoid deadlocks.
```
INPUTS

```c
    dlist   - [Device](autodocs-2.0/includes-exec-devices-h.md) list entry to be removed.
```
RESULT

    success - Success/failure indicator
SEE ALSO

```c
    [AddDosEntry()](autodocs-2.0/dos-library-adddosentry.md), [FindDosEntry()](autodocs-2.0/dos-library-finddosentry.md), [NextDosEntry()](autodocs-2.0/dos-library-nextdosentry.md), [LockDosList()](autodocs-2.0/dos-library-lockdoslist.md),
    [MakeDosEntry()](autodocs-2.0/dos-library-makedosentry.md), [FreeDosEntry()](autodocs-2.0/dos-library-freedosentry.md)
```

---

## See Also

- [AddDosEntry — dos.library](../autodocs/dos.library.md#adddosentry)
- [FindDosEntry — dos.library](../autodocs/dos.library.md#finddosentry)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [NextDosEntry — dos.library](../autodocs/dos.library.md#nextdosentry)
