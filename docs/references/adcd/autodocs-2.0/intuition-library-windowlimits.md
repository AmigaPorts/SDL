---
title: intuition.library/WindowLimits
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-windowlimits
functions: [GetScreenData, OpenWindow]
libraries: [intuition.library]
---

# intuition.library/WindowLimits

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    WindowLimits -- Set the minimum and maximum limits of a window.
SYNOPSIS

```c
    Success = WindowLimits( [Window](autodocs-2.0/includes-intuition-intuition-h.md), MinWidth, MinHeight, MaxWidth,
    D0                      A0      D0        D1         D2
                            MaxHeight )
                            D3

    BOOL WindowLimits( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *, WORD, WORD, UWORD, UWORD );
```
FUNCTION

```c
    Sets the minimum and maximum limits of the window's size.  Until this
    routine is called, the window's size limits are equal to the initial
    values established in the [OpenWindow()](autodocs-2.0/intuition-library-openwindow.md) function.

    After a call to this routine, the [Window](autodocs-2.0/includes-intuition-intuition-h.md) will be able to be sized
    to any dimensions within the specified limits.

    If you don't want to change any one of the dimensions, set the limit
    argument for that dimension to zero.  If any of the limit arguments
    is equal to zero, that argument is ignored and the initial setting
    of that parameter remains undisturbed.

    If any of the arguments is out of range (minimums greater than the
    current size, maximums less than the current size), that limit
    will be ignored, though the others will still take effect if they
    are in range.  If any are out of range, the return value from this
    procedure will be FALSE.  If all arguments are valid, the return
    value will be TRUE.

    If you want your window to be able to become "as large as possible"
    you may put -1 (i.e. ~0) in either or both Max arguments.  But
    please note: screen sizes may vary for several reasons, and you
    must be able to handle any possible size of window you might end
    up with if you use this method.  Note that you can use the function
    [GetScreenData()](autodocs-2.0/intuition-library-getscreendata.md) to find out how big the screen your window appears in
    is.  That function is particularly useful if your window is in
    the Workbench screen.  You may also refer to the WScreen field
    in your window structure, providing that your window remains open,
    which will ensure that the screen remains open, and thus the
    pointer remains valid.

    If the user is currently sizing this window, the new limits will
    not take effect until after the sizing is completed.
```
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to a [Window](autodocs-2.0/includes-intuition-intuition-h.md) structure
    MinWidth, MinHeight, MaxWidth, MaxHeight = the new limits for the size
        of this window.  If any of these is set to zero, it will
        be ignored and that setting will be unchanged.
```
RESULT

```c
    Returns TRUE if everything was in order.  If any of the parameters was
    out of range (minimums greater than current size, maximums less than
    current size), FALSE is returned and the errant limit request is
    not fulfilled (though the valid ones will be).
```
BUGS

SEE ALSO

```c
    [GetScreenData()](autodocs-2.0/intuition-library-getscreendata.md)
```

---

## See Also

- [GetScreenData — intuition.library](../autodocs/intuition.library.md#getscreendata)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
