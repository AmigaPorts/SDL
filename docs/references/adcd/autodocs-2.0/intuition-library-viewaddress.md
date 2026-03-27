---
title: intuition.library/ViewAddress
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-viewaddress
functions: [ViewAddress]
libraries: [intuition.library]
---

# intuition.library/ViewAddress

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    ViewAddress -- Return the address of the Intuition [View](autodocs-2.0/includes-graphics-view-h.md) structure.
```
SYNOPSIS

```c
    view = ViewAddress()
    D0

    struct [View](autodocs-2.0/includes-graphics-view-h.md) *ViewAddress( VOID );
```
FUNCTION

```c
    Returns the address of the Intuition [View](autodocs-2.0/includes-graphics-view-h.md) structure.  If you
    want to use any of the graphics, text, or animation primitives
    in your window and that primitive requires a pointer to a view,
    this routine will return the address of the view for you.
```
INPUTS

    None
RESULT

```c
    Returns the address of the Intuition [View](autodocs-2.0/includes-graphics-view-h.md) structure
```
BUGS

SEE ALSO

    graphics.library

---

## See Also

- [ViewAddress — intuition.library](../autodocs/intuition.library.md#viewaddress)
