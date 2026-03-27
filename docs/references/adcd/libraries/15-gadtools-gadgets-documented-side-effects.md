---
title: 15 / GadTools Gadgets / Documented Side-Effects
manual: libraries
chapter: libraries
section: 15-gadtools-gadgets-documented-side-effects
functions: [GT_FilterIMsg, GT_PostFilterIMsg]
libraries: [gadtools.library]
---

# 15 / GadTools Gadgets / Documented Side-Effects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are certain aspects of the behavior of GadTools gadgets that should
not be depended on. This will help current applications remain compatible
with future releases of the GadTools library.

When using [GT_FilterIMsg()](libraries/15-other-functions-gt-filterimsg-and-gt-postfilterimsg.md) and [GT_PostFilterIMsg()](libraries/15-other-functions-gt-filterimsg-and-gt-postfilterimsg.md), never make assumptions
about the message before or after filtering.  I.e., do not interpret the
unfiltered message, assume that it will or will not result in certain
kinds of filtered message or assume it will result in a consumed message
(i.e., when GT_FilterIMsg() returns NULL).

[IDCMP_INTUITICKS](libraries/9-event-message-classes-and-flags-other-flags.md) messages are consumed when a scroller's arrows are
repeating.  That is, IDCMP_INTUITICKS will not be received while the user
is pressing a scroller arrows.  Do not depend or rely on this side effect,
though, it will not necessarily remain so in the future.

A single call to [CreateGadget()](libraries/15-gadtools-gadgets-creating-gadgets.md) may create one or more actual gadgets.
These gadgets, along with the corresponding code in GadTools, define the
behavior of the particular kind of GadTools gadget requested.  Only the
behavior of these gadgets is documented, the number or type of actual
gadgets is subject to change.  Always refer to the gadget pointer received
from CreateGadget() when calling [GT_SetGadgetAttrs()](libraries/15-gadtools-gadgets-modifying-gadgets.md).  Never refer to
other gadgets created by GadTools, nor create code which depends on their
number or form.

For text-display gadgets, the [GTTX_CopyText](libraries/15-kinds-of-gadtools-text-display-and-numeric-display.md) tag does not cause the text to
be copied when the text is later changed with [GTTX_Text](libraries/15-kinds-of-gadtools-text-display-and-numeric-display.md).

The PLACETEXT [ng_Flags](libraries/15-gadtools-gadgets-the-newgadget-structure.md) are currently ignored by [GENERIC_KIND](libraries/15-the-kinds-of-gadtools-gadgets-generic-gadgets.md) gadgets.
However, this may not always be so.

All GadTools gadgets set GADTOOL_TYPE in the gadget's [GadgetType](libraries/5-intuition-gadgets-gadget-structure.md) field.
Do not use this flag to identify GadTools gadgets, as this flag is not
guaranteed to be set in the future.

The palette gadget subdivides its total area into the individual color
squares. Do not assume that the subdivision algorithm won't change.

---

## See Also

- [GT_FilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_filterimsg)
- [GT_PostFilterIMsg — gadtools.library](../autodocs/gadtools.library.md#gt_postfilterimsg)
