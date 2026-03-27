---
title: B Boopsi Class Reference / imageclass
manual: libraries
chapter: libraries
section: b-boopsi-class-reference-imageclass
functions: []
libraries: []
---

# B Boopsi Class Reference / imageclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  imageclass
Superclass:             [rootclass](libraries/b-boopsi-class-reference-rootclass.md)
Include File:           <intuition/[imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md)>

This class is the base class for Boopsi Images.  These images are
backwards compatible with the conventional Intuition Images.  Every Boopsi
image has an Intuition [Image](libraries/8-creating-images-image-structure.md) structure embedded in it so Intuition can
access the Boopsi image as a conventional Image structure when necessary.
Normally there are no direct instances of this class, only instances of
subclasses of imageclass.

New Methods:
------------
 [IM_DRAW](libraries/b-imageclass-new-methods-im-draw.md)       [IM_ERASE](libraries/b-imageclass-new-methods-im-erase.md)        [IM_HITFRAME](libraries/b-imageclass-new-methods-im-hitframe.md)      [IM_FRAMEBOX](libraries/b-imageclass-new-methods-im-framebox.md) 
 [IM_HITTEST](libraries/b-imageclass-new-methods-im-hittest.md)    [IM_DRAWFRAME](libraries/b-imageclass-new-methods-im-drawframe.md)    [IM_ERASEFRAME](libraries/b-imageclass-new-methods-im-eraseframe.md) 

Changed Methods:
----------------
 [OM_NEW](libraries/b-imageclass-changed-methods-om-new.md)    [OM_SET](libraries/b-imageclass-changed-methods-om-set.md) 

Attributes:
-----------
 [IA_Left, IA_Top, IA_Width, IA_Height (ISG)](libraries/b-imageclass-attributes-ia-left-ia-top-ia-width-ia-height.md) 
 [IA_FGPen, IA_BGPen (ISG)](libraries/b-imageclass-attributes-ia-fgpen-ia-bgpen-isg.md) 
 [IA_Data (ISG)](libraries/b-imageclass-attributes-ia-data-isg.md) 
 [IA_Pens ()](libraries/b-imageclass-attributes-ia-pens.md) 

