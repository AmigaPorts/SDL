# 27 Graphics Primitives / Display Routines and Structures




    CAUTION:
    --------
    This section describes the lowest-level graphics interface to the
    system hardware.  If you use any of the routines and the data
    structures described in these sections, your program will essentially
    take over the entire display.  In general, this is not compatible
    with Intuition's multiwindow operating environment since Intuition
    calls these low-level routines for you.
The descriptions of the display routines, as well as those of the drawing
routines, occasionally use the same terminology as that in the [Intuition](../Libraries_Manual_guide/node0002.html)
chapters.  These routines and data structures are the same ones that
Intuition software uses to produce its displays.

The computer produces a display from a set of instructions you define.
You organize the instructions as a set of parameters known as the [View](../Libraries_Manual_guide/node032B.html#line51)
structure (see the <graphics/[view.h](../Includes_and_Autodocs_2._guide/node00B8.html#line57)> include file for more information).
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
A complete display consists of one or more [ViewPort](../Libraries_Manual_guide/node032B.html#line59)s, whose display
sections are vertically separated from each other by at least one blank
scan line (non-interlaced). (If the system must make many changes to the
display during the transition from one ViewPort to the next, there may be
two or more blank scanlines between the ViewPorts.) The viewable area
defined by each ViewPort is rectangular. It may be only a portion of the
full ViewPort, it may be the full ViewPort, or it may be larger than the
full ViewPort, allowing it to be moved within the limits of its
[DisplayClip](../Includes_and_Autodocs_2._guide/node00B8.html#line76). You are essentially defining a display consisting of a number
of stacked rectangular areas in which separate sections of graphics
rasters can be shown.

 [Limitations on the Use of Viewports](../Libraries_Manual_guide/node0321.html) 
 [Characteristics of a Viewport](../Libraries_Manual_guide/node0322.html) 
 [Viewport Size Specifications](../Libraries_Manual_guide/node0323.html) 
 [Viewport Color Selection](../Libraries_Manual_guide/node0326.html) 
 [Viewport Display Modes](../Libraries_Manual_guide/node0327.html) 
 [Viewport Display Memory](../Libraries_Manual_guide/node032B.html) 
 [Forming a Basic Display](../Libraries_Manual_guide/node032C.html) 
 [Loading and Displaying the View](../Libraries_Manual_guide/node0333.html) 
 [Monitors, Modes and the Display Database](../Libraries_Manual_guide/node0335.html) 

