---
title: 8 / Intuition Graphic Objects / Positioning Graphic Objects
manual: libraries
chapter: libraries
section: 8-intuition-graphic-objects-positioning-graphic-objects
functions: [DrawBorder, DrawImage, PrintIText]
libraries: [intuition.library]
---

# 8 / Intuition Graphic Objects / Positioning Graphic Objects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The position of these objects is specified as the sum of two independent
components: an external component which gives the position of a base
reference point for the list of objects, and an internal component which
gives the relative offset of a specific object to the base reference point.

The external component is used to position the object list within the
display element.  For objects drawn indirectly by attaching them to a
menu, gadget or requester, this is always a point within the menu, gadget
or requester (the top left corner).

For objects drawn directly with the [DrawImage()](libraries/8-creating-images-directly-drawing-the-image.md), [DrawBorder()](libraries/8-creating-borders-directly-drawing-the-borders.md) or
[PrintIText()](libraries/8-creating-text-directly-drawing-the-intuitext.md) functions, specific x and y coordinates are provided as
arguments that specify an offset within the screen's or window's [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)
at which to display the list of objects.

Each object also has an internal, relative component that is added to the
external component described above to determine the final position of the
object.  This allows the application to reuse a graphical object and have
it appear relative to each object to which it is attached.  For example,
if the application has numerous gadgets of the same size, it can use a
single [Border](libraries/8-creating-borders-border-structure-definition.md) structure to draw lines around all the gadgets.  When the
gadgets are drawn, the base position of the lines will be taken from each
specific gadget in turn.

---

## See Also

- [DrawBorder — intuition.library](../autodocs/intuition.library.md#drawborder)
- [DrawImage — intuition.library](../autodocs/intuition.library.md#drawimage)
- [PrintIText — intuition.library](../autodocs/intuition.library.md#printitext)
