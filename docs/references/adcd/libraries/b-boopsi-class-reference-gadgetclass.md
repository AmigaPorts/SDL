---
title: B Boopsi Class Reference / gadgetclass
manual: libraries
chapter: libraries
section: b-boopsi-class-reference-gadgetclass
functions: [ObtainGIRPort]
libraries: [intuition.library]
---

# B Boopsi Class Reference / gadgetclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  gadgetclass
Superclass:             [rootclass](libraries/b-boopsi-class-reference-rootclass.md)
Include File:           <intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>

This is a base class for Intuition compatible gadget objects.  The
dispatcher for this class takes care of creating an Intuition [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)
structure as part of its local instance data.  All of the standard Boopsi
gadget classes build on this class.  Normally there are no direct
instances of this class, only instances of subclasses of gadgetclass.

The behavior of a Boopsi gadget depends on how it handles the five Boopsi
gadget methods: GM_HITTEST, GM_RENDER, GM_GOACTIVE, GM_HANDLEINPUT, and
GM_GOINACTIVE.  Intuition controls a Boopsi gadget by sending it these
types of messages.  The structures that these methods use for their
messages begin with the method's ID followed by a pointer to a [GadgetInfo](libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md)
structure (defined in <intuition/[cghooks.h](autodocs-2.0/includes-intuition-cghooks-h.md)>).  The GadgetInfo structure is
a read-only structure that contains information about the gadget's
rendering environment.  The gadget uses this to find things like its
window, screen, or pen array.  Although this structure does contain a
pointer to a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) for the gadget, the gadget must not use this
RastPort for rendering.  The gadget can obtain a RastPort for rendering by
calling the Intuition function [ObtainGIRPort()](autodocs-2.0/intuition-library-obtaingirport.md) using the GadgetInfo
structure.  See the intuition.library Autodocs for more details on this
function.

These methods are not defined directly by gadgetclass.  It is up to
subclasses of gadgetclass to implement them.

Like all Boopsi methods, these methods run on the context of the task that
called the method.  Normally, Intuition is the only entity that calls
these methods, so these normally operate in the input.device's task.
Because a gadget may have to process a large number of input events, poor
implementations of gadget methods (especially the GM_HANDLEINPUT method)
can degrade system performance.

New Methods:
------------
 [GM_HITTEST](libraries/b-gadgetclass-new-methods-gm-hittest.md)    [GM_GOACTIVE](libraries/b-gadgetclass-new-methods-gm-goactive.md)       [GM_GOINACTIVE](libraries/b-gadgetclass-new-methods-gm-goinactive.md) 
 [GM_RENDER](libraries/b-gadgetclass-new-methods-gm-render.md)     [GM_HANDLEINPUT](libraries/b-gadgetclass-new-methods-gm-handleinput.md) 

Changed Methods:
----------------
 [OM_NEW](libraries/b-gadgetclass-changed-methods-om-new.md)    [OM_NOTIFY](libraries/b-gadgetclass-changed-methods-om-notify.md) 

Attributes:
-----------
 [GA_Previous (I)](libraries/b-gadgetclass-attributes-ga-previous-i.md) 
 [ICA_TARGET (IS)](libraries/b-gadgetclass-attributes-ica-target-is.md) 
 [ICA_MAP (IS)](libraries/b-gadgetclass-attributes-ica-map-is.md) 
 [GA_Left, GA_Top, GA_Width, GA_Height (IS)](libraries/b-gadgetclass-attributes-ga-left-ga-top-ga-width-ga-height.md) 
 [GA_RelRight, GA_RelBottom, GA_RelWidth, GA_RelHeight (IS)](libraries/b-ga-relright-ga-relbottom-ga-relwidth-ga-relheight-is.md) 

The remaining attributes defined by gadgetclass are used to set the fields
in the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure of the Boopsi gadget.  Some Boopsi gadgets do not
pay attention to many of the fields in its Gadget structure, so most
applications will not have to worry about the majority of these
attributes.  Some gadget classes assign special meanings to these
attributes.  See the documentation of the specific gadget classes for more
details.

 [GA_IntuiText, GA_Text, GA_LabelImage (IS)](libraries/b-gadgetclass-attributes-ga-intuitext-ga-text-ga-labelimage.md) 
 [GA_Image (IS)](libraries/b-gadgetclass-attributes-ga-image-is.md) 
 [GA_Border, GA_SelectRender, GA_ID, GA_UserData, GA_SpecialInfo (IS)](libraries/b-gadgetclass-attributes-ga-border-ga-specialinfo-is.md) 
 [GA_GZZGadget, GA_SysGadget (IS)](libraries/b-gadgetclass-attributes-ga-gzzgadget-ga-sysgadget-is.md) 
 [GA_Disabled, GA_Selected (IS)](libraries/b-gadgetclass-attributes-ga-disabled-ga-selected-is.md) 
 [GA_EndGadget, GA_Immediate, GA_RelVerify, GA_FollowMouse, (IS)](libraries/b-gadgetclass-attributes-ga-endgadget-ga-tabcycle-is.md)     
 [GA_RightBorder, GA_LeftBorder, GA_TopBorder, GA_BottomBorder, (IS)](libraries/b-gadgetclass-attributes-ga-endgadget-ga-tabcycle-is.md) 
 [GA_ToggleSelect, GA_TabCycle (IS)](libraries/b-gadgetclass-attributes-ga-endgadget-ga-tabcycle-is.md)                                  
 [GA_Highlight (IS)](libraries/b-gadgetclass-attributes-ga-highlight-is.md) 
 [GA_SysGType (IS)](libraries/b-gadgetclass-attributes-ga-sysgtype-is.md) 

---

## See Also

- [ObtainGIRPort — intuition.library](../autodocs/intuition.library.md#obtaingirport)
