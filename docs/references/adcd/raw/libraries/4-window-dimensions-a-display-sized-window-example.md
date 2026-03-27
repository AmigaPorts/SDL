# 4 / / Window Dimensions / A Display Sized Window Example


A full screen window is not always desirable.  If the user is working on a
large, scrolling screen, they may only want a window the size of the
visible display.  The following example calculates the visible area on a
screen and opens a window in that area.  The example assumes that the
screen display clip is as large or larger than text overscan (OSCAN_TEXT)
which is set by the user.  The window is opened in the text overscan area,
not within the actual display clip that is used for the screen.  Use
[QueryOverscan()](../Libraries_Manual_guide/node00F0.html#line76) to find the standard overscan rectangles (display clips)
for a screen.  Use the graphics library call [VideoControl()](../Libraries_Manual_guide/node0339.html#line15) to find the
true display clip of the screen (see the chapter on "[Graphics Primitives](../Libraries_Manual_guide/node0339.html)"
for more information on VideoControl()).  The ViewPortExtra structure
contains the display clip information.


```c
    About Screen Coordinates.
    -------------------------
    The screen's actual position may not exactly equal the coordinates
    given in the LeftEdge and TopEdge fields of the [Screen](../Libraries_Manual_guide/node00DE.html#line6)
    structure.  This is due to hardware constraints that limit the
    fineness of the positioning of the underlying constructs.  This may
    cause a window which is opened in the visible part of the screen to
    be incorrectly positioned by a small number of pixels in each
    direction.  See the discussion of the screen's LeftEdge and
    TopEdge in the "[Intuition Screens](../Libraries_Manual_guide/node00DD.html#line36)" chapter for more information.

     [visiblewindow.c](../Libraries_Manual_guide/node05BF.html) 
```
