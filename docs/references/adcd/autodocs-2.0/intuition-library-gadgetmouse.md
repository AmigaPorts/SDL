---
title: intuition.library/GadgetMouse
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-gadgetmouse
functions: []
libraries: []
---

# intuition.library/GadgetMouse

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    GadgetMouse -- Calculate gadget-relative mouse position. (V36)
```
SYNOPSIS

```c
    GadgetMouse( [Gadget](autodocs-2.0/includes-intuition-intuition-h.md), GInfo, MousePoint )
                 A0      A1     A2

    VOID GadgetMouse( struct [GadgetInfo](autodocs-2.0/includes-intuition-cghooks-h.md) *, WORD * );
```
FUNCTION

```c
    Determines the current location of the mouse pointer relative
    to the upper-left corner of a custom gadget.  Typically used
    only in the GM_HANDLEINPUT and GM_GOACTIVE custom gadget hook
    routines.

    NEWS FLASH!!: These two hook routines are now passed the mouse
    coordinates, so this function has no known usefulness.

    We recommend that you don't call it.

    Note that this function calculates the mouse position taking
    "gadget relativity" (GFLG_RELRIGHT, GFLG_RELBOTTOM) into
    consideration.  If your custom gadget intends to ignore these
    properties, then you should either enjoin or inhibit your users
    from setting those bits, since Intuition won't ask if you respect
    them.
```
INPUTS

```c
    GInfo = A pointer to a [GadgetInfo](autodocs-2.0/includes-intuition-cghooks-h.md) structure as passed to the
            custom gadget hook routine.
    MousePoint = address of two WORDS, or a pointer to a structure of
            type Point.
```
RESULT

    Returns nothing.  Fills in the two words pointed to by
    MousePoint with the gadget-relative mouse position.
BUGS

    Useless, since equivalent information is now passed to every
    function that might have a use for this.
SEE ALSO

