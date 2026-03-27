---
title: B Boopsi Class Reference / frbuttonclass
manual: libraries
chapter: libraries
section: b-boopsi-class-reference-frbuttonclass
functions: []
libraries: []
---

# B Boopsi Class Reference / frbuttonclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  frbuttonclass
Superclass:             [buttongclass](libraries/b-boopsi-class-reference-buttongclass.md)
Include File:           <intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>

This is a special class of button gadget that puts a Boopsi framing image
around some other display element.  This display element can be one of
three things: plain text from the [GA_Text](libraries/b-gadgetclass-attributes-ga-intuitext-ga-text-ga-labelimage.md) attribute, an [IntuiText](libraries/8-creating-text-intuitext-structure.md) from the
[GA_IntuiText](libraries/b-gadgetclass-attributes-ga-intuitext-ga-text-ga-labelimage.md) attribute, or an Image from the [GA_LabelImage](libraries/b-gadgetclass-attributes-ga-intuitext-ga-text-ga-labelimage.md) attribute.

The user activates the gadget by clicking within the bounds of the
gadget's framing image, which it gets from the [GA_Image](libraries/b-gadgetclass-attributes-ga-image-is.md) attribute.
Usually the framing image is an instance of an image class that supports
the IM_FRAMEBOX method (like [frameiclass](libraries/b-boopsi-class-reference-frameiclass.md)).  If the framing image supports
the IM_FRAMEBOX method, the frbuttonclass object centers the frame image
around the display element.  See the [imageclass](libraries/b-boopsi-class-reference-imageclass.md) description of [IM_FRAMEBOX](libraries/b-imageclass-new-methods-im-framebox.md)
for more information.

New Methods:
------------
None.

Changed Methods:
----------------
 [OM_NEW](libraries/b-frbuttonclass-changed-methods-om-new.md)    [GM_HITTEST](libraries/b-frbuttonclass-changed-methods-gm-hittest.md)    [GM_RENDER](libraries/b-frbuttonclass-changed-methods-gm-render.md) 

Attributes:
-----------
 [GA_Width, GA_Height (S)](libraries/b-frbuttonclass-attributes-ga-width-ga-height-s.md) 
 [GA_DrawInfo (I)](libraries/b-frbuttonclass-attributes-ga-drawinfo-i.md) 
 [GA_Text, GA_IntuiText, GA_LabelImage (IS)](libraries/b-frbuttonclass-attributes-ga-text-ga-intuitext-ga.md) 

