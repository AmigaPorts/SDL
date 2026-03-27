---
title: intuition.library/FreeScreenDrawInfo
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-freescreendrawinfo
functions: [FreeScreenDrawInfo, GetScreenDrawInfo]
libraries: [intuition.library]
---

# intuition.library/FreeScreenDrawInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    FreeScreenDrawInfo -- Finish using a [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) structure. (V36)
```
SYNOPSIS

```c
    FreeScreenDrawInfo( [Screen](autodocs-2.0/includes-intuition-screens-h.md), DrInfo )
                        A0      A1

    VOID FreeScreenDrawInfo( struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) *, struct [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) * );
```
FUNCTION

```c
    Declares that you are finished with the [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) structure
    returned by [GetScreenDrawInfo()](autodocs-2.0/intuition-library-getscreendrawinfo.md).
```
INPUTS

```c
    [Screen](autodocs-2.0/includes-intuition-screens-h.md)           - pointer to screen passed to [GetScreenDrawInfo()](autodocs-2.0/intuition-library-getscreendrawinfo.md)
    DrInfo      - pointer to [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) returned by [GetScreenDrawInfo()](autodocs-2.0/intuition-library-getscreendrawinfo.md)
```
RESULT

    None
NOTES

```c
    This function, and [GetScreenDrawInfo()](autodocs-2.0/intuition-library-getscreendrawinfo.md), don't really do much, but
    they provide an upward compatibility path.  That means that
    if you misuse them today, they probably won't cause a problem,
    although they may someday later.  So, please be very careful
    only to use the [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) structure between calls to
    [GetScreenDrawInfo()](autodocs-2.0/intuition-library-getscreendrawinfo.md) and FreeScreenDrawInfo(), and be sure
    that you don't forget FreeScreenDrawInfo().
```
BUGS

SEE ALSO

```c
    [GetScreenDrawInfo()](autodocs-2.0/intuition-library-getscreendrawinfo.md)
```

---

## See Also

- [FreeScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#freescreendrawinfo)
- [GetScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#getscreendrawinfo)
