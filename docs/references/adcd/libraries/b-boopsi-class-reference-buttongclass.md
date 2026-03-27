---
title: B Boopsi Class Reference / buttongclass
manual: libraries
chapter: libraries
section: b-boopsi-class-reference-buttongclass
functions: []
libraries: []
---

# B Boopsi Class Reference / buttongclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  buttongclass
Superclass:             [gadgetclass](libraries/b-boopsi-class-reference-gadgetclass.md)
Include File:           <intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>

A class of button gadget that continually sends interim [OM_UPDATE](libraries/b-rootclass-new-methods-om-update.md) messages
to its target while the user holds down the button.  The button sends a
final OM_UPDATE message when the user lets  go of the button.  The imagery
for these objects is not built directly into the gadget.  Instead, a
buttongclass object uses a Boopsi image object, which it gets from its
GA_Image attribute.

New Methods:
------------
None.

Changed Methods:
----------------
 [GM_HITTEST](libraries/b-buttongclass-changed-methods-gm-hittest.md)    [GM_HANDLEINPUT](libraries/b-buttongclass-changed-methods-gm-handleinput.md)    [GM_RENDER](libraries/b-buttongclass-changed-methods-gm-render.md) 

Attributes:
-----------
 [GA_IMAGE (IS)](libraries/b-buttongclass-attributes-ga-image-is.md) 

