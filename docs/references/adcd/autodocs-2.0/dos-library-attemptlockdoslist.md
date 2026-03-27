---
title: dos.library/AttemptLockDosList
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-attemptlockdoslist
functions: [Forbid, LockDosList, NextDosEntry, UnLockDosList]
libraries: [dos.library, exec.library]
---

# dos.library/AttemptLockDosList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AttemptLockDosList -- Attempt to lock the Dos Lists for use (V36)
```
SYNOPSIS

```c
    dlist = AttemptLockDosList(flags)
    D0                          D1

    struct [DosList](autodocs-2.0/includes-dos-dosextens-h.md) *AttemptLockDosList(ULONG)
```
FUNCTION

```c
    Locks the dos device list in preparation to walk the list.  If the
    list is 'busy' then this routine will return NULL.  See [LockDosList()](autodocs-2.0/dos-library-lockdoslist.md)
    for more information.
```
INPUTS

    flags - Flags stating which types of nodes you want to lock.
RESULT

    dlist - Pointer to the beginning of the list or NULL.  Not a valid
            node!
SEE ALSO

```c
    [LockDosList()](autodocs-2.0/dos-library-lockdoslist.md), [UnLockDosList()](autodocs-2.0/dos-library-unlockdoslist.md), [Forbid()](autodocs-2.0/exec-library-forbid.md), [NextDosEntry()](autodocs-2.0/dos-library-nextdosentry.md)
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [LockDosList — dos.library](../autodocs/dos.library.md#lockdoslist)
- [NextDosEntry — dos.library](../autodocs/dos.library.md#nextdosentry)
- [UnLockDosList — dos.library](../autodocs/dos.library.md#unlockdoslist)
