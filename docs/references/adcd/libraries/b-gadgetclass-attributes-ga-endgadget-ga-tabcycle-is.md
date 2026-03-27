---
title: B / gadgetclass / Attributes: GA_EndGadget - GA_TabCycle (IS)
manual: libraries
chapter: libraries
section: b-gadgetclass-attributes-ga-endgadget-ga-tabcycle-is
functions: []
libraries: []
---

# B / gadgetclass / Attributes: GA_EndGadget - GA_TabCycle (IS)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

GA_EndGadget, GA_Immediate, GA_RelVerify, GA_FollowMouse, (IS)
GA_RightBorder, GA_LeftBorder, GA_TopBorder, GA_BottomBorder, (IS)
GA_ToggleSelect, GA_TabCycle (IS) - These are boolean attributes that
correspond to the flags in the object's [Gadget.Activation](libraries/5-intuition-gadgets-gadget-structure.md) field.  If the
value passed with the attribute is TRUE, the corresponding flag in
Gadget.Activation is set.  If the value passed with the attribute is
FALSE, the corresponding flag in Gadget.Activation is cleared.  See the
<intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)> include file or the "[Intuition Gadgets](libraries/5-intuition-gadgets-gadget-structure.md)" chapter of
the Amiga ROM Kernel Reference Manual: Libraries for more information.

