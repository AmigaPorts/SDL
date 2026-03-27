---
title: B / gadgetclass / Attributes: GA_Previous (I)
manual: libraries
chapter: libraries
section: b-gadgetclass-attributes-ga-previous-i
functions: [AddGList]
libraries: [intuition.library]
---

# B / gadgetclass / Attributes: GA_Previous (I)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This attribute is used to insert a new gadget into a list of gadgets
linked by their [Gadget.NextGadget](libraries/5-intuition-gadgets-gadget-structure.md) field.  When the [OM_NEW](libraries/b-gadgetclass-changed-methods-om-new.md) method creates
the new gadget, it inserts the new gadget into the list following the
GA_Previous gadget.  This attribute is a pointer to the gadget  (struct
Gadget *) that the new gadget will follow.  This attribute cannot be used
to link new gadgets into the gadget list of an open window or requester,
use [AddGList()](libraries/5-about-gadgets-adding-and-removing-gadgets.md) instead.

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
