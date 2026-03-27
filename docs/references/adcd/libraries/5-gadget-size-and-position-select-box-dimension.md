---
title: 5 / Gadget Size and Position / Select Box Dimension
manual: libraries
chapter: libraries
section: 5-gadget-size-and-position-select-box-dimension
functions: []
libraries: []
---

# 5 / Gadget Size and Position / Select Box Dimension

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The height and width of the gadget select box can be absolute or they can
be relative to the height and width of the display element in which the
gadget resides.

Set the gadget's [GFLG_RELWIDTH](libraries/5-gadget-structure-gadget-flags.md) flag to make the gadget's width relative to
the width of the window.  When this flag is set, the [Width](libraries/5-intuition-gadgets-gadget-structure.md) value is added
to the current window width to determine the width of the gadget select
box.  The Width value is usually negative in this case, making the width
of the gadget smaller than the width of the window.  If GFLG_RELWIDTH is
not set, Width will specify the actual width of the select box.

The actual width of the box will be recomputed each time the window is
sized.  Setting [GFLG_RELWIDTH](libraries/5-gadget-structure-gadget-flags.md) and a gadget width of zero will create a
gadget that is always as wide as the window, regardless of how the window
is sized.

The [GFLG_RELHEIGHT](libraries/5-gadget-structure-gadget-flags.md) flag has the same effect on the height of the gadget
select box.  If the flag is set, the height of the select box will be
relative to the height of the window, and the actual height will be
recomputed each time the window is sized.  If the flag is not set, the
value will specify the actual height of the select box.

Here are a few examples of gadgets that take advantage of the special
relativity modes of the select box.  Consider the Intuition window sizing
gadget.  The [LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md) and [TopEdge](libraries/5-intuition-gadgets-gadget-structure.md) of this gadget are both defined relative
to the right and bottom edges of the window.  No matter how the window is
sized, the gadget always appears in the lower right corner.

For the window drag gadget, the [LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md) and [TopEdge](libraries/5-intuition-gadgets-gadget-structure.md) are always absolute
in relation to the top left corner of the window.  [Height](libraries/5-intuition-gadgets-gadget-structure.md) of this gadget
is always an absolute quantity.  [Width](libraries/5-intuition-gadgets-gadget-structure.md) of the gadget, however, is defined
to be zero.  When Width is combined with the effect of the [GFLG_RELWIDTH](libraries/5-gadget-structure-gadget-flags.md)
flag, the drag gadget is always as wide as the window.

For a program with several requesters, each of which has an "OK" gadget in
the lower left corner and a "Cancel" gadget in the lower right corner, two
gadgets may be designed that will appear in the correct position
regardless of the size of the requester.  Design the "OK" and "Cancel"
gadgets such that they are relative to the lower left and lower right
corners of the requester.  Regardless of the size of the requesters, these
gadgets will appear in the correct position relative to these corners.
Note that these gadgets may only be used in one window or requester at a
time.

