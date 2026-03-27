# 3 Intuition Screens / Screen Data Structures


The Amiga uses [color registers](../Libraries_Manual_guide/node031E.html#line103) and [bitplane](../Libraries_Manual_guide/node031E.html#line33) organization as its internal
representation of display data.  Screens require a color table and display
raster memory for each bitplane.  This is the memory where imagery is
rendered and later translated by the hardware into the actual video
display.  This information is contained in data structures from the
Amiga's graphics library.

A [ViewPort](../Libraries_Manual_guide/node00F1.html#line4) is the main data structure used by the graphics library to
represent a screen.  Pointers to each of the screen's bitplanes are stored
in the graphics library [BitMap](../Libraries_Manual_guide/node00F1.html#line4) structure.  Color table information is
stored in a graphics structure called a [ColorMap](../Libraries_Manual_guide/node00F1.html#line4).  And the screen's
drawing and font information is stored in the [RastPort](../Libraries_Manual_guide/node00F1.html#line4) structure.

The graphics [RastPort](../Libraries_Manual_guide/node00F1.html#line4) structure is a general-purpose handle that the
graphics library uses for drawing operations.  Many Intuition drawing
functions also take a RastPort address as a parameter.  This makes sense
since the RastPort structure contains drawing variables as well as a
pointer to the [BitMap](../Libraries_Manual_guide/node00F1.html#line4) telling where to draw.  See the
"[Graphics Primitives](../Libraries_Manual_guide/node034A.html)" chapter for more information on these structures and
how they are used.

 [The Intuition Screen Data Structure](../Libraries_Manual_guide/node00DD.html)    [Other Screen Data Structures](../Libraries_Manual_guide/node00DE.html) 

