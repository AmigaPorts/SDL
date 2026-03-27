---
title: intuition.library/SetMenuStrip
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-setmenustrip
functions: [ClearMenuStrip, CloseWindow, OpenWindow, ResetMenuStrip, SetMenuStrip]
libraries: [intuition.library]
---

# intuition.library/SetMenuStrip

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetMenuStrip -- Attach a menu strip to a window.
SYNOPSIS

```c
    Success = SetMenuStrip( [Window](autodocs-2.0/includes-intuition-intuition-h.md), [Menu](autodocs-2.0/includes-intuition-intuition-h.md) )
    D0                      A0      A1

    BOOL SetMenuStrip( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, struct [Menu](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    Attaches the menu strip to the window.  After calling this routine,
    if the user presses the menu button, this specified menu strip
    will be displayed and accessible by the user.

    Menus with zero menu items are not allowed.

    NOTE:  You should always design your menu strip changes to be a
    two-way operation, where for every menu strip you add to your
    window you should always plan to clear that strip sometime.  Even
    in the simplest case, where you will have just one menu strip for
    the lifetime of your window, you should always clear the menu strip
    before closing the window.  If you already have a menu strip attached
    to this window, the correct procedure for changing to a new menu
    strip involves calling [ClearMenuStrip()](autodocs-2.0/intuition-library-clearmenustrip.md) to clear the old first.

    The sequence of events should be:
    - [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md)
    - zero or more iterations of:
    - SetMenuStrip()
    - [ClearMenuStrip()](autodocs-2.0/intuition-library-clearmenustrip.md)
    - [CloseWindow()](autodocs-2.0/intuition-library-closewindow.md)
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to a [Window](autodocs-2.0/includes-intuition-intuition-h.md) structure
    [Menu](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the first menu in the menu strip
```
RESULT

    TRUE if there were no problems.  TRUE always, since this routine
    will wait until it is OK to proceed.
BUGS

SEE ALSO

```c
    [ClearMenuStrip()](autodocs-2.0/intuition-library-clearmenustrip.md), [ResetMenuStrip()](autodocs-2.0/intuition-library-resetmenustrip.md)
```

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
- [CloseWindow — intuition.library](../autodocs/intuition.library.md#closewindow)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [ResetMenuStrip — intuition.library](../autodocs/intuition.library.md#resetmenustrip)
- [SetMenuStrip — intuition.library](../autodocs/intuition.library.md#setmenustrip)
