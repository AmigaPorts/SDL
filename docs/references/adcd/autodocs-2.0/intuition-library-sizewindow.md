---
title: intuition.library/SizeWindow
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-sizewindow
functions: [ChangeWindowBox, MoveWindow, WindowToBack, WindowToFront]
libraries: [intuition.library]
---

# intuition.library/SizeWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SizeWindow -- Ask Intuition to size a window.
SYNOPSIS

```c
    SizeWindow( [Window](autodocs-2.0/includes-intuition-intuition-h.md), DeltaX, DeltaY )
                A0      D0      D1

    VOID SizeWindow( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, WORD, WORD );
```
FUNCTION

```c
    This routine sends a request to Intuition asking to size the window
    the specified amounts.  The delta arguments describe how much to
    size the window along the respective axes.

    Note that the window will not be sized immediately, but rather
    will be sized the next time Intuition receives an input event,
    which happens currently at a minimum rate of ten times per second,
    and a maximum of sixty times a second.  You can discover when
    you window has finally been sized by setting the IDCMP_NEWSIZE flag
    of the IDCMP of your window.  See the "Input and Output Methods"
    chapter of The Intuition Reference Manual for description of the IDCMP.

    New for V36: Intuition now will do validity checking on the final
    dimensions.  To change to new absolute dimensions, or to move and
    size a window in one step, use [ChangeWindowBox()](autodocs-2.0/intuition-library-changewindowbox.md).

    However, limit checking against window MinWidth, MinHeight,
    MaxWidth, and MaxHeight was not done prior to V36, and
    these fields are still ignored (as documented) if you have
    no sizing gadget (WFLG_SIZEGADGET is not set).  The *are*
    respected now (V36) if WFLG_SIZEGADGET is set.

    New for V36: you can determine when the change in size has
    taken effect by receiving the IDCMP_CHANGEWINDOW IDCMP message.
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the structure of the window to be sized
    DeltaX = signed value describing how much to size the window
     on the x-axis
    DeltaY = signed value describing how much to size the window
     on the y-axis
```
RESULT

    None
BUGS

SEE ALSO

```c
    [ChangeWindowBox()](autodocs-2.0/intuition-library-changewindowbox.md), [MoveWindow()](autodocs-2.0/intuition-library-movewindow.md), [WindowToFront()](autodocs-2.0/intuition-library-windowtofront.md), [WindowToBack()](autodocs-2.0/intuition-library-windowtoback.md)
```

---

## See Also

- [ChangeWindowBox — intuition.library](../autodocs/intuition.library.md#changewindowbox)
- [MoveWindow — intuition.library](../autodocs/intuition.library.md#movewindow)
- [WindowToBack — intuition.library](../autodocs/intuition.library.md#windowtoback)
- [WindowToFront — intuition.library](../autodocs/intuition.library.md#windowtofront)
