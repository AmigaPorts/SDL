---
title: 27 / / Forming a Basic Display / Preparing the ColorMap Structure
manual: libraries
chapter: libraries
section: 27-forming-a-basic-display-preparing-the-colormap-structure
functions: [GetColorMap, GetRGB4, LoadRGB4, SetRGB4, SetRGB4CM, VideoControl]
libraries: [graphics.library]
---

# 27 / / Forming a Basic Display / Preparing the ColorMap Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) is created, Copper instructions are generated to change the
current contents of each color register just before the topmost line of a
[ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) so that this ViewPort's color registers will be used for
interpreting its display.  To set the color registers you create a
[ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) for the ViewPort with [GetColorMap()](autodocs-2.0/graphics-library-getcolormap.md) and call [SetRGB4()](autodocs-2.0/graphics-library-setrgb4.md).  Here are
the steps used in 1.3 to initialize a ColorMap:


```c
    if( view.ColorMap=GetColorMap( 4L ) )
        LoadRGB4((&viewPort, colortable, 4);
```
Under Release 2, a [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) is attached to the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) -- usually along with
[DisplayInfo](autodocs-2.0/includes-graphics-displayinfo-h.md) and [ViewExtra](libraries/27-display-routines-and-structures-forming-a-basic-display.md) -- by calling the [VideoControl()](libraries/27-mode-specification-viewport-interface.md) function.


```c
    /*  RGB values for the four colors used.  */
    #define BLACK 0x000
    #define RED   0xf00
    #define GREEN 0x0f0
    #define BLUE  0x00f

    /*  Define some colors in an array of UWORDS.  */
    static UWORD colortable[] = { BLACK, RED, GREEN, BLUE };

    /* Fill the TagItem Data field with the address of the properly
       initialized (including ViewPortExtra) structure to be passed to
       VideoControl().                                                 */
    vc[0].ti_Data = (ULONG)viewPort;

    /* Init ColorMap.  2 planes deep, so 4 entries
       (2 raised to #planes power).                */
    if(cm = GetColorMap( 4L ) )
    {
        /* For applications that must be compatible with 1.3, replace  */
        /* the next 2 lines with: viewPort.ColorMap=cm;                */
        if( VideoControl( cm , vcTags ) )
            fail("Could not attach extended structures\n");

        /*  Change colors to those in colortable.  */
        LoadRGB4(&viewPort, colortable, 4);
    }


    The 4 Is For Bits, Not Entries.
    -------------------------------
    The 4 in the name [LoadRGB4()](autodocs-2.0/graphics-library-loadrgb4.md) refers to the fact that each of the red,
    green, and blue values in a color table entry consists of four bits.
    It has nothing to do with the fact that this particular color table
    contains four entries. The call [GetRGB4()](autodocs-2.0/graphics-library-getrgb4.md) returns the RGB value of a
    single entry of a [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md). [SetRGB4CM()](autodocs-2.0/graphics-library-setrgb4cm.md) allows individual control of
    the entries in the ColorMap before or after linking it into the
    [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).
```
The [LoadRGB4()](autodocs-2.0/graphics-library-loadrgb4.md) call above could be replaced with the following:


```c
    register USHORT entry;

    /*  Operate on the same four ColorMap entries as above.  */
    for (entry = 0; entry < 4; entry++)
        {
        /* Call SetRGB4CM() with the address of the ColorMap, the entry to
           be changed, and the Red, Green, and Blue values to be stored
           there.
        */
        SetRGB4CM(viewPort.ColorMap, entry,
        /* Extract the three color values from the one colortable entry. */
            ((colortable[entry] & 0x0f00) >> 8),
                ((colortable[entry] & 0x00f0) >> 4),
                    (colortable[entry] & 0x000f));
        }
```
Notice above how the four bits for each color are masked out and shifted
right to get values from 0 to 15.


```c
    WARNING!
    --------
    It is important to use only the standard system [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md)-related
    calls to access the ColorMap entries.  These calls will remain
    compatible with recent and future enhancements to the ColorMap
    structure.
```
You might need to specify more colors in the color map than you think. If
you use a [dual playfield](libraries/27-advanced-topics-creating-a-dual-playfield-display.md) display (covered later in this chapter) with a
depth of 1 for each of the two playfields, this means a total of four
colors (two for each playfield). However, because playfield 2 uses color
registers starting from number 8 on up when in dual-playfield mode, the
color map must be initialized to contain at least 10 entries. That is, it
must contain entries for colors 0 and 1 (for playfield 1) and color
numbers 8 and 9 (for playfield 2). Space for sprite colors must be
allocated as well. For Amiga system software version 1.3 and earlier, when
in doubt, allocate a [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md) with 32 entries, just in case.

---

## See Also

- [GetColorMap — graphics.library](../autodocs/graphics.library.md#getcolormap)
- [GetRGB4 — graphics.library](../autodocs/graphics.library.md#getrgb4)
- [LoadRGB4 — graphics.library](../autodocs/graphics.library.md#loadrgb4)
- [SetRGB4 — graphics.library](../autodocs/graphics.library.md#setrgb4)
- [SetRGB4CM — graphics.library](../autodocs/graphics.library.md#setrgb4cm)
- [VideoControl — graphics.library](../autodocs/graphics.library.md#videocontrol)
