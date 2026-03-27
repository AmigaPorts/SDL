---
title: 5 Intuition Gadgets / Gadget Highlighting
manual: libraries
chapter: libraries
section: 5-intuition-gadgets-gadget-highlighting
functions: []
libraries: []
---

# 5 Intuition Gadgets / Gadget Highlighting

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In general, the appearance of an active or selected gadget changes to
inform the user the gadget state has changed.  A highlighting method is
specified by setting one of the highlighting flags in the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)
structure's [Flags](libraries/5-intuition-gadgets-gadget-structure.md) field.

Intuition supports three methods of activation or selection highlighting:

  * Highlighting by color complementing ([GFLG_GADGHCOMP](libraries/5-gadget-structure-gadget-flags.md))

  * Highlighting by drawing a box ([GFLG_GADGHBOX](libraries/5-gadget-structure-gadget-flags.md))

  * Highlighting by an alternate image or border ([GFLG_GADGHIMAGE](libraries/5-gadget-structure-gadget-flags.md))

  * No highlighting ([GFLG_GADGHNONE](libraries/5-gadget-structure-gadget-flags.md))

One of the highlighting types or [GFLG_GADGHNONE](libraries/5-gadget-structure-gadget-flags.md) must be specified for each
gadget.

 [Highlighting by Color Complementing](libraries/5-gadget-highlighting-highlighting-by-color-complementing.md) 
 [Highlighting by Drawing a Box](libraries/5-gadget-highlighting-highlighting-by-drawing-a-box.md) 
 [Highlighting with an Alternate Image or Alternate Border](libraries/5-gadget-highlighting-with-an-alternate-image-or-alternate.md) 

