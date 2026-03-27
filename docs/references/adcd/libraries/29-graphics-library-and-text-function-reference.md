---
title: 29 Graphics Library and Text / Function Reference
manual: libraries
chapter: libraries
section: 29-graphics-library-and-text-function-reference
functions: [AddFont, AskFont, AskSoftStyle, AvailFonts, ClearEOL, ClearScreen, CloseFont, DisposeFontContents, FontExtent, NewFontContents, NewScaledDiskFont, OpenDiskFont, OpenFont, RemFont, SetFont, SetSoftStyle, StripFont, Text, TextExtent, TextFit, TextLength]
libraries: [diskfont.library, graphics.library]
---

# 29 Graphics Library and Text / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following are brief descriptions of the Graphics and Diskfont library
functions that deal with text.  See the Amiga ROM Kernel Reference Manual:
Includes and Autodocs for details on each function call.


               Table 29-1: Graphics Library Text Functions
  _______________________________________________________________________
 |                                                                       |
 |      Function                  Description                            |
 |=======================================================================|
 |          [Text()](autodocs-2.0/graphics-library-text.md)  Render a text string to a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).                  |
 |       [SetFont()](autodocs-2.0/graphics-library-setfont.md)  Set a RastPort's font.                               |
 |       [AskFont()](autodocs-2.0/graphics-library-askfont.md)  Get the [TextAttr](libraries/29-the-text-function-choosing-the-font.md) for a RastPort's font.              |
 |      [OpenFont()](autodocs-2.0/graphics-library-openfont.md)  Open a font currently in the system font list.       |
 |     [CloseFont()](autodocs-2.0/graphics-library-closefont.md)  Close a font.                                        |
 |       [AddFont()](autodocs-2.0/graphics-library-addfont.md)  Add a font to the system list.                       |
 |       [RemFont()](autodocs-2.0/graphics-library-remfont.md)  Remove a font from the system list.                  |
 |     [StripFont()](autodocs-2.0/graphics-library-stripfont.md)  Remove the tf_Extension from a font (V36).           |
 |  [WeighTAMatch()](autodocs-2.0/graphics-library-weightamatch.md)  Get a measure of how well two fonts match (V36).     |
 |-----------------------------------------------------------------------|
 |   [ClearScreen()](autodocs-2.0/graphics-library-clearscreen.md)  Clear [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) from the current position to the end  |
 |                  of the RastPort.                                     |
 |      [ClearEOL()](autodocs-2.0/graphics-library-cleareol.md)  Clear RastPort from the current position to the end  |
 |                  of the line.                                         |
 |  [AskSoftStyle()](autodocs-2.0/graphics-library-asksoftstyle.md)  Get the soft style bits of a RastPort's font.        |
 |  [SetSoftStyle()](autodocs-2.0/graphics-library-setsoftstyle.md)  Set the soft style bits of a RastPort's font.        |
 |    [TextLength()](autodocs-2.0/graphics-library-textlength.md)  Determine the horizontal raster length of a text     |
 |                  string using the current RastPort settings.          |
 |    [TextExtent()](autodocs-2.0/graphics-library-textextent.md)  Determine the raster extent (along the X and Y axes) |
 |                  of a text string using the current RastPort settings |
 |                  (V36).                                               |
 |    [FontExtent()](autodocs-2.0/graphics-library-fontextent.md)  Fill in a [TextExtent](libraries/29-graphics-library-and-text-does-the-text-fit.md) structure with the bounding box |
 |                  for the characters in the specified font (V36).      |
 |       [TextFit()](autodocs-2.0/graphics-library-textfit.md)  Count the number of characters in a given string     |
 |                  that will fit into a given bounds, using the current |
 |                  RastPort settings (V36).                             |
 |_______________________________________________________________________|


               Table 29-2: Diskfont Library Text Functions
  _______________________________________________________________________
 |                                                                       |
 |           Function             Description                            |
 |=======================================================================|
 |           [AvailFonts()](autodocs-2.0/diskfont-library-availfonts.md)  Inquire which fonts are available from disk   |
 |                         and/or memory.                                |
 |      [NewFontContents()](autodocs-2.0/diskfont-library-newfontcontents.md)  Create a [FontContents](libraries/29-graphics-library-and-text-composition-of-a-bitmap-font.md) image for a font.       |
 |  [DisposeFontContents()](autodocs-2.0/diskfont-library-disposefontcontents.md)  Free the result from NewFontContents().       |
 |    [NewScaledDiskFont()](autodocs-2.0/diskfont-library-newscaleddiskfont.md)  Create a DiskFont scaled from another font    |
 |                         (V36).                                        |
 |         [OpenDiskFont()](autodocs-2.0/diskfont-library-opendiskfont.md)  Open a font, loading it from disk if          |
 |                         necessary.                                    |
 |_______________________________________________________________________|

---

## See Also

- [AddFont — graphics.library](../autodocs/graphics.library.md#addfont)
- [AskFont — graphics.library](../autodocs/graphics.library.md#askfont)
- [AskSoftStyle — graphics.library](../autodocs/graphics.library.md#asksoftstyle)
- [AvailFonts — diskfont.library](../autodocs/diskfont.library.md#availfonts)
- [ClearEOL — graphics.library](../autodocs/graphics.library.md#cleareol)
- [ClearScreen — graphics.library](../autodocs/graphics.library.md#clearscreen)
- [CloseFont — graphics.library](../autodocs/graphics.library.md#closefont)
- [DisposeFontContents — diskfont.library](../autodocs/diskfont.library.md#disposefontcontents)
- [FontExtent — graphics.library](../autodocs/graphics.library.md#fontextent)
- [NewFontContents — diskfont.library](../autodocs/diskfont.library.md#newfontcontents)
- [NewScaledDiskFont — diskfont.library](../autodocs/diskfont.library.md#newscaleddiskfont)
- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
- [RemFont — graphics.library](../autodocs/graphics.library.md#remfont)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
- [SetSoftStyle — graphics.library](../autodocs/graphics.library.md#setsoftstyle)
- [StripFont — graphics.library](../autodocs/graphics.library.md#stripfont)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
- [TextExtent — graphics.library](../autodocs/graphics.library.md#textextent)
- [TextFit — graphics.library](../autodocs/graphics.library.md#textfit)
- [TextLength — graphics.library](../autodocs/graphics.library.md#textlength)
