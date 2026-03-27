---
title: 5 / Gadget Size and Position / Select Box Position
manual: libraries
chapter: libraries
section: 5-gadget-size-and-position-select-box-position
functions: []
libraries: []
---

# 5 / Gadget Size and Position / Select Box Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To specify relative position or size for the gadget's select box, set or
more of the flags [GFLG_RELRIGHT](libraries/5-gadget-structure-gadget-flags.md), [GFLG_RELBOTTOM](libraries/5-gadget-structure-gadget-flags.md), [GFLG_RELWIDTH](libraries/5-gadget-structure-gadget-flags.md) or
[GFLG_RELHEIGHT](libraries/5-gadget-structure-gadget-flags.md) in the [Flags](libraries/5-intuition-gadgets-gadget-structure.md) field of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure.  When using
GFLG_RELxxx flags, the gadget size or position is recomputed each time the
window is sized.


    Positioning the Select Box.
    ---------------------------
    With GFLG_RELxxx gadgets, all of the imagery must be contained
    within the gadget's select box.  This allows Intuition to erase the
    gadget's imagery when the window is sized.  Intuition must be able to
    erase the gadget's imagery since the gadget's position or size will
    change as the window size changes.  If the old one were not removed,
    imagery from both sizes/positions would be visible.

    If a GFLG_RELxxx gadget's imagery must extend outside of its select
    box, position another GFLG_RELxxx gadget with a larger select box
    such that all of the first gadget's imagery is within the second
    gadget's select box. This "shadow" gadget is only used to clear the
    first gadget's imagery and, as such, it should not have imagery nor
    should it generate any messages. It should also be positioned later
    in the gadget list than the first gadget so that its select box does
    not interfere with the first gadget.
The left-right position of the select box is defined by the variable
[LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md), which is an offset from either the left or right edge of the
display element.  The offset method is determined by the [GFLG_RELRIGHT](libraries/5-gadget-structure-gadget-flags.md)
flag.  For the LeftEdge variable, positive values move toward the right
and negative values move toward the left of the containing display
element.  If GFLG_RELRIGHT is cleared, LeftEdge is an offset (usually a
positive value) from the left edge of the display element.

If [GFLG_RELRIGHT](libraries/5-gadget-structure-gadget-flags.md) is set, [LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md) is an offset (usually a negative value)
from the right edge of the display element.  When this is set, the
left-right position of the select box in the window is recomputed each
time the window is sized.  The gadget will automatically move with the
left border as the window is sized.

The top-bottom position of the select box is defined by the variable
[TopEdge](libraries/5-intuition-gadgets-gadget-structure.md), which is an offset from either the top or bottom edge of the
display element (window or requester).  The offset method is determined by
the [GFLG_RELBOTTOM](libraries/5-gadget-structure-gadget-flags.md) flag.  For the TopEdge variable, positive values move
toward the bottom and negative values move toward the top of the
containing display element.

If [GFLG_RELBOTTOM](libraries/5-gadget-structure-gadget-flags.md) is cleared, [TopEdge](libraries/5-intuition-gadgets-gadget-structure.md) is an offset (usually a positive
value) from the top of the display element.  If GFLG_RELBOTTOM is set,
TopEdge is an offset (usually a negative value) from the bottom of the
display element.  When this is set, the position of the select box is
recomputed each time the window is sized.  The gadget will automatically
move with the bottom border as the window is sized.

