# 3 Intuition Screens / Intuition Screens and the Graphics Library


As previously mentioned, an Intuition screen is related to a number of
underlying graphics library structures.




```c
         Table 3-8: Graphics Data Structures Used with Screens


    Structure Name  Description                   Defined in Include File
    --------------  -----------                   -----------------------
    View            Root structure of the            <graphics/[view.h](../Includes_and_Autodocs_2._guide/node00B8.html#line57)>
                    graphics display system

    ViewPort        The graphics structure that      <graphics/[view.h](../Includes_and_Autodocs_2._guide/node00B8.html#line40)>
                    corresponds to a screen

    BitMap          Contains size and pointers to    <graphics/[gfx.h](../Includes_and_Autodocs_2._guide/node00A6.html#line47)>
                    the screen's bit planes

    ColorMap        Contains size and pointer to     <graphics/[view.h](../Includes_and_Autodocs_2._guide/node00B8.html#line113)>
                    the screen's color table

    [RastPort](../Libraries_Manual_guide/node034A.html)        Holds drawing, pen and font    <graphics/[rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html#line55)>
                    settings and the BitMap
                    address
```
These data structures are unified in Intuition's [Screen](../Libraries_Manual_guide/node00DE.html#line6) structure (which
also incorporates higher level Intuition constructs such as menus and
windows).  Here's a brief explanation of the graphics library structures
used with Intuition.

[View](../Includes_and_Autodocs_2._guide/node00B8.html#line57)

```c
    The View is the graphics structure that corresponds to the whole
    display, including all visible screens.  The system has just one
    View; it's what you see on the monitor.  The address of the View may
    be obtained from any screen by using [ViewAddress()](../Libraries_Manual_guide/node00FD.html#line52).
```
[ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40)

```c
    The ViewPort is the underlying graphics structure corresponding to a
    screen.  Every screen has one ViewPort.  To get the address of the
    ViewPort from the [Screen](../Libraries_Manual_guide/node00DE.html#line6) structure, use (&my_screen-> ViewPort).
    From the ViewPort an application may obtain pointers to all the
    screen's bitplanes and to its color table.
```
[BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47)

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
[ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113)

```c
    The ColorMap contains a pointer to the color table, an array of 32
    WORDs for the hardware color registers.  Use SetRGB4(), GetRGB4(),
    SetRGB4CM() and LoadRGB4() from the graphics library to access the
    color table.  Do not read or write it directly.
```
[RastPort](../Libraries_Manual_guide/node034A.html)

```c
    A RastPort controls the graphics rendering to any display area (not
    just screens).  Screens have a RastPort to allow direct rendering
    into the screen.  Applications may find the RastPort address of a
    screen with (&my_screen->RastPort).  This generally is not useful
    since applications normally render into windows.
```
 [Changing Screen Colors](../Libraries_Manual_guide/node00F2.html) 
 [Direct Screen Access](../Libraries_Manual_guide/node00F3.html) 
 [Screen Functions That Integrate Intuition and Graphics](../Libraries_Manual_guide/node00F4.html) 
 [Limitations of the Graphics Subsystem](../Libraries_Manual_guide/node00F5.html) 

