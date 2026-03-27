---
title: intuition.library/GetScreenDrawInfo
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-getscreendrawinfo
functions: [FreeScreenDrawInfo, GetScreenDrawInfo, LockPubScreen]
libraries: [intuition.library]
---

# intuition.library/GetScreenDrawInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GetScreenDrawInfo -- Get pointer to rendering information. (V36)
```
SYNOPSIS

```c
    DrInfo = GetScreenDrawInfo( [Screen](autodocs-2.0/includes-intuition-screens-h.md) )
    D0                          A0

    struct [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) *GetScreenDrawInfo( struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) * );
```
FUNCTION

```c
    Returns a pointer to a [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) structure derived from the
    screen passed.  This data structure is READ ONLY.  The field
    dri_Version identifies which version of struct [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) you
    are given a pointer to.
```
INPUTS

```c
    [Screen](autodocs-2.0/includes-intuition-screens-h.md)        - pointer to a valid, open screen.
```
RESULT

```c
    DrInfo - pointer to a system-allocated [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) structure,
    as defined in [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md).
```
NOTES

```c
    Some information in the [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) structure may in the future
    be calculated the first time this function is called for a
    particular screen.

    You must call [FreeScreenDrawInfo()](autodocs-2.0/intuition-library-freescreendrawinfo.md) when you are done using the
    returned pointer.

    This function does not prevent a screen from closing.  Apply it
    only to the screens you opened yourself, or apply a protocol
    such as [LockPubScreen()](autodocs-2.0/intuition-library-lockpubscreen.md).

    WARNING: Until further notice, the pointer returned does not
    remain valid after the screen is closed.

    This function and [FreeScreenDrawInfo()](autodocs-2.0/intuition-library-freescreendrawinfo.md) don't really do much now,
    but they provide an upward compatibility path.  That means that
    if you misuse them today, they probably won't cause a problem,
    although they may someday later.  So, please be very careful
    only to use the [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) structure between calls to
    GetScreenDrawInfo() and [FreeScreenDrawInfo()](autodocs-2.0/intuition-library-freescreendrawinfo.md), and be sure
    that you don't forget [FreeScreenDrawInfo()](autodocs-2.0/intuition-library-freescreendrawinfo.md).
```
BUGS

    Does not reflect to changes in screen modes, depth, or pens.
SEE ALSO

```c
    [FreeScreenDrawInfo()](autodocs-2.0/intuition-library-freescreendrawinfo.md), [LockPubScreen()](autodocs-2.0/intuition-library-lockpubscreen.md), [intuition/screens.h](autodocs-2.0/includes-intuition-screens-h.md)
```

---

## See Also

- [FreeScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#freescreendrawinfo)
- [GetScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#getscreendrawinfo)
- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
