---
title: 3 Intuition Screens / Intuition Screens and the Graphics Library
manual: libraries
chapter: libraries
section: 3-intuition-screens-intuition-screens-and-the-graphics
functions: [GetRGB4, LoadRGB4, SetRGB4, SetRGB4CM, ViewAddress]
libraries: [graphics.library, intuition.library]
---

# 3 Intuition Screens / Intuition Screens and the Graphics Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As previously mentioned, an Intuition screen is related to a number of
underlying graphics library structures.




```c
         Table 3-8: Graphics Data Structures Used with Screens


    Structure Name  Description                   Defined in Include File
    --------------  -----------                   -----------------------
    View            Root structure of the            <graphics/[view.h](autodocs-2.0/includes-graphics-view-h.md)>
                    graphics display system

    ViewPort        The graphics structure that      <graphics/[view.h](autodocs-2.0/includes-graphics-view-h.md)>
                    corresponds to a screen

    BitMap          Contains size and pointers to    <graphics/[gfx.h](autodocs-2.0/includes-graphics-gfx-h.md)>
                    the screen's bit planes

    ColorMap        Contains size and pointer to     <graphics/[view.h](autodocs-2.0/includes-graphics-view-h.md)>
                    the screen's color table

    [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)        Holds drawing, pen and font    <graphics/[rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)>
                    settings and the BitMap
                    address
```
These data structures are unified in Intuition's [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure (which
also incorporates higher level Intuition constructs such as menus and
windows).  Here's a brief explanation of the graphics library structures
used with Intuition.

[View](autodocs-2.0/includes-graphics-view-h.md)

```c
    The View is the graphics structure that corresponds to the whole
    display, including all visible screens.  The system has just one
    View; it's what you see on the monitor.  The address of the View may
    be obtained from any screen by using [ViewAddress()](libraries/3-intuition-screens-function-reference.md).
```
[ViewPort](autodocs-2.0/includes-graphics-view-h.md)

```c
    The ViewPort is the underlying graphics structure corresponding to a
    screen.  Every screen has one ViewPort.  To get the address of the
    ViewPort from the [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md) structure, use (&my_screen-> ViewPort).
    From the ViewPort an application may obtain pointers to all the
    screen's bitplanes and to its color table.
```
[BitMap](autodocs-2.0/includes-graphics-gfx-h.md)

```c
    The BitMap structure contains pointers to all the bit planes (up to
    8) and their sizes.  For future compatibility, use
    (my_screen->RastPort.BitMap) to get the address of the BitMap from
    the screen rather than (&my_screen->BitMap).

    The BitMap.BytesPerRow field specifies the number of bytes that have
    been allocated for each raster line.  This may be larger than the
    screen width depending on display alignment restrictions.  Alignment
    restrictions may change.  Always use this variable, not a hard-coded
    value.
```
[ColorMap](autodocs-2.0/includes-graphics-view-h.md)

```c
    The ColorMap contains a pointer to the color table, an array of 32
    WORDs for the hardware color registers.  Use SetRGB4(), GetRGB4(),
    SetRGB4CM() and LoadRGB4() from the graphics library to access the
    color table.  Do not read or write it directly.
```
[RastPort](libraries/27-drawing-routines-the-rastport-structure.md)

```c
    A RastPort controls the graphics rendering to any display area (not
    just screens).  Screens have a RastPort to allow direct rendering
    into the screen.  Applications may find the RastPort address of a
    screen with (&my_screen->RastPort).  This generally is not useful
    since applications normally render into windows.
```
 [Changing Screen Colors](libraries/3-intuition-screens-and-graphics-library-changing-screen.md) 
 [Direct Screen Access](libraries/3-intuition-screens-and-the-graphics-library-direct-screen.md) 
 [Screen Functions That Integrate Intuition and Graphics](libraries/3-screen-functions-that-integrate-intuition-and-graphics.md) 
 [Limitations of the Graphics Subsystem](libraries/3-screens-and-graphics-lib-limitations-of-the-graphics.md) 

---

## See Also

- [GetRGB4 — graphics.library](../autodocs/graphics.library.md#getrgb4)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
- [SetRGB4CM — graphics.library](../autodocs/graphics.library.md#setrgb4cm)
- [ViewAddress — intuition.library](../autodocs/intuition.library.md#viewaddress)
