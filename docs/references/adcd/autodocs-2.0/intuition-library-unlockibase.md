---
title: intuition.library/UnlockIBase
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-unlockibase
functions: [LockIBase]
libraries: [intuition.library]
---

# intuition.library/UnlockIBase

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    UnlockIBase -- Surrender an Intuition lock gotten by [LockIBase()](autodocs-2.0/intuition-library-lockibase.md).
```
SYNOPSIS

```c
    UnlockIBase( Lock )
                 A0

    VOID UnlockIBase( ULONG );
```
FUNCTION


```c
    Surrenders lock gotten by [LockIBase()](autodocs-2.0/intuition-library-lockibase.md).

    Calling this function when you do not own the specified lock will
    immediately crash the system.
```
INPUTS

```c
    The value returned by [LockIBase()](autodocs-2.0/intuition-library-lockibase.md) should be passed to this function,
    to specify which internal lock is to be freed.

    Note that the parameter is passed in A0, not D0, for historical
    reasons.
```
RESULT

    None
BUGS

SEE ALSO

```c
    [LockIBase()](autodocs-2.0/intuition-library-lockibase.md)
```

---

## See Also

- [LockIBase — intuition.library](../autodocs/intuition.library.md#lockibase)
