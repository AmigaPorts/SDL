---
title: 4 / / Window Dimensions / A Display Sized Window Example
manual: libraries
chapter: libraries
section: 4-window-dimensions-a-display-sized-window-example
functions: [QueryOverscan, VideoControl]
libraries: [graphics.library, intuition.library]
---

# 4 / / Window Dimensions / A Display Sized Window Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A full screen window is not always desirable.  If the user is working on a
large, scrolling screen, they may only want a window the size of the
visible display.  The following example calculates the visible area on a
screen and opens a window in that area.  The example assumes that the
screen display clip is as large or larger than text overscan (OSCAN_TEXT)
which is set by the user.  The window is opened in the text overscan area,
not within the actual display clip that is used for the screen.  Use
[QueryOverscan()](libraries/3-overscan-and-the-display-clip-preset-overscan-values.md) to find the standard overscan rectangles (display clips)
for a screen.  Use the graphics library call [VideoControl()](libraries/27-mode-specification-viewport-interface.md) to find the
true display clip of the screen (see the chapter on "[Graphics Primitives](libraries/27-mode-specification-viewport-interface.md)"
for more information on VideoControl()).  The ViewPortExtra structure
contains the display clip information.


```c
    About Screen Coordinates.
    -------------------------
    The screen's actual position may not exactly equal the coordinates
    given in the LeftEdge and TopEdge fields of the [Screen](libraries/3-screen-data-structures-other-screen-data-structures.md)
    structure.  This is due to hardware constraints that limit the
    fineness of the positioning of the underlying constructs.  This may
    cause a window which is opened in the visible part of the screen to
    be incorrectly positioned by a small number of pixels in each
    direction.  See the discussion of the screen's LeftEdge and
    TopEdge in the "[Intuition Screens](libraries/3-screen-data-structures-the-intuition-screen-data-structure.md)" chapter for more information.

     [visiblewindow.c](libraries/lib-examples-visiblewindow-c.md) 
```

---

## See Also

- [QueryOverscan — intuition.library](../autodocs/intuition.library.md#queryoverscan)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
