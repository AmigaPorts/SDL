---
title: 12 / Boopsi Gadgets / The Boopsi Gadget Methods
manual: libraries
chapter: libraries
section: 12-boopsi-gadgets-the-boopsi-gadget-methods
functions: [ObtainGIRPort, ReleaseGIRPort]
libraries: [intuition.library]
---

# 12 / Boopsi Gadgets / The Boopsi Gadget Methods

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Intuition drives a Boopsi gadget by sending it Boopsi messages. Intuition
uses a series of five Boopsi methods:

[GM_RENDER](libraries/12-the-boopsi-gadget-methods-gm-render.md)       This method tells the gadget to render itself.

[GM_HITTEST](libraries/12-the-boopsi-gadget-methods-gm-hittest.md)      This method asks a gadget whether it has been "hit" by a

                mouse click.
[GM_GOACTIVE](libraries/12-the-boopsi-gadget-methods-gm-goactive-gm-handleinput.md)     This method asks a gadget if it wants to be the active

                gadget.
[GM_HANDLEINPUT](libraries/12-the-boopsi-gadget-methods-gm-goactive-gm-handleinput.md)  This method passes a gadget an input event.

[GM_GOINACTIVE](libraries/12-the-boopsi-gadget-methods-gm-goinactive.md)   This method tells a gadget that it is no longer active.

The formats of each of these Boopsi messages differ, but they all have two
things in common.  Like all Boopsi messages, each starts with their
respective method ID.  For each of these methods, the method ID field is
followed by a pointer to a GadgetInfo structure (defined in
<intuition/[cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md)>).  The GadgetInfo structure contains information
about the display on which the gadget needs to render itself:


struct GadgetInfo {
```c
    struct Screen          *gi_Screen;
    struct Window          *gi_Window;     /* null for screen gadgets */
    struct Requester       *gi_Requester;  /* null if not GTYP_REQGADGET */

    /* rendering information: don't use these without cloning/locking.
     * Official way is to call ObtainGIRPort()
     */
    struct RastPort        *gi_RastPort;
    struct Layer           *gi_Layer;

    /* copy of dimensions of screen/window/g00/req(/group)
     * that gadget resides in.  Left/Top of this box is
     * offset from window mouse coordinates to gadget coordinates
     *  screen gadgets:                 0,0 (from screen coords)
     *  window gadgets (no g00):        0,0
     *  GTYP_GZZGADGETs (borderlayer):  0,0
     *  GZZ innerlayer gadget:          borderleft, bordertop
     *  Requester gadgets:              reqleft, reqtop
     */
    struct IBox            gi_Domain;

    /* these are the pens for the window or screen */
    struct {
        UBYTE   DetailPen;
        UBYTE   BlockPen;
    }                      gi_Pens;

    /* the Detail and Block pens in gi_DrInfo->dri_Pens[] are
     * for the screen.  Use the above for window-sensitive colors.
     */
    struct DrawInfo        *gi_DrInfo;

    /* reserved space: this structure is extensible
     * anyway, but using these saves some recompilation
     */
    ULONG                  gi_Reserved[6];
```
};


All the fields in this structure are read only.

Although this structure contains a pointer to the gadget's [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)
structure, applications should not use it for rendering.  Instead, use the
intuition.library function [ObtainGIRPort()](autodocs-2.0/intuition-library-obtaingirport.md) to obtain a copy of the
GadgetInfo's RastPort.  When the gadget is finished with this RastPort, it
should call [ReleaseGIRPort()](autodocs-2.0/intuition-library-releasegirport.md) to relinquish the RastPort.

 [GM_RENDER](libraries/12-the-boopsi-gadget-methods-gm-render.md)     [GM_GOACTIVE/GM_HANDLEINPUT](libraries/12-the-boopsi-gadget-methods-gm-goactive-gm-handleinput.md) 
 [GM_HITTEST](libraries/12-the-boopsi-gadget-methods-gm-hittest.md)    [GM_GOINACTIVE](libraries/12-the-boopsi-gadget-methods-gm-goinactive.md) 

---

## See Also

- [ObtainGIRPort — intuition.library](../autodocs/intuition.library.md#obtaingirport)
- [ReleaseGIRPort — intuition.library](../autodocs/intuition.library.md#releasegirport)
