---
title: gadgetclass
manual: amiga-mail
chapter: amiga-mail
section: gadgetclass
functions: [AddGList]
libraries: [intuition.library]
---

# gadgetclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  gadgetclass
Superclass:             rootclass
Description:            Base class for Intuition compatible gadget classes
Include File:           <intuition/gadgetclass.h>


New Methods:
------------

Intuition uses the following methods to control a gadget.  Only custom
gadget class implentors will be interested in these.

GM_HITTEST
GM_RENDER
GM_GOACTIVE
GM_HANDLEINPUT
GM_GOINACTIVE


Changed Methods:
----------------

OM_NEW - Initializes transparent Gadget structure.  LeftEdge and TopEdge
are set to 0, Width and Height are arbitrary constants which you should
override.  Sets GadgetType to CUSTOMGADGET, and installs a pointer to
the gadgetclass data structure in the MutualExclude field.  These
objects are also valid "custom gadgets."

Links self into a NextGadget linked list if GA_Previous is passed to
OM_NEW.


OM_UPDATE and OM_SET are used simply to change the attributes.  This
gadgetclass does not implement any concrete gadgets.  This is left to
the subclasses.


OM_NOTIFY - This class will issue an OM_UPDATE message to ICA_Target
through ICA_Map.  Subclasses of gadgetclass are advised to let the
superclass handle this method.


Attributes:
-----------

GA_Left                         (IS)
GA_Top                          (IS)
GA_Width                        (IS)
GA_Height                       (IS)

These correspond to position and dimension fields in the Intuition
Gadget structure.  Setting these clears the "gadget relative" flags
(below).


GA_RelRight                     (IS)
GA_RelBottom                    (IS)
GA_RelWidth                     (IS)
GA_RelHeight                    (IS)

These are alternative position/dimension attributes.  Setting these
stores the corresponding data in the Left/Top/Width/Height Gadget
fields, respectively, and sets the corresponding "relative" flag
(GRELRIGHT, GRELBOTTOM, and so on).


GA_IntuiText                    (IS)
GA_Text                         (IS)
GA_LabelImage                   (IS)

This copies the ti_Data value blindly into the Gadget.GadgetText field,
and sets the flags LABELSTRING and LABELIMAGE as appropriate in
Gadget.Flags.  GA_IntuiText requires that ti_Data be an IntuiText
pointer, as with old-style gadgets.  GA_Text takes a pointer to a NULL-
terminated string (UBYTE *).  GA_LabelImage takes a pointer to a
(boopsi) image.

Classes which support the attributes other than GA_IntuiText must
document themselves appropriately, but this facility allows us to have
low-overhead text gadgets and gadgets with iconic labels.


GA_Image                        (IS)

This may be a boopsi image or a regular image.  Things are designed so
that the image may be shared between gadgets. The image will not be
disposed when the gadget object is disposed.


GA_Border                       (IS)
GA_SelectRender                 (IS)
GA_ID                           (IS)
GA_UserData                     (IS)
GA_SpecialInfo                  (IS)

All of this group of attributes correspond to fields in the Gadget
structure.


GA_Disabled                     (IS)
GA_GZZGadget                    (IS)
GA_Selected                     (IS)
GA_EndGadget                    (IS)
GA_Immediate                    (IS)
GA_RelVerify                    (IS)
GA_FollowMouse                  (IS)
GA_RightBorder                  (IS)
GA_LeftBorder                   (IS)
GA_TopBorder                    (IS)
GA_BottomBorder                 (IS)
GA_ToggleSelect                 (IS)
GA_SysGadget                    (IS)
GA_TabCycle                     (IS)

This group corresponds to Boolean attributes (flags) in the Gadget
structure.  This class will put the correct flag in the correct field.
You can pass any non-zero value in the ti_Data tag field to cause the
corresponding flag to be set.  Pass zero to clear.


GA_HighLight                    (IS)

Sets the "GADGHIGHBITS" portion of Gadget.Flags to the attribute value
in ti_Data.


GA_SysGType                     (IS)

Sets the system gadget type portion of Gadget.GadgetType to the (masked)
value in ti_Data.


GA_Previous                     (I)

Previous gadget (or (struct Gadget **)) in linked list.  This attribute
cannot be used to link new gadgets into the gadget list of an open
window or requester.  You must use AddGList().


ICA_Target                      (IS)
ICA_Map                         (IS)

These are given the same meaning as in icclass, from which they are
borrowed.

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
