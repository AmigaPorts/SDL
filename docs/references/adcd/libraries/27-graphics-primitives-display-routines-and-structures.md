---
title: 27 Graphics Primitives / Display Routines and Structures
manual: libraries
chapter: libraries
section: 27-graphics-primitives-display-routines-and-structures
functions: []
libraries: []
---

# 27 Graphics Primitives / Display Routines and Structures

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    CAUTION:
    --------
    This section describes the lowest-level graphics interface to the
    system hardware.  If you use any of the routines and the data
    structures described in these sections, your program will essentially
    take over the entire display.  In general, this is not compatible
    with Intuition's multiwindow operating environment since Intuition
    calls these low-level routines for you.
The descriptions of the display routines, as well as those of the drawing
routines, occasionally use the same terminology as that in the [Intuition](libraries/user-interface-libraries.md)
chapters.  These routines and data structures are the same ones that
Intuition software uses to produce its displays.

The computer produces a display from a set of instructions you define.
You organize the instructions as a set of parameters known as the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md)
structure (see the <graphics/[view.h](autodocs-2.0/includes-graphics-view-h.md)> include file for more information).
The following figure shows how the system interprets the contents of a
View structure.  This drawing shows a complete display composed of two
different component parts, which could (for example) be a low-resolution,
multicolored part and a high-resolution, two-colored part.


                                VIDEO DISPLAY
                          _________________________
                         |                         |
                         |  _____________________  |
                         | |                     | |
                         | |                     | |
                         | |                     | |
                         | |     ViewPort #1     | |
                         | |                     | |   Background color
                         | |                     | | / shows here
                         | |_____________________| |/
                         |    _________________    /
                         |  /|                 |  /|
                         | / |                 | / |
                         |/  |                 |   |
                         /   |   ViewPort #2   |   |
                        /|   |                 |   |
     ViewPorts must be / |   |                 |   |
       seperated by at   |   |_________________|   |
  least one blank line   |                         |


```c
      (sometimes more).  |_________________________|

                        A complete display is composed
                          of one or more "ViewPorts"


            Figure 27-9: The Display Is Composed of ViewPorts
```
A complete display consists of one or more [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)s, whose display
sections are vertically separated from each other by at least one blank
scan line (non-interlaced). (If the system must make many changes to the
display during the transition from one ViewPort to the next, there may be
two or more blank scanlines between the ViewPorts.) The viewable area
defined by each ViewPort is rectangular. It may be only a portion of the
full ViewPort, it may be the full ViewPort, or it may be larger than the
full ViewPort, allowing it to be moved within the limits of its
[DisplayClip](autodocs-2.0/includes-graphics-view-h.md). You are essentially defining a display consisting of a number
of stacked rectangular areas in which separate sections of graphics
rasters can be shown.

 [Limitations on the Use of Viewports](libraries/27-display-routines-and-structures-limitations-on-use-of.md) 
 [Characteristics of a Viewport](libraries/27-display-routines-and-structures-characteristics-of-a.md) 
 [Viewport Size Specifications](libraries/27-display-routines-and-structures-viewport-size.md) 
 [Viewport Color Selection](libraries/27-display-routines-and-structures-viewport-color-selection.md) 
 [Viewport Display Modes](libraries/27-display-routines-and-structures-viewport-display-modes.md) 
 [Viewport Display Memory](libraries/27-display-routines-and-structures-viewport-display-memory.md) 
 [Forming a Basic Display](libraries/27-display-routines-and-structures-forming-a-basic-display.md) 
 [Loading and Displaying the View](libraries/27-display-routines-and-structures-loading-and-displaying.md) 
 [Monitors, Modes and the Display Database](libraries/27-routines-and-structures-monitors-modes-and-display.md) 

