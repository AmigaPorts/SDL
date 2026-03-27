---
title: 29 / The Text Function / Setting the Text Drawing Attributes
manual: libraries
chapter: libraries
section: 29-the-text-function-setting-the-text-drawing-attributes
functions: [SetAPen, SetBPen, SetDrMd, SetFont, Text]
libraries: [graphics.library]
---

# 29 / The Text Function / Setting the Text Drawing Attributes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In addition to [SetFont()](libraries/29-the-text-function-choosing-the-font.md), there are three rastport control functions that
set attributes for text rendering:


```c
    void SetAPen( struct RastPort *rp, ULONG pen );
    void SetBPen( struct RastPort *rp, ULONG pen );
    void SetDrMd( struct RastPort *rp, ULONG drawMode );
```
The color of the text depends upon the rastport's current drawing mode and
pen colors.  You set the draw mode with the [SetDrMd()](autodocs-2.0/graphics-library-setdrmd.md) function passing it
a pointer to a rastport and a drawing mode: [JAM1](libraries/27-the-rastport-structure-rastport-drawing-modes.md), [JAM2](libraries/27-the-rastport-structure-rastport-drawing-modes.md), [COMPLEMENT](libraries/27-the-rastport-structure-rastport-drawing-modes.md) or
[INVERSEID](libraries/27-the-rastport-structure-rastport-drawing-modes.md).

If the drawing mode is [JAM1](libraries/27-the-rastport-structure-rastport-drawing-modes.md), the text will be rendered in the
[RastPort.FgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md) color.  Wherever there is a set bit in the character's
bitmap image, [Text()](libraries/29-graphics-library-and-text-the-text-function.md) will set the corresponding bit in the rastport to the
FgPen color.  This is known as overstrike mode.  You set the FgPen color
with the [SetAPen()](libraries/27-the-rastport-structure-rastport-drawing-pens.md) function by passing it a pointer to the rastport and a
color number.

If the drawing mode is set to [JAM2](libraries/27-the-rastport-structure-rastport-drawing-modes.md), [Text()](libraries/29-graphics-library-and-text-the-text-function.md) will place the [FgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md) color as
in the [JAM1](libraries/27-the-rastport-structure-rastport-drawing-modes.md) mode, but it will also set the bits in the rastport to the
[RastPort.BgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md) color wherever there is a corresponding cleared bit in the
character's bitmap image.  Basically, this prints the character themselves
in the FgPen color and fills in the surrounding parts of the character
image with the BgPen color.   You set the BgPen color with the [SetBPen()](autodocs-2.0/graphics-library-setbpen.md)
function by passing it a pointer to the rastport and a color number.

If the drawing mode is [COMPLEMENT](libraries/27-the-rastport-structure-rastport-drawing-modes.md), for every bit set in the character's
bitmap image, the corresponding bits in the rastport (in all of the
rastport's bitplanes) will have their state reversed.  cleared bits in the
character's bitmap image have no effect on the destination rastport.  As
with the other drawing modes, the write mask can be used to protect
certain bitplanes from being modified (see the "[graphics primitives](libraries/27-the-rastport-structure-rastport-write-mask.md)"
chapter for more details).

The [JAM1](libraries/27-the-rastport-structure-rastport-drawing-modes.md), [JAM2](libraries/27-the-rastport-structure-rastport-drawing-modes.md), and [COMPLEMENT](libraries/27-the-rastport-structure-rastport-drawing-modes.md) drawing modes are mutually exclusive of
each other but each can be modified by the [INVERSVID](libraries/27-the-rastport-structure-rastport-drawing-modes.md) drawing mode.  If you
combine any of the drawing modes with INVERSVID, the Amiga will reverse
the state of all the bits in the source drawing area before writing
anything into the rastport.

The idea of using a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) structure to hold all the rendering
attributes is convenient if the rastport's drawing attributes aren't going
to change much.  This is not the case where several processes need to
render into a rastport using very different drawing attributes.  An easy
way around this problem is to clone the RastPort.  By making an exact
duplicate of a RastPort, you can change the various rendering parameters
of your RastPort without effecting other programs that render into the
RastPort you cloned.  Because a RastPort only contains a pointer to the
rendering area (the bitmap), the original RastPort and the cloned RastPort
both render into the bitmap, but they can use different drawing parameters
(font, drawing mode, colors, etc.).

---

## See Also

- [SetAPen — graphics.library](../autodocs/graphics.library.md#setapen)
- [SetBPen — graphics.library](../autodocs/graphics.library.md#setbpen)
- [SetDrMd — graphics.library](../autodocs/graphics.library.md#setdrmd)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
