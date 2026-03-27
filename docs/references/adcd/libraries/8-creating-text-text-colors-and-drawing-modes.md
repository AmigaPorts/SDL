---
title: 8 / Creating Text / Text Colors and Drawing Modes
manual: libraries
chapter: libraries
section: 8-creating-text-text-colors-and-drawing-modes
functions: []
libraries: []
---

# 8 / Creating Text / Text Colors and Drawing Modes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[IntuiText](libraries/8-creating-text-intuitext-structure.md) gets its colors from the values set in the color registers for
the screen in which they are rendered.  The available number of colors and
palette settings are screen attributes and cannot be changed through
IntuiText rendering.

Text characters in general are made up of two areas: the character image
itself and the background area surrounding the character image.  The color
used in each area is determined by the draw mode which can be set to [JAM1](libraries/8-creating-text-intuitext-structure.md),
[JAM2](libraries/8-creating-text-intuitext-structure.md) or [COMPLEMENT](libraries/8-creating-text-intuitext-structure.md).  The flag [INVERSVID](libraries/8-creating-text-intuitext-structure.md) may also be specified.

[JAM1](libraries/8-creating-text-intuitext-structure.md) draw mode renders each character with [FrontPen](libraries/8-creating-text-intuitext-structure.md) and leaves the
background area unaffected.  Because the background of a character is not
drawn, the pixels of the destination memory  around the character image
are not disturbed.  Graphics beneath the text will be visible in the
background area of each character cell.

[JAM2](libraries/8-creating-text-intuitext-structure.md) draw mode renders each character with [FrontPen](libraries/8-creating-text-intuitext-structure.md) and renders each
character background with [BackPen](libraries/8-creating-text-intuitext-structure.md).  Using this mode, any graphics that
previously appeared beneath the character cells will be totally
overwritten.

[COMPLEMENT](libraries/8-creating-text-intuitext-structure.md) draw mode renders the pixels of each character as the binary
complement of the color that is currently at the destination pixel.  The
destination is the display memory where the text is drawn.  As with [JAM1](libraries/8-creating-text-intuitext-structure.md),
nothing is drawn into the background.  [FrontPen](libraries/8-creating-text-intuitext-structure.md) and [BackPen](libraries/8-creating-text-intuitext-structure.md) are not used
in COMPLEMENT mode.  To determine the complement color, invert all the
bits in the binary representation of the color register number.  The
resulting number specifies the color register to use for that pixel.  In a
three bitplane display, for example, color 6 (110 in binary) is the
complement of color 1 (001 in binary).

The [INVERSVID](libraries/8-creating-text-intuitext-structure.md) flag inverses the video for each of the drawing modes.  For
[JAM1](libraries/8-creating-text-intuitext-structure.md), nothing is drawn into the character area and the background is drawn
in [FrontPen](libraries/8-creating-text-intuitext-structure.md).  For [JAM2](libraries/8-creating-text-intuitext-structure.md), the character area is drawn in [BackPen](libraries/8-creating-text-intuitext-structure.md) and the
background is drawn in FrontPen.  For [COMPLEMENT](libraries/8-creating-text-intuitext-structure.md) mode, nothing is drawn
into the character area and the background is complemented.

