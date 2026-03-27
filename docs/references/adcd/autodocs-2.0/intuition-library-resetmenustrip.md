---
title: intuition.library/ResetMenuStrip
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-resetmenustrip
functions: [ClearMenuStrip, CloseWindow, OpenWindow, ResetMenuStrip, SetMenuStrip]
libraries: [intuition.library]
---

# intuition.library/ResetMenuStrip

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ResetMenuStrip -- Re-attach a menu strip to a window. (V36)
```
SYNOPSIS

```c
    Success = ResetMenuStrip( [Window](autodocs-2.0/includes-intuition-intuition-h.md), [Menu](autodocs-2.0/includes-intuition-intuition-h.md) )
    D0                        A0      A1

    BOOL ResetMenuStrip( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Menu](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    This function is simply a "fast" version of [SetMenuStrip()](autodocs-2.0/intuition-library-setmenustrip.md) that
    doesn't perform the precalculations of menu page sizes that
    [SetMenuStrip()](autodocs-2.0/intuition-library-setmenustrip.md) does.

    You may call this function ONLY IF the menu strip and all items
    and sub-items have not changed since the menu strip was passed to
    [SetMenuStrip()](autodocs-2.0/intuition-library-setmenustrip.md), with the following exceptions:

    - You may change the CHECKED flag to turn a checkmark on or off.
    - You may change the ITEMENABLED flag to enable/disable some
      [MenuItem](autodocs-2.0/includes-intuition-intuition-h.md) or [Menu](autodocs-2.0/includes-intuition-intuition-h.md) structures.

    In all other ways, this function performs like [SetMenuStrip()](autodocs-2.0/intuition-library-setmenustrip.md).

    The new sequence of events you can use is:
    - [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md)
    - [SetMenuStrip()](autodocs-2.0/intuition-library-setmenustrip.md)
    zero or more iterations of:
        - [ClearMenuStrip()](autodocs-2.0/intuition-library-clearmenustrip.md)
        - change CHECKED or ITEMENABLED flags
        - ResetMenuStrip()
    - [ClearMenuStrip()](autodocs-2.0/intuition-library-clearmenustrip.md)
    - [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md)
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to a [Window](autodocs-2.0/includes-intuition-intuition-h.md) structure
    [Menu](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the first menu in the menu strip
```
RESULT

    TRUE always.
BUGS

SEE ALSO

```c
    [SetMenuStrip()](autodocs-2.0/intuition-library-setmenustrip.md), [ClearMenuStrip()](autodocs-2.0/intuition-library-clearmenustrip.md)
```

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
