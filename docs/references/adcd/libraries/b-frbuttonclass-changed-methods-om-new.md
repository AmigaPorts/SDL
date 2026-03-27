---
title: B / frbuttonclass / Changed Methods: OM_NEW
manual: libraries
chapter: libraries
section: b-frbuttonclass-changed-methods-om-new
functions: []
libraries: []
---

# B / frbuttonclass / Changed Methods: OM_NEW

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When this class creates an object, it sets the object's embedded
[Gadget.Width](libraries/5-intuition-gadgets-gadget-structure.md) and [Gadget.Height](libraries/5-intuition-gadgets-gadget-structure.md) fields according to the frame image in
[GA_Image](libraries/b-gadgetclass-attributes-ga-image-is.md).  If the GA_Image understands the [IM_FRAMEBOX](libraries/b-imageclass-new-methods-im-framebox.md) method, the gadget
asks the GA_Image what it dimensions would be if it had to surround the
display element.  If the GA_Image does not support IM_FRAMEBOX, it just
copies the GA_Image image's width and height into the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.

