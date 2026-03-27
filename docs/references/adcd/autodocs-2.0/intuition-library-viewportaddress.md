---
title: intuition.library/ViewPortAddress
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-viewportaddress
functions: []
libraries: []
---

# intuition.library/ViewPortAddress

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    ViewPortAddress -- Return the address of a window's viewport.
SYNOPSIS

```c
    [ViewPort](autodocs-2.0/includes-graphics-view-h.md) = ViewPortAddress( [Window](autodocs-2.0/includes-intuition-intuition-h.md) )
    D0                          A0

    struct [ViewPort](autodocs-2.0/includes-graphics-view-h.md) *ViewPortAddress( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

    Returns the address of the viewport associated with the specified
    window.  The viewport is actually the viewport of the screen within
    which the window is displayed.  If you want to use any of the graphics,
    text, or animation primitives in your window and that primitive
    requires a pointer to a viewport, you can use this call.

    This pointer is only valid as long as your window's screen remains
    open, which is ensured by keeping your window open.
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to the window for which you want the viewport address
```
RESULT

```c
    Returns the address of the Intuition [ViewPort](autodocs-2.0/includes-graphics-view-h.md) structure for
    your window's screen .
```
BUGS

    This routine is unnecessary: you can just use the expression
    &Window->WScreen->ViewPort.
SEE ALSO

    graphics.library
