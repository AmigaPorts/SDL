---
title: intuition.library/MoveWindow
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-movewindow
functions: [ChangeWindowBox, SizeWindow, WindowToBack, WindowToFront]
libraries: [intuition.library]
---

# intuition.library/MoveWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    MoveWindow -- Ask Intuition to move a window.
SYNOPSIS

```c
    MoveWindow( [Window](autodocs-2.0/includes-intuition-intuition-h.md), DeltaX, DeltaY )
                A0      D0      D1

    VOID MoveWindow( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, WORD, WORD );
```
FUNCTION

```c
    This routine sends a request to Intuition asking to move the window
    the specified distance.  The delta arguments describe how far to
    move the window along the respective axes.

    Note that the window will not be moved immediately, but rather
    will be moved the next time Intuition receives an input event,
    which happens currently at a minimum rate of ten times per second,
    and a maximum of sixty times a second.

    Interactions with other arbitration of Intuition data structures
    may defer this operation longer.  For V36, you can use the new
    IDCMP class IDCMP_CHANGEWINDOW to detect when this operation has
    completed.

    New for V36: Intuition now will do validity checking on the final
    position.  To send absolute movements, or to move and size a
    window in one step, use [ChangeWindowBox()](autodocs-2.0/intuition-library-changewindowbox.md).
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the structure of the [Window](autodocs-2.0/includes-intuition-intuition-h.md) to be moved
    DeltaX = how far to move the [Window](autodocs-2.0/includes-intuition-intuition-h.md) on the x-axis
    DeltaY = how far to move the [Window](autodocs-2.0/includes-intuition-intuition-h.md) on the y-axis
```
RESULT

    None
BUGS

SEE ALSO

```c
    [ChangeWindowBox()](autodocs-2.0/intuition-library-changewindowbox.md), [SizeWindow()](autodocs-2.0/intuition-library-sizewindow.md), [WindowToFront()](autodocs-2.0/intuition-library-windowtofront.md), [WindowToBack()](autodocs-2.0/intuition-library-windowtoback.md)
```

---

## See Also

- [ChangeWindowBox — intuition.library](../autodocs/intuition.library.md#changewindowbox)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
- [WindowToBack — intuition.library](../autodocs/intuition.library.md#windowtoback)
- [WindowToFront — intuition.library](../autodocs/intuition.library.md#windowtofront)
