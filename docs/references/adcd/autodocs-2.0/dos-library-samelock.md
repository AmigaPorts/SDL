---
title: dos.library/SameLock
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-samelock
functions: []
libraries: []
---

# dos.library/SameLock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    SameLock -- returns whether two locks are on the same object (V36)
```
SYNOPSIS

```c
    value = SameLock(lock1, lock2)
    D0                D1     D2

    LONG SameLock(BPTR, BPTR)
```
FUNCTION

    Compares two locks.  Returns LOCK_SAME if they are on the same object,
    LOCK_SAME_VOLUME if on different objects on the same volume, and
    LOCK_DIFFERENT if they are on different volumes.  Always compare
    for equality or non-equality with the results, in case new return
    values are added.
INPUTS

    lock1 - 1st lock for comparison
    lock2 - 2nd lock for comparison
RESULT

    value - LOCK_SAME, LOCK_SAME_VOLUME, or LOCK_DIFFERENT
BUGS

```c
    Should do more extensive checks for NULL against a real lock, checking
    to see if the real lock is a lock on the root of the boot volume.

    In V36, it would return LOCK_SAME_VOLUME for different volumes on the
    same handler.  Also, LOCK_SAME_VOLUME was LOCK_SAME_HANDLER (now
    an obsolete define, see [<dos/dos.h>](autodocs-2.0/includes-dos-dos-h.md)).
```
SEE ALSO

```c
    [<dos/dos.h>](autodocs-2.0/includes-dos-dos-h.md)
```
