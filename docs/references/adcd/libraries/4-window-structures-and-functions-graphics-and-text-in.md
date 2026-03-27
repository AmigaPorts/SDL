---
title: 4 / Window Structures and Functions / Graphics and Text in Windows
manual: libraries
chapter: libraries
section: 4-window-structures-and-functions-graphics-and-text-in
functions: [SetFont]
libraries: [graphics.library]
---

# 4 / Window Structures and Functions / Graphics and Text in Windows

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Applications can call functions in both the graphics library and the
Intuition library to render images, lines, text and other graphic elements
in windows.  The graphics library provides primitive operations such as
area fill, line drawing, text and animation.

The number of colors and the palette available in a window are defined by
the screen in which the window opens.  Applications should never change
the palette of a screen unless the screen is a custom screen created by
the application.

Graphics rendered into the window should respect the drawing pens defined
for the screen.  See the section on "[DrawInfo and the 3D Look](libraries/3-drawinfo-and-the-3d-look-the-pen-specification-in-drawinfo.md)" in the
"Intuition Screens" chapter for more information.

Default window fonts come from one of two places, depending on the screen
on which the window opens.  The window title font is always taken from the
screen font.  If the screen is opened with a font specified, either by
specifying the tag [SA_Font](libraries/3-custom-screen-functions-screen-attributes.md) or the variable [NewScreen](libraries/3-screen-data-structures-other-screen-data-structures.md).Font, then
[Window.RPort](libraries/4-intuition-windows-the-window-structure.md)->Font is taken from the screen's font.  Otherwise, the
window's rastport's font is taken from [GfxBase->DefaultFont](autodocs-2.0/includes-graphics-gfxbase-h.md). This
information is available to the application if it opened the screen.

If the application did not open the screen, it has no way of knowing which
font has been used for the window.  Applications that require to know the
window's font before the window is open must explicitly set the font
(using [SetFont()](libraries/29-the-text-function-choosing-the-font.md)) for that window after opening it.  In this case, the
application may use any font it desires.  It is recommended that
applications use the screen's font if they support proportional fonts, and
[GfxBase->DefaultFont](autodocs-2.0/includes-graphics-gfxbase-h.md) otherwise, as these fonts are generally the user's
preference.

Intuition also provides a minimal high level interface to some of the
functions in the Graphics library.  This includes calls to draw lines,
text and images.  See the chapter entitled
"[Intuition Images, Line Drawing and Text](libraries/8-intuition-images-line-drawing-and-text.md)," for more information about
using Intuition to render graphics.

---

## See Also

- [SetFont — graphics.library](../autodocs/graphics.library.md#setfont)
