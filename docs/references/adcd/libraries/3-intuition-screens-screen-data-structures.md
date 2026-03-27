---
title: 3 Intuition Screens / Screen Data Structures
manual: libraries
chapter: libraries
section: 3-intuition-screens-screen-data-structures
functions: []
libraries: []
---

# 3 Intuition Screens / Screen Data Structures

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga uses [color registers](libraries/27-introduction-forming-an-image.md) and [bitplane](libraries/27-introduction-forming-an-image.md) organization as its internal
representation of display data.  Screens require a color table and display
raster memory for each bitplane.  This is the memory where imagery is
rendered and later translated by the hardware into the actual video
display.  This information is contained in data structures from the
Amiga's graphics library.

A [ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) is the main data structure used by the graphics library to
represent a screen.  Pointers to each of the screen's bitplanes are stored
in the graphics library [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure.  Color table information is
stored in a graphics structure called a [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).  And the screen's
drawing and font information is stored in the [RastPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure.

The graphics [RastPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) structure is a general-purpose handle that the
graphics library uses for drawing operations.  Many Intuition drawing
functions also take a RastPort address as a parameter.  This makes sense
since the RastPort structure contains drawing variables as well as a
pointer to the [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) telling where to draw.  See the
"[Graphics Primitives](libraries/27-drawing-routines-the-rastport-structure.md)" chapter for more information on these structures and
how they are used.

 [The Intuition Screen Data Structure](libraries/3-screen-data-structures-the-intuition-screen-data-structure.md)    [Other Screen Data Structures](libraries/3-screen-data-structures-other-screen-data-structures.md) 

