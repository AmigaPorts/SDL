---
title: 27 Graphics Primitives / Drawing Routines
manual: libraries
chapter: libraries
section: 27-graphics-primitives-drawing-routines
functions: []
libraries: []
---

# 27 Graphics Primitives / Drawing Routines

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Most of the graphics drawing routines require information about how the
drawing is to take place.  For this reason, most graphics drawing routines
use a data structure called a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md), that contains pointers to the
drawing area and drawing variables such as the current pen color and font
to use.  In general, you pass a pointer to your RastPort structure as an
argument whenever you call a drawing function.

 [The RastPort Structure](libraries/27-drawing-routines-the-rastport-structure.md) 
 [Using the Graphics Drawing Routines](libraries/27-drawing-routines-using-the-graphics-drawing-routines.md) 
 [Performing Data Move Operations](libraries/27-drawing-routines-performing-data-move-operations.md) 

