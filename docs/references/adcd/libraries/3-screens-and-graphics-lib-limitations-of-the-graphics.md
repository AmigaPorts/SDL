---
title: 3 / Screens and Graphics Lib / Limitations of the Graphics Subsystem
manual: libraries
chapter: libraries
section: 3-screens-and-graphics-lib-limitations-of-the-graphics
functions: []
libraries: []
---

# 3 / Screens and Graphics Lib / Limitations of the Graphics Subsystem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If each of the visible screens does not have the same physical attributes,
it may not be possible to display the data in its proper screen mode.
Screen coercion is the technique that allows multiple screens with
differing physical attributes to be displayed simultaneously.  When a
coerced screen is visible, its aspect ratio and colors may appear
significantly changed.  This is normal and the screen will be displayed
correctly when it is the frontmost screen.

Hardware restrictions prevent certain types of displays.  For instance,
screens always use the full width of the display, regardless of the width
of the overscan rectangle.  This prevents any changes in display mode
within a video line.  Other modes, such as the VGA modes, require specific
revisions of the custom chips and may not be available on all machines.
See the "[Graphics Primitives](libraries/27-display-routines-and-structures-limitations-on-use-of.md)" chapter and the Amiga [Hardware](hardware/3-forming-basic-playfield-defining-the-size-of-the-display.md) Reference
Manual for more information on Amiga display organization and limitations.

