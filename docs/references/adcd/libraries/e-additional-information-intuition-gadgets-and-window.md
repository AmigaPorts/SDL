---
title: E / Additional Information / Intuition Gadgets and Window Borders
manual: libraries
chapter: libraries
section: e-additional-information-intuition-gadgets-and-window
functions: [LockPubScreen, OpenWindow, PrintIText, SetFont, Text]
libraries: [graphics.library, intuition.library]
---

# E / Additional Information / Intuition Gadgets and Window Borders

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If 2.0 Intuition finds a gadget whose hit area ([Gadget](libraries/5-intuition-gadgets-gadget-structure.md) [LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md)/[TopEdge](libraries/5-intuition-gadgets-gadget-structure.md)/
[Width](libraries/5-intuition-gadgets-gadget-structure.md)/[Height](libraries/5-intuition-gadgets-gadget-structure.md)) is substantially inside the border, it will be treated as
though it was declared in the border.  This is called "bordersniffing".
Gadgets declared as being in the border or detected by Intuition as being
in the border are refreshed each time after the border is refreshed, and
thus aren't clobbered.

Noteworthy special cases:

 1) A gadget that has several pixels not in the border is not

```c
    bordersniffed. An example would be an 18-pixel high gadget in the
    bottom border of a [SIZEBBOTTOM](libraries/4-window-attributes-boolean-window-attribute-tags.md) window.  About half the gadget will be
    clobbered by the border rendering.
```
 2) A gadget that is not substantially in the border but has imagery that

    extends into the border cannot be sniffed out by Intuition.
 3) A gadget that is substantially in the border but has imagery that

```c
    extends into the main part of the window will be sniffed out as a
    border gadget, and this could change the refreshing results.  A
    common trick to put imagery in a window is to put a 1x1 or 0x0 dummy
    gadget at window location (0,0) and attach the window imagery to it.
    To support this, Intuition will never bordersniff gadgets of size 1x1
    or smaller.

    All these cases can be fixed by setting the appropriate
    GACT_xxxBORDER gadget [Activation](libraries/5-intuition-gadgets-gadget-structure.md) flag.
```
 4) In rare cases, buttons rendered with [Border](libraries/8-creating-borders-border-structure-definition.md) structures and [JAM1](libraries/8-creating-borders-border-structure-definition.md) text

    may appear invisible under Release 2.
The height of the window's title bar is affected by the current font
settings.  See the discussion of "[Screen Attributes](libraries/3-custom-screen-functions-screen-attributes.md)" in the "Intuition
Screens" chapter. To predict your window's titlebar height before you call
[OpenWindow()](libraries/4-basic-window-structures-and-functions-opening-a-window.md):


```c
    topborder = screen->WBorTop + screen->Font->ta_YSize + 1
```
The screen's font may not legally be changed after a screen is opened.

Be sure the screen cannot go away on you.  This is true if:


```c
    1) You opened the screen yourself.

    2) You currently have a window open on the screen.

    3) You currently hold a lock on this screen (see [LockPubScreen()](libraries/3-intuition-screens-public-screen-functions.md)).
```
[IntuiText](libraries/8-creating-text-intuitext-structure.md) rendered into a window (either through [PrintIText()](libraries/8-creating-text-directly-drawing-the-intuitext.md) or as a
gadget's [GadgetText](libraries/5-intuition-gadgets-gadget-structure.md)) defaults to the Window [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) font, but can be
overridden using its [ITextFont](libraries/8-creating-text-intuitext-structure.md) field.  Text rendered with the [Text()](libraries/29-graphics-library-and-text-the-text-function.md)
function appears in the Window RastPort font.

The Window's [RPort](libraries/4-intuition-windows-the-window-structure.md)'s font shown above is the initial font that Intuition
sets for you in your window's [RastPort](libraries/27-drawing-routines-the-rastport-structure.md). It is legal to change that
subsequently with [SetFont()](libraries/29-the-text-function-choosing-the-font.md).

---

## See Also

- [LockPubScreen — intuition.library](../autodocs/intuition.library.md#lockpubscreen)
- [OpenWindow — intuition.library](../autodocs/intuition.library.md#openwindow)
- [PrintIText — intuition.library](../autodocs/intuition.library.md#printitext)
- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
