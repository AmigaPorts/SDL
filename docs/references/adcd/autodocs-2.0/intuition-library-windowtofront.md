---
title: intuition.library/WindowToFront
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-windowtofront
functions: [MoveWindow, MoveWindowInFrontOf, SizeWindow, WindowToBack]
libraries: [intuition.library]
---

# intuition.library/WindowToFront

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    WindowToFront -- Ask Intuition to bring a window to the front.
SYNOPSIS

```c
    WindowToFront( [Window](autodocs-2.0/includes-intuition-intuition-h.md) )
                   A0

    VOID WindowToFront( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    This routine sends a request to Intuition asking to bring the window
    in front of all other windows in the screen.

    Note that the window will not be depth-arranged immediately, but rather
    will be arranged the next time Intuition receives an input event,
    which happens currently at a minimum rate of ten times per second,
    and a maximum of sixty times a second.

    [Remember](autodocs-2.0/includes-intuition-intuition-h.md) that WFLG_BACKDROP windows cannot be depth-arranged.
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the structure of the window to be brought to front
```
RESULT

    None
BUGS

SEE ALSO

```c
    [MoveWindow()](autodocs-2.0/intuition-library-movewindow.md), [SizeWindow()](autodocs-2.0/intuition-library-sizewindow.md), [WindowToBack()](autodocs-2.0/intuition-library-windowtoback.md), [MoveWindowInFrontOf()](autodocs-2.0/intuition-library-movewindowinfrontof.md)
```

---

## See Also

- [MoveWindow — intuition.library](../autodocs/intuition.library.md#movewindow)
- [MoveWindowInFrontOf — intuition.library](../autodocs/intuition.library.md#movewindowinfrontof)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
- [WindowToBack — intuition.library](../autodocs/intuition.library.md#windowtoback)
