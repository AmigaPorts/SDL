---
title: dos.library/OpenFromLock
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-openfromlock
functions: [Close, Lock, Open, UnLock]
libraries: [dos.library]
---

# dos.library/OpenFromLock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    OpenFromLock -- Opens a file you have a lock on (V36)
```
SYNOPSIS

```c
    fh = OpenFromLock(lock)
    D0                 D1

    BPTR OpenFromLock(BPTR)
```
FUNCTION

```c
    Given a lock, this routine performs an open on that lock.  If the open
    succeeds, the lock is (effectively) relinquished, and should not be
    UnLock()ed or used.  If the open fails, the lock is still usable.
    The lock associated with the file internally is of the same access
    mode as the lock you gave up - shared is similar to MODE_OLDFILE,
    exclusive is similar to MODE_NEWFILE.
```
INPUTS

    lock - Lock on object to be opened.
RESULT

    fh   - Newly opened file handle or NULL for failure
BUGS

```c
    In the original V36 autodocs, this was shown (incorrectly) as
    taking a Mode parameter as well.  The prototypes and pragmas were
    also wrong.
```
SEE ALSO

```c
    [Open()](autodocs-2.0/dos-library-open.md), [Close()](autodocs-2.0/dos-library-close.md), [Lock()](autodocs-2.0/dos-library-lock.md), [UnLock()](autodocs-2.0/dos-library-unlock.md)
```

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
