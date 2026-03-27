---
title: intuition.library/LockIBase
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-lockibase
functions: [LockLayerInfo, ObtainSemaphore, UnlockIBase]
libraries: [exec.library, intuition.library, layers.library]
---

# intuition.library/LockIBase

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    LockIBase -- Invoke semaphore arbitration of [IntuitionBase](autodocs-2.0/includes-intuition-intuitionbase-h.md).
```
SYNOPSIS

```c
    Lock = LockIBase( LockNumber )
    D0                D0

    ULONG LockIBase( ULONG );
```
FUNCTION

```c
    Grabs Intuition internal semaphore so that caller may examine
    [IntuitionBase](autodocs-2.0/includes-intuition-intuitionbase-h.md) safely.  This function is not a magic "fix all my
    race conditions" panacea.

    The idea here is that you can get the locks Intuition needs before
    such [IntuitionBase](autodocs-2.0/includes-intuition-intuitionbase-h.md) fields as ActiveWindow and FirstScreen are
    changed, or linked lists of windows and screens are changed.

    Do Not Get Tricky with this entry point, and do not hold these locks
    for long, as all Intuition input processing will wait for you to
    surrender the lock by a call to [UnlockIBase()](autodocs-2.0/intuition-library-unlockibase.md).

    NOTE WELL: A call to this function MUST be paired with a subsequent
    call to [UnlockIBase()](autodocs-2.0/intuition-library-unlockibase.md), and soon, please.

    NOTE WELL: Do not call any Intuition functions (nor any graphics,
    layers, dos, or other high-level system function) while
    holding this lock.
```
INPUTS

    A long unsigned integer, LockNumber, specifies which of Intuition's
    internal locks you want to get.  This parameter should be zero for all
    forseeable uses of this function, which will let you examine active
    fields and linked lists of screens and windows with safety.
RESULT

```c
    Returns another ULONG which should be passed to [UnlockIBase()](autodocs-2.0/intuition-library-unlockibase.md) to
    surrender the lock gotten by this call.
```
BUGS

    This function must not be called while holding any other system locks
    such as layer or LayerInfo locks.
SEE ALSO

```c
    [UnlockIBase()](autodocs-2.0/intuition-library-unlockibase.md), [layers.library/LockLayerInfo()](autodocs-2.0/layers-library-locklayerinfo.md),
    [exec.library/ObtainSemaphore()](autodocs-2.0/exec-library-obtainsemaphore.md)
```

---

## See Also

- [LockLayerInfo — layers.library](../autodocs/layers.library.md#locklayerinfo)
- [ObtainSemaphore — exec.library](../autodocs/exec.library.md#obtainsemaphore)
- [UnlockIBase — intuition.library](../autodocs/intuition.library.md#unlockibase)
