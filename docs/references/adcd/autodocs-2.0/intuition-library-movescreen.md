---
title: intuition.library/MoveScreen
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-movescreen
functions: [MakeScreen, RethinkDisplay]
libraries: [intuition.library]
---

# intuition.library/MoveScreen

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    MoveScreen -- Attempt to move the screen by the increments provided.
SYNOPSIS

```c
    MoveScreen( [Screen](autodocs-2.0/includes-intuition-screens-h.md), DeltaX, DeltaY )
                A0      D0      D1

    VOID MoveScreen( struct [Screen](autodocs-2.0/includes-intuition-screens-h.md) *, WORD, WORD );
```
FUNCTION

```c
    Moves the screen the specified increment, specified in screen
    pixel resolution coordinates.

    New for V36: [Screen](autodocs-2.0/includes-intuition-screens-h.md) movement limits have been greatly relaxed,
    to support screen scrolling.  In particular, negative values
    for screen LeftEdge and TopEdge may now be valid.
```
   If the DeltaX and DeltaY variables you specify would move the screen
   in a way that violates any restrictions, the screen will be moved
   as far as possible.  You may examine the LeftEdge and TopEdge fields

```c
    of the [Screen](autodocs-2.0/includes-intuition-screens-h.md) structure after this function returns to see where
    the screen really ended up.

    In operation, this function determines what the resulting position
    values that are actually to be used, sets these up, and calls
    [MakeScreen()](autodocs-2.0/intuition-library-makescreen.md) and [RethinkDisplay()](autodocs-2.0/intuition-library-rethinkdisplay.md).
```
INPUTS

```c
    [Screen](autodocs-2.0/includes-intuition-screens-h.md) = pointer to a [Screen](autodocs-2.0/includes-intuition-screens-h.md) structure
    DeltaX = amount to move the screen on the x-axis
            Note that DeltaX no longer (V36) need be set to zero
    DeltaY = amount to move the screen on the y-axis
            Note that these coordinates are in the same resolution
            as the screen (such as HIRES or INTERLACE)
```
RESULT

    None
BUGS

SEE ALSO

```c
    [RethinkDisplay()](autodocs-2.0/intuition-library-rethinkdisplay.md)
```

---

## See Also

- [MakeScreen — intuition.library](../autodocs/intuition.library.md#makescreen)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
