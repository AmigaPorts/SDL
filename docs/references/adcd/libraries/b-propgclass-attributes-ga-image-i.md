---
title: B / propgclass / Attributes: GA_Image (I)
manual: libraries
chapter: libraries
section: b-propgclass-attributes-ga-image-i
functions: []
libraries: []
---

# B / propgclass / Attributes: GA_Image (I)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[Propgclass](libraries/b-boopsi-class-reference-propgclass.md) intercepts this [gadgetclass](libraries/b-boopsi-class-reference-gadgetclass.md) attribute before passing it on to
gadgetclass.  This attribute passes an image for the prop gadget's knob,
which gets stored in the propgclass object's [Gadget.Image](libraries/5-intuition-gadgets-gadget-structure.md) structure.  If
the propgclass does not get a GA_Image when it creates a prop gadget, the
prop gadget's knob defaults to an AUTOKNOB.  An AUTOKNOB automatically
sizes itself according to how large the range of the gadget is compared to
the visible range of the gadget.  See the [PGA_Visible](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md) and [PGA_Total](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md)
attributes for more details.

