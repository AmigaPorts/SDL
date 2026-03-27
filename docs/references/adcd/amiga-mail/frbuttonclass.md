---
title: frbuttonclass
manual: amiga-mail
chapter: amiga-mail
section: frbuttonclass
functions: []
libraries: []
---

# frbuttonclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  frbuttonclass
Superclass:             buttongclass
Description:            A button gadget that knows how to outline its

                        "label" within a shared "frame image".
New Methods:
------------

None.


Changed Methods:
----------------

OM_NEW - Will set up its dimensions depending on GA_Image, including
support for frame images.  If GA_Image understands the IM_FRAMEBOX
method, dimensions are calculated to surround the "label" stashed in
GadgetText, which can be GA_IntuiText, GA_Text, or GA_LabelImage.


OM_SET - If you change the dimensions, this method will adjust the
contents by using IM_FRAMEBOX with FRAMEIF_SPECIFY.


GM_HITTEST - uses IM_HITFRAME.


GM_RENDER - uses IM_DRAWFRAME.  First draws the frame, then draws the
contents or label described under OM_NEW.


Attributes:
-----------

GA_Width                        (IS)
GA_Height                       (IS)

If you change these, the contents will be readjusted and the gadget re-
rendered.

