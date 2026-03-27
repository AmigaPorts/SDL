---
title: intuition.library/ClearMenuStrip
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-clearmenustrip
functions: [ResetMenuStrip, SetMenuStrip, Wait]
libraries: [exec.library, intuition.library]
---

# intuition.library/ClearMenuStrip

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ClearMenuStrip -- Clear (detach) the menu strip from the window.
```
SYNOPSIS

```c
    ClearMenuStrip( [Window](autodocs-2.0/includes-intuition-intuition-h.md) )
                    A0

    VOID ClearMenuStrip( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    Detaches the current menu strip from the window; menu strips
    are attached to windows using the [SetMenuStrip()](autodocs-2.0/intuition-library-setmenustrip.md) function
    (or, for V36, [ResetMenuStrip()](autodocs-2.0/intuition-library-resetmenustrip.md) ).

    If the menu is in use (for that matter if any menu is in use)
    this function will block (Wait()) until the user has finished.

    Call this function before you make any changes to the data
    in a [Menu](autodocs-2.0/includes-intuition-intuition-h.md) or [MenuItem](autodocs-2.0/includes-intuition-intuition-h.md) structure which is part of a menu
    strip linked into a window.
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to a window structure
```
RESULT

    None
BUGS

SEE ALSO

```c
    [SetMenuStrip()](autodocs-2.0/intuition-library-setmenustrip.md), [ResetMenuStrip()](autodocs-2.0/intuition-library-resetmenustrip.md)
```

---

## See Also

- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
