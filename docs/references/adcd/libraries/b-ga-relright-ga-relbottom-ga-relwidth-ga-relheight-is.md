---
title: B / / GA_RelRight, GA_RelBottom, GA_RelWidth, GA_RelHeight (IS)
manual: libraries
chapter: libraries
section: b-ga-relright-ga-relbottom-ga-relwidth-ga-relheight-is
functions: []
libraries: []
---

# B / / GA_RelRight, GA_RelBottom, GA_RelWidth, GA_RelHeight (IS)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These attributes correspond to the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md) structure's [LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md), [TopEdge](libraries/5-intuition-gadgets-gadget-structure.md),
[Width](libraries/5-intuition-gadgets-gadget-structure.md), and [Height](libraries/5-intuition-gadgets-gadget-structure.md) fields.  Setting any of these attributes also sets the
corresponding "relative" flag in the Gadget structure's [Flags](libraries/5-intuition-gadgets-gadget-structure.md) field
(respectively, [GFLG_RELRIGHT](libraries/5-gadget-structure-gadget-flags.md), [GFLG_RELBOTTOM](libraries/5-gadget-structure-gadget-flags.md), [GFLG_RELWIDTH](libraries/5-gadget-structure-gadget-flags.md), and
[GFLG_RELHEIGHT](libraries/5-gadget-structure-gadget-flags.md)).  Note that the value passed in this attribute is normally
a negative LONG.  See the "[Intuition Gadgets](libraries/5-gadget-structure-gadget-flags.md)" chapter of the Amiga ROM
Kernel Reference Manual: Libraries for more information on these flags.

