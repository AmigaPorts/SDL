---
title: intuition.library/ChangeWindowBox
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-changewindowbox
functions: [ChangeWindowBox, MoveSizeLayer, MoveWindow, SizeWindow, ZipWindow]
libraries: [intuition.library, layers.library]
---

# intuition.library/ChangeWindowBox

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ChangeWindowBox -- Change window position and dimensions. (V36)
```
SYNOPSIS

```c
    ChangeWindowBox( [Window](autodocs-2.0/includes-intuition-intuition-h.md), Left, Top, Width, Height )
                     A0      D0    D1   D2     D3

    VOID ChangeWindowBox( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, WORD, WORD, WORD, WORD );
```
FUNCTION

```c
    Makes simultaneous changes in window position and dimensions,
    in absolute (not relative) coordinates.

    Like [MoveWindow()](autodocs-2.0/intuition-library-movewindow.md) and [SizeWindow()](autodocs-2.0/intuition-library-sizewindow.md), the effect of this function
    is deferred until the next input comes along.  Unlike these
    functions, ChangeWindowBox() specifies absolute window position
    and dimensions, not relative.  This makes for more reliable
    results considering that the action is deferred, so this
    function is typically preferable to [MoveWindow()](autodocs-2.0/intuition-library-movewindow.md) and [SizeWindow()](autodocs-2.0/intuition-library-sizewindow.md)
    paired.

    You can detect that this operation has completed by receiving
    the IDCMP_CHANGEWINDOW IDCMP message

    The dimensions are limited to legal range, but you should still
    take care to specify sensible inputs based on the window's dimension
    limits and the size of its screen.

    This function limits the position and dimensions to legal
    values.
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = the window to change position/dimension
    Left, Top, Width, Height = new position and dimensions
```
RESULT

    Position and dimension are changed to your specification,
    or as close as possible.
    Returns nothing.
BUGS

SEE ALSO

```c
    [MoveWindow()](autodocs-2.0/intuition-library-movewindow.md), [SizeWindow()](autodocs-2.0/intuition-library-sizewindow.md), [ZipWindow()](autodocs-2.0/intuition-library-zipwindow.md),
    [layers.library/MoveSizeLayer()](autodocs-2.0/layers-library-movesizelayer.md)
```

---

## See Also

- [ChangeWindowBox — intuition.library](../autodocs/intuition.library.md#changewindowbox)
- [MoveSizeLayer — layers.library](../autodocs/layers.library.md#movesizelayer)
- [MoveWindow — intuition.library](../autodocs/intuition.library.md#movewindow)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
- [ZipWindow — intuition.library](../autodocs/intuition.library.md#zipwindow)
