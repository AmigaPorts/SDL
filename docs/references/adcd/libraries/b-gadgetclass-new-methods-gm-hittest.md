---
title: B / gadgetclass / New Methods: GM_HITTEST
manual: libraries
chapter: libraries
section: b-gadgetclass-new-methods-gm-hittest
functions: []
libraries: []
---

# B / gadgetclass / New Methods: GM_HITTEST

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method asks a gadget if a point is within its bounds. Usually the
point corresponds to a mouse click.  Intuition sends a gadget this message
when the user clicks inside the rectangular bounds found in the object's
[Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure (using its [TopEdge](libraries/5-intuition-gadgets-gadget-structure.md), [LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md), [Width](libraries/5-intuition-gadgets-gadget-structure.md), and [Height](libraries/5-intuition-gadgets-gadget-structure.md) fields).
This method returns GMR_GADGETHIT if a point is within the gadget,
otherwise it returns zero.  Because the gadget decides if it was hit, the
gadget can be almost any shape or pattern.  Boopsi gadgets that default to
using the bounds of their Gadget structure should always return
GMR_GADGETHIT.

GM_HITTEST uses a custom message structure (defined in
<intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>):


```c
    struct gpHitTest
    {
        ULONG             MethodID;     /* GM_HITTEST   */
        struct GadgetInfo *gpht_GInfo;
        struct
        {
            WORD X;                     /* Is this point inside */
            WORD Y;                     /* of the gadget?       */
        } gpht_Mouse;
    };
```
The gpht_Mouse.X and gpht_Mouse.Y fields make up the X and Y coordinates
of the hit point.  These coordinates are relative to the upper-left corner
of the gadget ([Gadget.LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md), [Gadget.TopEdge](libraries/5-intuition-gadgets-gadget-structure.md)).

