---
title: 5 / / Gadget Refreshing by the Program / Updating a Gadget's Imagery
manual: libraries
chapter: libraries
section: 5-gadget-refreshing-by-the-program-updating-a-gadget-s
functions: [RectFill, RefreshGList, RemoveGList]
libraries: [graphics.library, intuition.library]
---

# 5 / / Gadget Refreshing by the Program / Updating a Gadget's Imagery

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [RefreshGList()](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md) function was designed to draw gadgets from scratch, and
assumes that the underlying area is blank.  This function cannot be used
blindly to update gadget imagery.  The typical problem that arises is that
the application cannot change a gadget from selected to unselected state
(or from disabled to enabled state) and have the imagery appear correct.
However, with a little care, the desired results can be obtained.

Depending on the imagery you select for your gadget, the rendering of one
state may not completely overwrite the rendering of a previous one.  For
example, consider a button which consists of a complement-highlighted
[boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadget, whose imagery is a surrounding [Border](libraries/8-creating-borders-border-structure-definition.md) and whose label is
an [IntuiText](libraries/8-creating-text-intuitext-structure.md).  Attempting to visually unselect such a gadget by clearing
its [GFLG_SELECTED](libraries/5-gadget-structure-gadget-flags.md) flag and refreshing it will leave incorrect imagery
because [RefreshGList()](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md) just redraws the border and text, and never knows
to erase the field area around the text and inside the gadget.  That area
will remain complemented from before.

One solution is to use a gadget whose imagery is certain to overwrite any
imagery left over from a different state.  Disabling a gadget or
highlighting it with complement mode affects the imagery in the entire
select box.  To overwrite this successfully, the gadget's imagery
([GadgetRender](libraries/5-intuition-gadgets-gadget-structure.md)) should be an [Image](libraries/8-creating-images-image-structure.md) structure which fully covers the select
box.  Such a gadget may be highlighted with color complementing
([GFLG_GADGHCOMP](libraries/5-gadget-structure-gadget-flags.md)), or with an alternate image ([GFLG_GADGHIMAGE](libraries/5-gadget-structure-gadget-flags.md)) for its
[SelectRender](libraries/5-intuition-gadgets-gadget-structure.md).  Or, for a gadget which will never be disabled but needs to
be deselected programmatically, you may also use a [Border](libraries/8-creating-borders-border-structure-definition.md) structure for
its GadgetRender, and an identically-shaped (but differently colored)
Border for its SelectRender.

The other technique is to pre-clear the underlying area before
re-rendering the gadget.  To do this, remove the gadget, erase the
rectangle of the gadget's select area, change the [GFLG_SELECTED](libraries/5-gadget-structure-gadget-flags.md) or the
[GFLG_DISABLED](libraries/5-gadget-structure-gadget-flags.md) flag, add the gadget back, and refresh it.

If the gadget has a relative size and/or position (i.e., if of the
GFLG_RELxxx flags are used), then the application will need to compute the
rectangle of the gadget's select area based on the window's current width
and/or height.  Since the window size is involved in the calculation, it
is important that the window not change size between the call to
[RemoveGList()](libraries/5-about-gadgets-adding-and-removing-gadgets.md) and the call to [RectFill()](libraries/27-using-the-graphics-drawing-routines-rectangle-fill.md).  To ensure this, the application
should set [IDCMP_SIZEVERIFY](libraries/9-event-message-classes-and-flags-window-flags.md) so that Intuition will first notify you before
beginning a sizing operation.  (Note that applications using any of the
IDCMP verify events such as IDCMP_SIZEVERIFY should not delay long in
processing such events, since that holds up the user, and also Intuition
may give up and stop waiting for you).

---

## See Also

- [RectFill — graphics.library](../autodocs/graphics.library.md#rectfill)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
