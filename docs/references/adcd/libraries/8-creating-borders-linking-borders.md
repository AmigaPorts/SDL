---
title: 8 / Creating Borders / Linking Borders
manual: libraries
chapter: libraries
section: 8-creating-borders-linking-borders
functions: []
libraries: []
---

# 8 / Creating Borders / Linking Borders

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [NextBorder](libraries/8-creating-borders-border-structure-definition.md) field can point to another instance of a [Border](libraries/8-creating-borders-border-structure-definition.md) structure.
This allows complex graphic objects to be created by linking together
Border structures, each with its own data points, color and draw mode.
This might be used, for instance, to draw a double border around a
requester or gadget where the outer border is a second Border structure,
linked to the first inner border.

Note that the borders can share data.  For instance, to create a border
with a shadow, link two borders together each of which points to the same
[XY](libraries/8-creating-borders-border-structure-definition.md) data.  Set the first border to draw in a dark pen (such as the
[SHADOWPEN](libraries/3-drawinfo-and-the-3d-look-the-pen-specification-in-drawinfo.md) from the screen's [DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) structure) and position the border
down and to the right a few pixels by changing [LeftEdge](libraries/8-creating-borders-border-structure-definition.md) and [TopEdge](libraries/8-creating-borders-border-structure-definition.md) in the
[Border](libraries/8-creating-borders-border-structure-definition.md) structure.

The second border should be set to a bright pen (such as the [SHINEPEN](libraries/3-drawinfo-and-the-3d-look-the-pen-specification-in-drawinfo.md) in
the screen's [DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) structure).  When the border is drawn, the first
border will draw in a dark color and then the second border will be drawn
over it in a light color.  Since they use the same data set, and the dark
border is shifted down and to the right, the border will have a three
dimensional appearance.  This technique is demonstrated in the [example](libraries/lib-examples-shadowborder-c.md)
listed earlier in this section.

