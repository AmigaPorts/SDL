---
title: propgclass
manual: amiga-mail
chapter: amiga-mail
section: propgclass
functions: [NewObject]
libraries: [intuition.library]
---

# propgclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  propgclass
Superclass:             gadgetclass
Description:            Extended function proportional gadgets.
Include File:           <intuition/gadgetclass.h>


New Methods:
------------

None.


Changed Methods:
----------------

All methods defined by gadgetclass are handled to provide compatible
proportional gadget processing.


OM_SET, OM_UPDATE - Changes attributes and, if needed and if propgclass
is the true class, will update the slider visuals by updating the knob
position and dimensions.


GM_HANDLEINPUT - If the knob position changes sufficiently to change
PGA_Top, this method will issue an OM_NOTIFY message, with attributes
PGA_Top and GA_ID.  The OPUF_INTERIM flag will be set for intermediate
messages issued while the mouse is dragging the slider knob. This method
Will issue a message with OPUF_INTERIM clear when it is done, which is
the "final value".


Attributes:
-----------

GA_Image                        (I)
GA_Border                       (I)

If you don't pass GA_Image to NewObject(), the gadget will create and
use an AUTOKNOB.  Likewise if you pass (the "illegal" attribute)
GA_Border: an AUTOKNOB will be used instead.


GA_HighLight                    (I)

GADGHBOX highlighting is not allowed, and will be converted to GADGHBOX.


GA_SpecialInfo                  ()

This attributed is "forced" to point to the PropInfo allocated for
objects of this class.

Other gadgetclass attributes are passed along to the superclass.


PGA_Freedom                     (IG)

May be either of FREEHORIZ or FREEVERT (not both).  The default is
FREEVERT.


PGA_Borderless                  (I)

Means the same as PropInfo.Flags BORDERLESS.


PGA_HorizPot, PGA_VertPot, PGA_HorizBody, PGA_VertBody

These are defined in the include file but obsolete and will not be
supported.  Class propgclass supports gadgets that are vertical or
horizontally free, but not both.


PGA_Top                         (ISGNU)
PGA_Visible                     (ISU)
PGA_Total                       (ISU)

These attributes are very useful replacements to Pot and Body variables.
They are based on the use of proportional gadgets to control scrolling
text.  When scrolling 100 lines of text in a 25 line visible window, you
would set PGA_Total to 100, PGA_Visible to 25, and watch PGA_Top run
from 0 to 75 (the top line of the last page).  All internal prop gadget
values will be calculated based on these (depending on whether the
gadget is FREEHORIZ or FREEVERT). "Container clicks" for page jumps will
leave an overlap of one line, unless the value PGA_Visible is 1, in
which case the prop gadget acts as an integer numeric slider taking
values from 0 to PGA_Total - 1.  Note that PGA_Top has OM_NOTIFY access.
All three of these attributes have OM_UPDATE access, so they can be
controlled via interconnections.


PGA_NewLook                     (I)

Equivalent to PropInfo.Flags PROPNEWLOOK flag.

---

## See Also

- [NewObject — intuition.library](../autodocs/intuition.library.md#newobject)
