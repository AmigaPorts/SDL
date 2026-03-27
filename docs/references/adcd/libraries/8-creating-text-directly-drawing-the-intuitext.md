---
title: 8 / Creating Text / Directly Drawing the IntuiText
manual: libraries
chapter: libraries
section: 8-creating-text-directly-drawing-the-intuitext
functions: [PrintIText]
libraries: [intuition.library]
---

# 8 / Creating Text / Directly Drawing the IntuiText

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Use the [PrintIText()](autodocs-2.0/intuition-library-printitext.md) call to directly draw the text into the target
[RastPort](libraries/27-drawing-routines-the-rastport-structure.md) of a window or screen.


```c
    void PrintIText( struct RastPort *rp, struct IntuiText *iText,
                     long left, long top );
```
The rp argument is a pointer to the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) into which the text should be
drawn.  This RastPort can come from a [Window](libraries/4-intuition-windows-the-window-structure.md) or [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure.

The iText argument is a pointer to a list of [IntuiText](libraries/8-creating-text-intuitext-structure.md) structures which
are to be rendered.  The list may contain a single IntuiText structure.
If the font is not specified in the IntuiText structure, Intuition will
render the text using the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)'s font.

The left and top arguments give the external component, or base position
for this list of [IntuiText](libraries/8-creating-text-intuitext-structure.md) structures.  The [LeftEdge](libraries/8-creating-text-intuitext-structure.md) and [TopEdge](libraries/8-creating-text-intuitext-structure.md) values in
each IntuiText structure are added to these to determine the final
position of the text.

[IntuiText](libraries/8-creating-text-intuitext-structure.md) objects may also be drawn indirectly by attaching them to
gadgets, menus or requesters.

---

## See Also

- [PrintIText — intuition.library](../autodocs/intuition.library.md#printitext)
