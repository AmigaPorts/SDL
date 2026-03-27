---
title: 5 / Gadget Refreshing / Gadget Refreshing by the Program
manual: libraries
chapter: libraries
section: 5-gadget-refreshing-gadget-refreshing-by-the-program
functions: [AddGList, RefreshGList, RemoveGList]
libraries: [intuition.library]
---

# 5 / Gadget Refreshing / Gadget Refreshing by the Program

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [AddGList()](libraries/5-about-gadgets-adding-and-removing-gadgets.md) function adds gadgets to Intuition's internal lists but do
not display their imagery.  Subsequently calls to [RefreshGList()](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md) must be
made to draw the gadgets into the window or requester.

Programs may use [RefreshGList()](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md) to update the display after making changes
to their gadgets.  The supported changes include (not an exhaustive list):
changing the [GFLG_SELECTED](libraries/5-gadget-structure-gadget-flags.md) flag for [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets to implement mutually
exclusive gadgets, changing the [GadgetText](libraries/5-intuition-gadgets-gadget-structure.md) of a gadget to change its
label, changing the [GFLG_DISABLED](libraries/5-gadget-structure-gadget-flags.md) flag, and changing the contents of the
[StringInfo](libraries/5-string-gadget-type-stringinfo-structure.md) structure [Buffer](libraries/5-string-gadget-type-stringinfo-structure.md) of a [string](libraries/5-intuition-gadgets-string-gadget-type.md) gadget.  When making changes to a
gadget, be sure to remove the gadget from the system with [RemoveGList()](libraries/5-about-gadgets-adding-and-removing-gadgets.md)
before altering it.  Remember to add the gadget back and refresh its
imagery.

[Boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadgets rendered with borders, instead of images, or highlighted
with surrounding boxes ([GFLG_GADGHBOX](libraries/5-gadget-structure-gadget-flags.md)) are handled very simply by
Intuition, and complicated transitions done by the program can get the
rendering out of phase.  Applications should avoid modifying the imagery
and refreshing gadgets that may be highlighted due to selection by the
user.  Such operations may leave pixels highlighted when the gadget is no
longer selected.  The problems with such transitions can often be avoided
by providing imagery, either image or border, that covers all pixels in
the select box.  For [GFLG_GADGHIMAGE](libraries/5-gadget-structure-gadget-flags.md) gadgets, the select imagery should
cover all pixels covered in the normal imagery.

 [Updating a Gadget's Imagery](libraries/5-gadget-refreshing-by-the-program-updating-a-gadget-s.md)    [gadget Refresh Function](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md) 

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
