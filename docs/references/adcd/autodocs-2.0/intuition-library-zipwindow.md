---
title: intuition.library/ZipWindow
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-zipwindow
functions: [ChangeWindowBox, MoveWindow, OpenWindow, SizeWindow]
libraries: [intuition.library]
---

# intuition.library/ZipWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ZipWindow -- Change window to "alternate" position and
                 dimensions. (V36)
```
SYNOPSIS

```c
    ZipWindow( [Window](autodocs-2.0/includes-intuition-intuition-h.md) )
               A0

    VOID ZipWindow( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

```c
    Changes the position and dimension of a window to the values
    at the last occasion of ZipWindow being called (or invoked
    via the "zoom" gadget).

    Typically this is used to snap between a normal, large, working
    dimension of the window to a smaller, more innocuous position
    and dimension.

    Like [MoveWindow()](autodocs-2.0/intuition-library-movewindow.md), [SizeWindow()](autodocs-2.0/intuition-library-sizewindow.md), and [ChangeWindowBox()](autodocs-2.0/intuition-library-changewindowbox.md), the action of
    this function is deferred to the Intuition input handler.

    More tuning needs to be done to establish initial values for
    the first invocation of this function for a window.  You can
    provide initial values using the [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md) tag item
    WA_Zoom.

    It could also use a new name, but "ZoomWindow" is misleading,
    since "Zoom" normally implies "scale."

    The zoom gadget will appear (in the place of the old "toback"
    gadget) when you open your window if you either specify a
    sizing gadget or use WA_Zoom.

    You can detect that this function has taken effect by receiving
    an IDCMP_CHANGEWINDOW IDCMP message.
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) -- window to be changed.
```
RESULT

    None
BUGS

```c
    [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md) assumes that the proper default "other" dimensions
    are "full size."
```
SEE ALSO

```c
    [ChangeWindowBox()](autodocs-2.0/intuition-library-changewindowbox.md), [MoveWindow()](autodocs-2.0/intuition-library-movewindow.md), [SizeWindow()](autodocs-2.0/intuition-library-sizewindow.md)
```

---

## See Also

- [ChangeWindowBox — intuition.library](../autodocs/intuition.library.md#changewindowbox)
- [MoveWindow — intuition.library](../autodocs/intuition.library.md#movewindow)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
