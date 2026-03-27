---
title: groupgclass
manual: amiga-mail
chapter: amiga-mail
section: groupgclass
functions: []
libraries: []
---

# groupgclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  groupgclass
Superclass:             gadgetclass
Description:            Composite gadget objects
Include File:           <intuition/gadgetclass.h>


New Methods:
------------

None


Changed Methods:
----------------

OM_SET - Passes most attributes to the superclass, but propagates
changes in position to its members appropriately. Also, GA_Width and
GA_Height are calculated from the position and dimension of the
membership.


OM_ADDMEMBER - add a gadget to the group list.  Add the gadgets you want
in the group right after you create it and leave them there until you
are done.  Note that all members of the groupgclass object will be
deleted by OM_DISPOSE.


OM_DISPOSE - this class will dispose of the object and all its member
gadgets.


Attributes:
-----------

LAYOUTA_Orientation
LAYOUTA_Spacing
LAYOUTA_LayoutObj

These attributes specify simple layout parameters and a "layout object
delegate" are not currently implemented.  GA_Width and GA_Height are
calculated from the membership.


GA_Left                         (IS)
GA_Position                     (IS)

These are propagated magically to the membership.

The gadget relative flags (GA_RelWidth, GA_RelHeight, and so on) are not
supported.

