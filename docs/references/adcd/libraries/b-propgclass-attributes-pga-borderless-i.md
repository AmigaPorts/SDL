---
title: B / propgclass / Attributes: PGA_Borderless (I)
manual: libraries
chapter: libraries
section: b-propgclass-attributes-pga-borderless-i
functions: []
libraries: []
---

# B / propgclass / Attributes: PGA_Borderless (I)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is a boolean attribute which corresponds to the [PROPBORDERLESS](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) flag of
the [PropInfo](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) structure's [Flags](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) field (defined in <intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>).
If this attribute is TRUE, the new [propgclass](libraries/b-boopsi-class-reference-propgclass.md) object will not have a
border around it.  In an [AUTOKNOB](libraries/5-initialization-of-proportional-gadget-the-propinfo.md) propgclass gadget, if the [PROPNEWLOOK](libraries/5-initialization-of-proportional-gadget-the-propinfo.md)
flag is set as well (see the [PGA_NewLook](libraries/b-propgclass-attributes-pga-newlook-i.md) attribute), the knob will have a
3D appearance.

