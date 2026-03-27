---
title: dos.library/Examine
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-examine
functions: [AllocDosObject, Lock, UnLock]
libraries: [dos.library]
---

# dos.library/Examine

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Examine -- Examine a directory or file associated with a lock
SYNOPSIS

```c
    success = Examine( lock, [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) )
    D0                  D1        D2

    BOOL Examine(BPTR,struct [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) *)
```
FUNCTION

```c
    Examine() fills in information in the [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) concerning the
    file or directory associated with the lock. This information
    includes the name, size, creation date and whether it is a file or
    directory.  [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) must be longword aligned.  Examine() gives
    a return code of zero if it fails.

    You may make a local copy of the [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md), as long as it is
    never passed to [ExNext()](autodocs-2.0/dos-library-exnext.md).
```
INPUTS

```c
    lock      - BCPL pointer to a lock
    infoBlock - pointer to a [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) (MUST be longword aligned)
```
RESULTS

    success - boolean
SPECIAL NOTE

```c
    [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) must be longword-aligned.  [AllocDosObject()](autodocs-2.0/dos-library-allocdosobject.md) will
    allocate them correctly for you.
```
SEE ALSO

```c
    [Lock()](autodocs-2.0/dos-library-lock.md), [UnLock()](autodocs-2.0/dos-library-unlock.md), [ExNext()](autodocs-2.0/dos-library-exnext.md), [ExamineFH()](autodocs-2.0/dos-library-examinefh.md), [<dos/dos.h>](autodocs-2.0/includes-dos-dos-h.md), [AllocDosObject()](autodocs-2.0/dos-library-allocdosobject.md),
    [ExAll()](autodocs-2.0/dos-library-exall.md)
```

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
