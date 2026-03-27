---
title: B Boopsi Class Reference / groupgclass
manual: libraries
chapter: libraries
section: b-boopsi-class-reference-groupgclass
functions: []
libraries: []
---

# B Boopsi Class Reference / groupgclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  groupgclass
Superclass:             [gadgetclass](libraries/b-boopsi-class-reference-gadgetclass.md)
Include File:           <intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>

This is a class of objects that maintains an internal list of gadgets.
Its purpose is to make it easier to layout a group of gadgets.  Any
gadgets that are a member of a groupgclass object are rendered relative to
the groupgclass object's GA_Left and GA_Top attributes.  As new gadgets
are added to the groupgclass object, the groupgclass object's dimensions
grow to enclose the new gadgets.  When the groupgclass object receives an
[OM_DISPOSE](libraries/b-rootclass-new-methods-om-dispose.md) message, it not only disposes of itself, it also disposes of
all the gadgets in its list.  Groupgclass does not support the gadget
relative flags ([GA_RelWidth, GA_RelHeight, GA_RelBottom, and GA_RelRight](libraries/b-ga-relright-ga-relbottom-ga-relwidth-ga-relheight-is.md)).

New Methods:
------------
None.

Changed Methods:
----------------
 [OM_SET](libraries/b-groupgclass-changed-methods-om-set.md)          [GM_HITTEST](libraries/b-groupgclass-changed-methods-gm-hittest.md) 
 [OM_ADDMEMBER](libraries/b-groupgclass-changed-methods-om-addmember.md)    [GM_RENDER](libraries/b-groupgclass-changed-methods-gm-render.md) 
 [OM_REMMEMBER](libraries/b-groupgclass-changed-methods-om-remmember.md)    [GM_GOACTIVE/GM_GOINACTIVE/GM_HANDLEINPUT](libraries/b-groupgclass-changed-gm-goactive-gm-goinactive-gm.md) 
 [OM_DISPOSE](libraries/b-groupgclass-changed-methods-om-dispose.md) 

Attributes:
-----------
 [GA_Left, GA_Top (IS)](libraries/b-groupgclass-attributes-ga-left-ga-top-is.md) 

