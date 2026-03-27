---
title: 3 / Intuition Screens and Graphics Library / Changing Screen Colors
manual: libraries
chapter: libraries
section: 3-intuition-screens-and-graphics-library-changing-screen
functions: [LoadRGB4, SetRGB4, SetRGB4CM]
libraries: [graphics.library]
---

# 3 / Intuition Screens and Graphics Library / Changing Screen Colors

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Screen colors are set at the time the screen is opened with the [SA_Colors](libraries/3-custom-screen-functions-screen-attributes.md)
tag.  If the colors need to be changed after the screen is opened, the
graphics library function, LoadRGB4() should be used.  To change a single
entry in the color table, use SetRGB4() and SetRGB4CM().  See the
"[Graphics Primitives](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md)" chapter for more information on these functions.

---

## See Also

- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
- [SetRGB4CM — graphics.library](../autodocs/graphics.library.md#setrgb4cm)
