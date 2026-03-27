---
title: dos.library/AddDosEntry
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-adddosentry
functions: [AttemptLockDosList, FindDosEntry, LockDosList, NextDosEntry, RemDosEntry]
libraries: [dos.library]
---

# dos.library/AddDosEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddDosEntry -- Add a Dos [List](autodocs-2.0/includes-exec-lists-h.md) entry to the lists (V36)
```
SYNOPSIS

```c
    success = AddDosEntry(dlist)
    D0                     D1

    LONG AddDosEntry(struct [DosList](autodocs-2.0/includes-dos-dosextens-h.md) *)
```
FUNCTION

```c
    Adds a device, volume or assign to the dos devicelist.  Can fail if it
    conflicts with an existing entry (such as another assign to the same
    name or another device of the same name).  Volume nodes with different
    dates and the same name CAN be added, or with names that conflict with
    devices or assigns.  Note: the dos list does NOT have to be locked to
    call this.  Do not access dlist after adding unless you have locked the
    Dos [Device](autodocs-2.0/includes-exec-devices-h.md) list.

    An additional note concerning calling this from within a handler:
    in order to avoid deadlocks, your handler must either be multi-
    threaded, or it must attempt to lock the list before calling this
    function.  The code would look something like this:

    if (AttemptLockDosList(LDF_xxx|LDF_WRITE))
    {
            rc = AddDosEntry(...);
            UnLockDosList(LDF_xxx|LDF_WRITE);
    }

    If [AttemptLockDosList()](autodocs-2.0/dos-library-attemptlockdoslist.md) fails (i.e. it's locked already), check for
    messages at your filesystem port (don't wait!) and try the
    [AttemptLockDosList()](autodocs-2.0/dos-library-attemptlockdoslist.md) again.
```
INPUTS

```c
    dlist   - [Device](autodocs-2.0/includes-exec-devices-h.md) list entry to be added.
```
RESULT

    success - Success/Failure indicator
SEE ALSO

```c
    [RemDosEntry()](autodocs-2.0/dos-library-remdosentry.md), [FindDosEntry()](autodocs-2.0/dos-library-finddosentry.md), [NextDosEntry()](autodocs-2.0/dos-library-nextdosentry.md), [LockDosList()](autodocs-2.0/dos-library-lockdoslist.md),
    [MakeDosEntry()](autodocs-2.0/dos-library-makedosentry.md), [FreeDosEntry()](autodocs-2.0/dos-library-freedosentry.md), [AttemptLockDosList()](autodocs-2.0/dos-library-attemptlockdoslist.md)
```

---

## See Also

- [AttemptLockDosList — dos.library](../autodocs/dos.library.md#attemptlockdoslist)
- [FindDosEntry — dos.library](../autodocs/dos.library.md#finddosentry)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [NextDosEntry — dos.library](../autodocs/dos.library.md#nextdosentry)
- [RemDosEntry — dos.library](../autodocs/dos.library.md#remdosentry)
