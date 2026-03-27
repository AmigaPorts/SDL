---
title: 8 / Creating Text / Fonts
manual: libraries
chapter: libraries
section: 8-creating-text-fonts
functions: [IntuiTextLength, OpenDiskFont, OpenFont]
libraries: [diskfont.library, graphics.library, intuition.library]
---

# 8 / Creating Text / Fonts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The application may choose to specify the font used in rendering the
[IntuiText](libraries/8-creating-text-intuitext-structure.md), or it may choose to use the default font for the system.

To use the default font, set the [ITextFont](libraries/8-creating-text-intuitext-structure.md) field to NULL.  Some care must
be taken when using the default font.  When an [IntuiText](libraries/8-creating-text-intuitext-structure.md) object is
rendered and no font is specified, the text will be rendered in the font
set in the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).

If the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) font is NULL, the text will be rendered using
[GfxBase->DefaultFont](autodocs-2.0/includes-graphics-gfxbase-h.md).  Also, [IntuiTextLength()](libraries/8-creating-text-determining-text-length.md) always uses
GfxBase->DefaultFont when [ITextFont](libraries/8-creating-text-intuitext-structure.md) is NULL.  The application must have
open the graphics library in order to check the default font in GfxBase.
(See the [graphics library](libraries/29-graphics-library-and-text.md) chapter for more information.)

To use a specific font for this text, place a pointer to an initialized
[TextAttr](libraries/29-the-text-function-choosing-the-font.md) structure in the [ITextFont](libraries/8-creating-text-intuitext-structure.md) field.  Intuition will only use the
specified font if it is available through a call to the [OpenFont()](libraries/29-the-text-function-choosing-the-font.md)
routine.  To use a font from disk, the application must first open the
font using the [OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md) function.  For more information about using
fonts, see the "[Graphics Library and Text](libraries/29-the-text-function-choosing-the-font.md)" chapter in this manual.

---

## See Also

- [IntuiTextLength — intuition.library](../autodocs/intuition.library.md#intuitextlength)
- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
