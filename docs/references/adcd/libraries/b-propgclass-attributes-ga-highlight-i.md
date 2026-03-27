---
title: B / propgclass / Attributes: GA_Highlight (I)
manual: libraries
chapter: libraries
section: b-propgclass-attributes-ga-highlight-i
functions: []
libraries: []
---

# B / propgclass / Attributes: GA_Highlight (I)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[Propgclass](libraries/b-boopsi-class-reference-propgclass.md) intercepts this [gadgetclass](libraries/b-boopsi-class-reference-gadgetclass.md) attribute before passing it on to
gadgetclass.  It does this to make sure the highlighting is not set to
GADGHBOX.  GADGHBOX will be converted to GADGHCOMP.  See the
"[Intuition Gadgets](libraries/5-intuition-gadgets-gadget-highlighting.md)" chapter of the Amiga ROM Kernel Reference Manual:
Libraries for more information on the types of gadget highlighting.

Other [gadgetclass](libraries/b-boopsi-class-reference-gadgetclass.md) attributes are passed along to the superclass.

