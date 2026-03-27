---
title: 8 / Creating Borders / Border Colors and Drawing Modes
manual: libraries
chapter: libraries
section: 8-creating-borders-border-colors-and-drawing-modes
functions: []
libraries: []
---

# 8 / Creating Borders / Border Colors and Drawing Modes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Borders can select their colors from the values set in the color registers
for the screen in which they are rendered.  The available number of colors
and palette settings are screen attributes and may not be changed through
border rendering.

Two drawing modes pertain to border lines: [JAM1](libraries/8-creating-borders-border-structure-definition.md) and [COMPLEMENT](libraries/8-creating-borders-border-structure-definition.md).  To draw
the line in a specific color, use the JAM1 draw mode.  This mode converts
each pixel in the line to the color set in the [FrontPen](libraries/8-creating-borders-border-structure-definition.md) field.

Selecting the [COMPLEMENT](libraries/8-creating-borders-border-structure-definition.md) draw mode causes the line to be drawn in an
exclusive-or mode that inverts the color of each pixel within the line.
The data bits of the pixel are changed to their binary complement.  This
complement is formed by reversing all bits in the binary representation of
the color register number.  In a three bitplane display, for example,
color 6 is 110 in binary. In COMPLEMENT draw mode, if a pixel is color 6,
it will be changed to the 001 (binary), which is color 1.  Note that a
border drawn in COMPLEMENT mode can be removed from a static display by
drawing the border again in the same position.

