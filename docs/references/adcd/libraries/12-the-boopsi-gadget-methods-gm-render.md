---
title: 12 / / The Boopsi Gadget Methods / GM_RENDER
manual: libraries
chapter: libraries
section: 12-the-boopsi-gadget-methods-gm-render
functions: [ObtainGIRPort, OpenWindow]
libraries: [intuition.library]
---

# 12 / / The Boopsi Gadget Methods / GM_RENDER

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Every time Intuition feels it is necessary to redraw a Boopsi gadget, it
sends a gadget a GM_RENDER message.  The GM_RENDER message (defined in
<intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>) tells a gadget to render itself:


```c
    struct gpRender
    {
        ULONG             MethodID;   /* GM_RENDER */
        struct GadgetInfo *gpr_GInfo;
        struct RastPort   *gpr_RPort; /* all ready for use */
        LONG              gpr_Redraw; /* might be a "highlight pass" */
    };
```
Some events that cause Intuition to send a GM_RENDER are: an application
passed the gadget to [OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md), the user moved or resized a gadget's
window, or an application explicitly asked Intuition to refresh some
gadgets.

The GM_RENDER message contains a pointer to the gadget's [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) so the
GM_RENDER method does not have to extract it from the gpr_GInfo [GadgetInfo](libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md)
structure using [ObtainGIRPort()](autodocs-2.0/intuition-library-obtaingirport.md)).  The gadget renders itself according to
how much imagery it needs to replace.  The gpr_Redraw field contains one
of three values:

GREDRAW_REDRAW  Redraw the entire gadget.

GREDRAW_UPDATE  The user has manipulated the gadget, causing a change

```c
                to its imagery. Update only that part of the gadget's
                imagery that is effected by the user manipulating the
                gadget (for example, the knob and scrolling field of
                the prop gadget).
```
GREDRAW_TOGGLE  If this gadget supports it, toggle to or from the

                highlighting imagery.
Intuition is not the only entity that calls this method.  The gadget's
other methods may call this method to render the gadget when it goes
through state changes.  For example, as a prop gadget is following the
mouse from the gadget's [GM_HANDLEINPUT](libraries/12-the-boopsi-gadget-methods-gm-goactive-gm-handleinput.md) method, the gadget could send
itself GM_RENDER messages, telling itself to update its imagery according
to where the mouse has moved.

---

## See Also

- [ObtainGIRPort — intuition.library](../autodocs/intuition.library.md#obtaingirport)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
