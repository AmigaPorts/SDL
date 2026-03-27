---
title: 8 / Graphic Objects / Displaying Images, Borders and IntuiText
manual: libraries
chapter: libraries
section: 8-graphic-objects-displaying-images-borders-and-intuitext
functions: [DrawBorder, DrawImage, PrintIText]
libraries: [intuition.library]
---

# 8 / Graphic Objects / Displaying Images, Borders and IntuiText

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Images, Borders and IntuiText objects may be directly or indirectly
rendered into the display by the application.  The application can draw
these objects directly into windows or screens by using one of the
functions [DrawImage()](libraries/8-creating-images-directly-drawing-the-image.md), [DrawBorder()](libraries/8-creating-borders-directly-drawing-the-borders.md) or [PrintIText()](libraries/8-creating-text-directly-drawing-the-intuitext.md).  The application
supplies the appropriate pointer to a [Border](libraries/8-creating-borders-border-structure-definition.md), [Image](libraries/8-creating-images-image-structure.md) or [IntuiText](libraries/8-creating-text-intuitext-structure.md) structure
as an argument to the function, as well as position information and a
pointer to the correct [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).  These rendering functions are discussed
in more detail below.

The application can also draw these objects indirectly by attaching them
to a menu, gadget or requester.  As Intuition places these elements on the
display, it also renders the associated graphics.  The [Requester](libraries/7-intuition-requesters-and-alerts-requester-structure.md), [Gadget](libraries/5-intuition-gadgets-gadget-structure.md),
and [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) structures contain one or more fields reserved for rendering
information.  See the specific chapters on these items for information on
attaching graphical objects to them.

---

## See Also

- [DrawBorder — intuition.library](../autodocs/intuition.library.md#drawborder)
- [DrawImage — intuition.library](../autodocs/intuition.library.md#drawimage)
- [PrintIText — intuition.library](../autodocs/intuition.library.md#printitext)
