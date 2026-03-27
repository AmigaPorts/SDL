---
title: 28 / / Specifying Animation Components / Component Ordering
manual: libraries
chapter: libraries
section: 28-specifying-animation-components-component-ordering
functions: []
libraries: []
---

# 28 / / Specifying Animation Components / Component Ordering

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [PrevSeq](libraries/28-specifying-animation-components-sequencing-animcomps.md), [NextSeq](libraries/28-specifying-animation-components-sequencing-animcomps.md), [PrevComp](libraries/28-animation-components-linking-multiple-animcomp-sequences.md) and [NextComp](libraries/28-animation-components-linking-multiple-animcomp-sequences.md) linkages have no bearing on
the order in which [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md)s in any given video frame are drawn.  To
specify the inter-component priorities (so that the closest objects appear
frontmost) the [Before](libraries/28-bob-priorities-specifying-the-drawing-order.md) and [After](libraries/28-bob-priorities-specifying-the-drawing-order.md) pointers in the initially active
AnimComp's underlying [Bob](libraries/28-using-bobs-the-bob-structure.md) structure are linked in to the rest of the
system, as described previously in the discussion of Bobs.

This setup needs to be done once, for the initially active [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md)s of
the [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md) only.

The animation system adjusts the [Before](libraries/28-bob-priorities-specifying-the-drawing-order.md) and [After](libraries/28-bob-priorities-specifying-the-drawing-order.md) pointers of all the
underlying [Bob](libraries/28-using-bobs-the-bob-structure.md) structures to constantly maintain the inter-component
drawing sequence, even though different components are being made active
as sequencing occurs.

These pointers also assure that one complete object always has priority
over another object. The [Bob](libraries/28-using-bobs-the-bob-structure.md) [Before](libraries/28-bob-priorities-specifying-the-drawing-order.md) and [After](libraries/28-bob-priorities-specifying-the-drawing-order.md) pointers are used to link
together the last [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md)'s Bob of one [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md) to the first AnimComp's Bob
of the next AnimOb.

