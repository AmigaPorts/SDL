---
title: intuition.library/RefreshWindowFrame
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-refreshwindowframe
functions: []
libraries: []
---

# intuition.library/RefreshWindowFrame

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RefreshWindowFrame -- Ask Intuition to redraw your window border.
SYNOPSIS

```c
    RefreshWindowFrame( [Window](autodocs-2.0/includes-intuition-intuition-h.md) )
                        A0

    VOID RefreshWindowFrame( struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) * );
```
FUNCTION

    Refreshes the border of a window, including title region and all
    of the window's gadgets.

    You may use this call if you wish to update the display of your
    borders.  The expected use of this is to correct unavoidable
    corruption.
INPUTS

```c
    [Window](autodocs-2.0/includes-intuition-intuition-h.md) = a pointer to a [Window](autodocs-2.0/includes-intuition-intuition-h.md) structure
```
RESULT

    None
BUGS

SEE ALSO

