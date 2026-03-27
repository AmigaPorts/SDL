---
title: 3 / DrawInfo and the 3D Look / The Font Specification in DrawInfo
manual: libraries
chapter: libraries
section: 3-drawinfo-and-the-3d-look-the-font-specification-in
functions: []
libraries: []
---

# 3 / DrawInfo and the 3D Look / The Font Specification in DrawInfo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Font information for a screen comes from a number of different places.

[SA_Font](libraries/3-custom-screen-functions-screen-attributes.md)

```c
    The application may specify the font to be used in a screen by
    providing the SA_Font tag with a [TextAttr](libraries/29-the-text-function-choosing-the-font.md) structure.  In this case,
    the font will be used by the screen and will be the default font for
    the [RastPort](libraries/4-intuition-windows-basic-window-structures-and-functions.md) of any window opening in the screen.
```
[SA_SysFont](libraries/3-custom-screen-functions-screen-attributes.md), 0

```c
    If the application requests the user's preferred monospace font, it
    is taken from [GfxBase->DefaultFont](autodocs-2.0/includes-graphics-gfxbase-h.md).  Any window's [RastPorts](libraries/4-intuition-windows-basic-window-structures-and-functions.md) are also
    initialized to use this same font.
```
SA_SysFont, 1

```c
    The screen font selected by the user from the Preferences font editor
    may be used for the screen by using the SA_SysFont tag.  This font,
    the "preferred screen font", may be proportional.  For compatibility
    reasons, if this font is specified for the screen, the window's
    [RastPort](libraries/4-intuition-windows-basic-window-structures-and-functions.md) will be initialized to [GfxBase->DefaultFont](autodocs-2.0/includes-graphics-gfxbase-h.md) (a
    non-proportional font).
```
To access information on an open screen's font, the application may
reference [Screen.Font](libraries/3-screen-data-structures-the-intuition-screen-data-structure.md) or [DrawInfo.dri_Font](libraries/3-intuition-screens-drawinfo-and-the-3d-look.md).  These fonts are identical,
the [DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) structure simply provides an alternate method of accessing
the information.  Note that Screen.Font is a pointer to a [TextAttr](libraries/29-the-text-function-choosing-the-font.md)
structure and that DrawInfo.dri_Font is a pointer to a [TextFont](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md) structure.
The application may use whichever form is best suited to its requirements.

It is illegal to change the screen's font after the screen is opened.
This means that the font specified in the [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) and [DrawInfo](libraries/3-screen-data-structures-other-screen-data-structures.md) structures
is guaranteed to remain open as long is the screen is open.

The menu bar, window titles, menu items, and the contents of a string
gadget all use the screen's font.  The font used for menu items can be
overridden in the menu item's [IntuiText](libraries/8-creating-text-intuitext-structure.md) structure.  Under V36 and higher,
the font used in a string gadget can be overridden through the
[StringExtend](libraries/5-string-gadget-type-extended-string-gadgets.md) structure.  The font of the menu bar and window titles cannot
be overridden.

For more information on screen fonts, see the description of the [SA_Font](libraries/3-custom-screen-functions-screen-attributes.md)
and [SA_SysFont](libraries/3-custom-screen-functions-screen-attributes.md) tags in the "Screen Attributes" section above.

