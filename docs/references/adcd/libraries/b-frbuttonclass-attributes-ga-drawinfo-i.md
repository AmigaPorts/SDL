---
title: B / frbuttonclass / Attributes: GA_DrawInfo (I)
manual: libraries
chapter: libraries
section: b-frbuttonclass-attributes-ga-drawinfo-i
functions: []
libraries: []
---

# B / frbuttonclass / Attributes: GA_DrawInfo (I)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This attribute passes a pointer to a valid [DrawInfo](libraries/b-rootclass-new-methods-om-dispose.md) structure.  If the
[frbuttonclass](libraries/b-boopsi-class-reference-frbuttonclass.md) gadget is going to frame plain text (passed to it in the
[GA_Text](libraries/b-gadgetclass-attributes-ga-intuitext-ga-text-ga-labelimage.md) attribute), the frbuttonclass gadget requires a DrawInfo structure
to properly calculate the dimensions of the text.

