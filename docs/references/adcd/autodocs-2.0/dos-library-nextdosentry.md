---
title: dos.library/NextDosEntry
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-nextdosentry
functions: [AddDosEntry, FindDosEntry, LockDosList, RemDosEntry]
libraries: [dos.library]
---

# dos.library/NextDosEntry

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    NextDosEntry -- Get the next Dos [List](autodocs-2.0/includes-exec-lists-h.md) entry (V36)
```
SYNOPSIS

```c
    newdlist = NextDosEntry(dlist,flags)
    D0                       D1    D2

    struct [DosList](autodocs-2.0/includes-dos-dosextens-h.md) *NextDosEntry(struct [DosList](autodocs-2.0/includes-dos-dosextens-h.md) *,ULONG)
```
FUNCTION

```c
    Find the next Dos [List](autodocs-2.0/includes-exec-lists-h.md) entry of the right type.  You MUST have locked
    the types you're looking for.  Returns NULL if there are no more of
    that type in the list.
```
INPUTS

    dlist    - The current device entry.
    flags    - What type of entries to look for.
RESULT

    newdlist - The next device entry of the right type or NULL.
SEE ALSO

```c
    [AddDosEntry()](autodocs-2.0/dos-library-adddosentry.md), [RemDosEntry()](autodocs-2.0/dos-library-remdosentry.md), [FindDosEntry()](autodocs-2.0/dos-library-finddosentry.md), [LockDosList()](autodocs-2.0/dos-library-lockdoslist.md),
    [MakeDosEntry()](autodocs-2.0/dos-library-makedosentry.md), [FreeDosEntry()](autodocs-2.0/dos-library-freedosentry.md)
```

---

## See Also

- [AddDosEntry — dos.library](../autodocs/dos.library.md#adddosentry)
- [FindDosEntry — dos.library](../autodocs/dos.library.md#finddosentry)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [RemDosEntry — dos.library](../autodocs/dos.library.md#remdosentry)
