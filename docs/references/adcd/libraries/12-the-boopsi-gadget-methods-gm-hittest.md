---
title: 12 / / The Boopsi Gadget Methods / GM_HITTEST
manual: libraries
chapter: libraries
section: 12-the-boopsi-gadget-methods-gm-hittest
functions: []
libraries: []
---

# 12 / / The Boopsi Gadget Methods / GM_HITTEST

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When Intuition gets a left mouse button click in a window, one of the
things it does is check through the window's list of gadgets to see if
that click was inside the bounds of a gadget's [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure (using the
[LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md), [TopEdge](libraries/5-intuition-gadgets-gadget-structure.md), [Width](libraries/5-intuition-gadgets-gadget-structure.md), and [Height](libraries/5-intuition-gadgets-gadget-structure.md) fields).  If it was (and that gadget
is a Boopsi gadget), Intuition sends that gadget a GM_HITTEST message
(defined in <intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>):


```c
    struct gpHitTest
    {
        ULONG             MethodID;     /* GM_HITTEST   */
        struct GadgetInfo *gpht_GInfo;
        struct
        {
            WORD X;     /* Is this point inside of the gadget? */
            WORD Y;
        } gpht_Mouse;
    };
```
This message contains the coordinates of the mouse click.  These
coordinates are relative to the upper-left of the gadget ([LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md),
[TopEdge](libraries/5-intuition-gadgets-gadget-structure.md)).

Because Intuition can only tell if the user clicked inside gadget's
"bounding box", Intuition only knows that the click was close to the
gadget.  Intuition uses the GM_HITTEST to ask the gadget if the click was
really inside the gadget.  The gadget returns GMR_GADGETHIT (defined in
<intuition/[gadgetclass](autodocs-2.0/includes-intuition-gadgetclass-h.md)>) to tell Intuition that the user hit it,
otherwise it returns zero.  This method allows a gadget to be any shape or
pattern, rather than just rectangular.

