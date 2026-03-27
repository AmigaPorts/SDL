---
title: dos.library/ExNext
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-exnext
functions: [AllocDosObject, IoErr, Lock, UnLock]
libraries: [dos.library]
---

# dos.library/ExNext

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ExNext -- Examine the next entry in a directory
SYNOPSIS

```c
    success = ExNext( lock, [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) )
    D0                 D1        D2

    BOOL ExNext(BPTR, struct [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) *)
```
FUNCTION

```c
    This routine is passed a directory lock and a [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) that
    have been initialized by a previous call to [Examine()](autodocs-2.0/dos-library-examine.md), or updated
    by a previous call to ExNext().  ExNext() gives a return code of zero
    on failure.  The most common cause of failure is reaching the end
    of the list of files in the owning directory.  In this case, [IoErr](autodocs-2.0/dos-library-ioerr.md)
    will return ERROR_NO_MORE_ENTRIES and a good exit is appropriate.

    So, follow these steps to examine a directory:
    1) Pass a Lock and a [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) to [Examine()](autodocs-2.0/dos-library-examine.md).  The lock must
       be on the directory you wish to examine.
    2) Pass ExNext() the same lock and [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md).
    3) Do something with the information returned in the [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md).
       Note that the fib_DirEntryType field is positive for directories,
       negative for files.
    4) Keep calling ExNext() until it returns FALSE.  Check [IoErr()](autodocs-2.0/dos-library-ioerr.md)
       to ensure that the reason for failure was ERROR_NO_MORE_ENTRIES.

    Note: if you wish to recursively scan the file tree and you find
    another directory while ExNext()ing you must Lock that directory and
    [Examine()](autodocs-2.0/dos-library-examine.md) it using a new [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md).  Use of the same
    [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) to enter a directory would lose important state
    information such that it will be impossible to continue scanning
    the parent directory.  While it is permissible to [UnLock()](autodocs-2.0/dos-library-unlock.md) and [Lock()](autodocs-2.0/dos-library-lock.md)
    the parent directory between ExNext() calls, this is NOT recommended.
    Important state information is associated with the parent lock, so
    if it is freed between ExNext() calls this information has to be
    rebuilt on each new ExNext() call, and will significantly slow down
    directory scanning.

    It is NOT legal to [Examine()](autodocs-2.0/dos-library-examine.md) a file, and then to ExNext() from that
    [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md).       You may make a local copy of the [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md), as
    long as it is never passed back to the operating system.
```
INPUTS

```c
    lock - BCPL pointer to a lock originally used for the [Examine()](autodocs-2.0/dos-library-examine.md) call
    infoBlock - pointer to a [FileInfoBlock](autodocs-2.0/includes-dos-dos-h.md) used on the previous [Examine()](autodocs-2.0/dos-library-examine.md)
                or ExNext() call.
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
    [Examine()](autodocs-2.0/dos-library-examine.md), [Lock()](autodocs-2.0/dos-library-lock.md), [UnLock()](autodocs-2.0/dos-library-unlock.md), [IoErr()](autodocs-2.0/dos-library-ioerr.md), [ExamineFH()](autodocs-2.0/dos-library-examinefh.md), [AllocDosObject()](autodocs-2.0/dos-library-allocdosobject.md),
    [ExAll()](autodocs-2.0/dos-library-exall.md)
```

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
