---
title: 7 / True Requesters / Gadgets in Requesters
manual: libraries
chapter: libraries
section: 7-true-requesters-gadgets-in-requesters
functions: [EndRequest]
libraries: [intuition.library]
---

# 7 / True Requesters / Gadgets in Requesters

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Each requester gadget must have the [GTYP_REQGADGET](libraries/5-intuition-gadgets-gadget-structure.md) flag set in the
[GadgetType](libraries/5-intuition-gadgets-gadget-structure.md) field of its [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.  This informs Intuition that
this gadget is to be rendered in a requester rather than a window.

Requesters can have gadgets in them that automatically satisfy the request
and end the requester.  When one of these gadgets is selected, Intuition
will remove the requester from the window.  This is equivalent to the
application calling [EndRequest()](libraries/7-true-requesters-creating-application-requesters.md), and, if the request is terminated by
selection of such a gadget, the application should not call EndRequest()
for that requester.

Set the [GACT_ENDGADGET](libraries/5-gadget-structure-gadget-activation-flags.md) flag in the [Activation](libraries/5-intuition-gadgets-gadget-structure.md) field of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)
structure to create a gadget that automatically terminates the requester.
Every time one of the requester's gadgets is selected, Intuition examines
the GACT_ENDGADGET flag.  If GACT_ENDGADGET is set, the requester is
removed from the display and unlinked from the window's active requester
list.

Requesters rendered via Intuition and those that use a custom bitmap
differ in how their gadgets are rendered.  For requesters rendered via
Intuition, the application supplies a regular gadget list just as it would
for application gadgets in a window.

In custom bitmap requesters, however, any gadget imagery is part of the
bitmap supplied for the requester.  Therefore the list of gadgets supplied
for custom bitmap requesters should not provide gadget imagery but rather
it should define only the select boxes, highlighting, and gadget types for
the gadgets.

The [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structures used with a custom bitmap requester should have
their [GadgetRender](libraries/5-intuition-gadgets-gadget-structure.md), [SelectRender](libraries/5-intuition-gadgets-gadget-structure.md) and [GadgetText](libraries/5-intuition-gadgets-gadget-structure.md) fields set to NULL as
these will be ignored.  Other gadget information--select box dimensions,
highlighting, and gadget type--is still relevant.  The select box
information is especially important since the select box must have a well
defined correspondence with the custom bitmap imagery supplied.  The basic
idea is to make sure that the user understands the requester imagery and
gadgets.

---

## See Also

- [EndRequest — intuition.library](../autodocs/intuition.library.md#endrequest)
