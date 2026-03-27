---
title: B Boopsi Class Reference / frameiclass
manual: libraries
chapter: libraries
section: b-boopsi-class-reference-frameiclass
functions: []
libraries: []
---

# B Boopsi Class Reference / frameiclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  frameiclass
Superclass:             [imageclass](libraries/b-boopsi-class-reference-imageclass.md)
Include File:           <intuition/[imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md)>

This is a class of framing image, which can optionally fill itself.  Its
purpose is to frame other display elements using an embossed or recessed
rectangular frame.  The frame renders itself using the appropriate
[DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) pens (SHINEPEN, SHADOWPEN, etc.).  This class is intelligent
enough to bound or center its contents.


New Methods:
------------
None.

Changed Methods:
----------------
 [IM_DRAW](libraries/b-frameiclass-changed-methods-im-draw.md) 
 [IDS_NORMAL, IDS_INACTIVENORMAL, IDS_DISABLED](libraries/b-frameiclass-ids-normal-ids-inactivenormal-ids-disabled.md) 
 [IDS_SELECTED, IDS_INACTIVESELECTED](libraries/b-frameiclass-changed-methods-ids-selected-ids.md) 
 [IM_DRAWFRAME](libraries/b-frameiclass-changed-methods-im-drawframe.md) 
 [IM_FRAMEBOX](libraries/b-frameiclass-changed-methods-im-framebox.md) 

Attributes:
-----------
 [IA_Recessed (IS)](libraries/b-frameiclass-attributes-ia-recessed-is.md)    [IA_EdgesOnly (IS)](libraries/b-frameiclass-attributes-ia-edgesonly-is.md) 

