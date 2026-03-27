---
title: 27 Graphics Primitives / Introduction
manual: libraries
chapter: libraries
section: 27-graphics-primitives-introduction
functions: []
libraries: []
---

# 27 Graphics Primitives / Introduction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This chapter describes the basic graphics functions available to Amiga
programmers.  It covers the graphics support structures, display routines
and drawing routines.  Many of the operations described in this section
are also performed by the Intuition software.  See the [Intuition](libraries/user-interface-libraries.md) chapters
for more information.

The Amiga supports several basic types of graphics routines: display
routines, drawing routines, sprites and animation.  These routines are
very versatile and allow you to define any combination of drawing and
display areas you may wish to use.

The first section of this chapter defines the display routines.  These
routines show you how to form and manipulate a display, including the
following aspects of display use:

  * How to query the graphics system to find out what type of video

    monitor is attached and which graphics modes can be displayed on
    it.
  * How to identify the memory area that you wish to have displayed.

  * How to position the display area window to show only a certain

    portion of a larger drawing area.
  * How to split the screen into as many vertically stacked slices

    as you wish.
  * How to determine which horizontal and vertical resolution modes

    to use.
  * How to determine the current correct number of pixels across and

    lines down for a particular section of the display.
  * How to specify how many color choices per pixel are to be

    available in a specific section of the display.
The later sections of the chapter explain all of the available modes of
drawing supported by the system software, including how to do the
following:

  * Reserve memory space for use by the drawing routines.

  * Define the colors that can be drawn into a drawing area.

  * Define the colors of the drawing pens (foreground pen,

```c
    background pen for patterns, and outline pen for area-fill
    outlines).
```
  * Define the pen position in the drawing area.

  * Drawing primitives; lines, rectangles, circles and ellipses.

  * Define vertex points for area-filling, and specify the area-fill

    color and pattern.
  * Define a pattern for patterned line drawing.

  * Change drawing modes.

  * Read or write individual pixels in a drawing area.

  * Copy rectangular blocks of drawing area data from one drawing

    area to another.
  * Use a template (predefined shape) to draw an object into a

    drawing area.
 [Components of a Display](libraries/27-introduction-components-of-a-display.md) 
 [Introduction To Raster Displays](libraries/27-introduction-introduction-to-raster-displays.md) 
 [Interlaced and Non-Interlaced Modes](libraries/27-introduction-interlaced-and-non-interlaced-modes.md) 
 [Low, High and Super-High Resolution Modes](libraries/27-introduction-low-high-and-super-high-resolution-modes.md) 
 [About ECS](libraries/27-introduction-about-ecs.md) 
 [Forming an Image](libraries/27-introduction-forming-an-image.md) 
 [Role of the Copper (Coprocessor)](libraries/27-introduction-role-of-the-copper-coprocessor.md) 

