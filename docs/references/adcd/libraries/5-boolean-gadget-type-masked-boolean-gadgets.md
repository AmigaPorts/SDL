---
title: 5 / Boolean Gadget Type / Masked Boolean Gadgets
manual: libraries
chapter: libraries
section: 5-boolean-gadget-type-masked-boolean-gadgets
functions: []
libraries: []
---

# 5 / Boolean Gadget Type / Masked Boolean Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Imagery for [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets is rectangular by default, but non-rectangular
boolean gadgets are possible, with some restrictions. An auxiliary bit
plane, called a mask, may be associated with a boolean gadget. When the
user clicks within the select box of the gadget, a further test is made to
see if the chosen point is contained within the mask. Only if it is, does
the interaction count as a gadget hit.

With masked [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets, if the gadget has highlight type
[GFLG_GADGHCOMP](libraries/5-gadget-structure-gadget-flags.md) then the complement rendering is restricted to the mask.
This allows for non-rectangular shapes, such as an oval gadget which
highlights only within the oval.

There are some shortcomings to non-rectangular [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets.  For
instance, the gadget image is not rendered through the mask.  Images are
rectangular blocks, with all bits rendered.  In the case of an oval mask,
the image will be rendered in the corner areas even though they are
outside of the oval.  Also, it is not possible to mask out the select box,
thus non-rectangular masked gadgets cannot overlap in the masked area.
Therefore, such gadgets can't be crowded together without care.  Likewise,
the ghosting of a disabled gadget does not respect the mask, so ghosting
of the corners around an oval may be visible, depending on the colors
involved.

To use a masked [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadget, fill out an instance of the [BoolInfo](libraries/5-boolean-gadget-type-boolinfo-structure.md)
structure.  This structure contains a pointer to the mask plane data.  The
application must also set the [GACT_BOOLEXTEND](libraries/5-gadget-structure-gadget-activation-flags.md) flag in the gadget's
[Activation](libraries/5-intuition-gadgets-gadget-structure.md) field.

