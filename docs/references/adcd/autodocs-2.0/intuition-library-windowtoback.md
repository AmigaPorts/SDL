---
title: intuition.library/WindowToBack
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-windowtoback
functions: [MoveWindow, MoveWindowInFrontOf, SizeWindow, WindowToFront]
libraries: [intuition.library]
---

# intuition.library/WindowToBack

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    WindowToBack -- Ask Intuition to send a window behind others.
SYNOPSIS

```c
    WindowToBack( [Window](autodocs-2.0/includes-intuition-intuition-h.md) )
                  A0

    VOID WindowToBack( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    This routine sends a request to Intuition asking to send the window
    in back of all other windows in the screen.

    Note that the window will not be depth-arranged immediately, but rather
    will be arranged the next time Intuition receives an input event,
    which happens currently at a minimum rate of ten times per second,
    and a maximum of sixty times a second.

    [Remember](autodocs-2.0/includes-intuition-intuition-h.md) that WFLG_BACKDROP windows cannot be depth-arranged.
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the structure of the window to be sent to the back
```
RESULT

    None
BUGS

SEE ALSO

```c
    [MoveWindow()](autodocs-2.0/intuition-library-movewindow.md), [SizeWindow()](autodocs-2.0/intuition-library-sizewindow.md), [WindowToFront()](autodocs-2.0/intuition-library-windowtofront.md), [MoveWindowInFrontOf()](autodocs-2.0/intuition-library-movewindowinfrontof.md)
```

---

## See Also

- [MoveWindow — intuition.library](../autodocs/intuition.library.md#movewindow)
- [MoveWindowInFrontOf — intuition.library](../autodocs/intuition.library.md#movewindowinfrontof)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
- [WindowToFront — intuition.library](../autodocs/intuition.library.md#windowtofront)
