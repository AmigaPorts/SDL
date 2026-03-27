---
title: 11 Intuition Special Functions / Locking IntuitionBase
manual: libraries
chapter: libraries
section: 11-intuition-special-functions-locking-intuitionbase
functions: [LockIBase, UnlockIBase]
libraries: [intuition.library]
---

# 11 Intuition Special Functions / Locking IntuitionBase

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

It is sometimes necessary to examine the [IntuitionBase](autodocs-2.0/includes-intuition-intuitionbase-h.md) structure.  Items
such as the address of the active screen and window, current mouse
coordinates and more can be found there.  It is never a good idea to
simply read these fields, as they are prone to sudden change.  The
IntuitionBase structure must always be locked before looking at its fields.

It is necessary to inform Intuition that an application is about to
examine [IntuitionBase](autodocs-2.0/includes-intuition-intuitionbase-h.md) so that Intuition will not change any variables and
IntuitionBase will remain static during the access.  The call [LockIBase()](autodocs-2.0/intuition-library-lockibase.md)
will lock the state of IntuitionBase so that it may be examined.  During
the time that the application has IntuitionBase locked, all Intuition
input processing is frozen.  Make every effort to examine IntuitionBase
and release the lock as quickly as possible.  The values in IntuitionBase
are read-only.  Applications should never write values to IntuitionBase.


```c
    ULONG LockIBase( unsigned long dontknow );
```
[LockIBase()](autodocs-2.0/intuition-library-lockibase.md) is passed a ULONG (dontknow in the prototype above) indicating
the Intuition lock desired.  For all foreseeable uses of the call this
value should be 0.  LockIBase() returns a ULONG, that must be passed to
[UnlockIBase()](autodocs-2.0/intuition-library-unlockibase.md) later to allow [IntuitionBase](autodocs-2.0/includes-intuition-intuitionbase-h.md) to change once again.

Every call to [LockIBase()](autodocs-2.0/intuition-library-lockibase.md) must be matched by a subsequent call to
[UnlockIBase()](autodocs-2.0/intuition-library-unlockibase.md):


```c
    void UnlockIBase( unsigned long ibLock );
```
Set the ibLock argument to the value returned by the previous call to
[LockIBase()](autodocs-2.0/intuition-library-lockibase.md).


```c
    About LockIBase().
    ------------------
    This function should not be called while holding any other system
    locks such as [Layer](libraries/30-layers-the-layer-structure.md) and [Layer_Info](autodocs-2.0/includes-graphics-layers-h.md) locks.  Between calls to
    [LockIBase()](autodocs-2.0/intuition-library-lockibase.md) and [UnlockIBase()](autodocs-2.0/intuition-library-unlockibase.md), you may not call any Intuition
    or other high-level system functions so it is best to copy the
    information you need and release the lock as quickly as possible.

    About IntuitionBase.
    --------------------
    Never, ever, modify any of the fields in [IntuitionBase](autodocs-2.0/includes-intuition-intuitionbase-h.md) directly.
    Also, there are fields in IntuitionBase that are considered system
    private that should not be accessed, even for reading.  (Refer to the
    <intuition/[intuitionbase](autodocs-2.0/includes-intuition-intuitionbase-h.md)> include file.) Application programs
    cannot depend on (and should not use) the contents of these fields;
    their usage is subject to change in future revisions of Intuition.
```

---

## See Also

- [LockIBase — intuition.library](../autodocs/intuition.library.md#lockibase)
- [UnlockIBase — intuition.library](../autodocs/intuition.library.md#unlockibase)
