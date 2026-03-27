---
title: B / gadgetclass / New Methods: GM_RENDER
manual: libraries
chapter: libraries
section: b-gadgetclass-new-methods-gm-render
functions: []
libraries: []
---

# B / gadgetclass / New Methods: GM_RENDER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method tells a gadget to render itself.  The return value for this
method is not explicitly defined.

GM_RENDER uses a custom message structure (defined in
<intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>):


```c
    struct gpRender
    {
        ULONG             MethodID;   /* GM_RENDER */
        struct GadgetInfo *gpr_GInfo;
        struct RastPort   *gpr_RPort; /* all ready for use */
        LONG              gpr_Redraw; /* might be a "highlight pass" */
    };
```
The GM_RENDER message contains a pointer to the Gadget's [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) which it
can use for rendering.  The Gadget renders itself according to how much
imagery it needs to replace.  The gpr_Redraw field contains one of three
values:

GREDRAW_REDRAW  Redraw the entire gadget.

GREDRAW_UPDATE  The user has manipulated the gadget changing the

```c
                imagery.  Update only that part of the gadget's
                imagery that is effected by the user manipulating the
                gadget (for example, the knob and scrolling field of
                the prop gadget).
```
GREDRAW_TOGGLE  If this gadget supports it, toggle to or from the

                highlighting imagery.
