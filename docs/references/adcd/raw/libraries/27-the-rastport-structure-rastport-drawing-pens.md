# 27 / / The RastPort Structure / RastPort Drawing Pens


The Amiga has three different drawing "pens" associated with the graphics
drawing routines.  These are:

  * [FgPen](../Libraries_Manual_guide/node034A.html#line14)--the foreground or primary drawing pen. For historical

    reasons, it is also called the A-Pen.
  * [BgPen](../Libraries_Manual_guide/node034A.html#line14)--the background or secondary drawing pen. For historical

    reasons, it is also called the B-Pen.
  * [AOlPen](../Libraries_Manual_guide/node034A.html#line14)--the area outline pen. For historical reasons, it is also

    called the O-Pen.
A drawing pen variable in the [RastPort](../Libraries_Manual_guide/node034A.html) contains the current value (range
0-255) for a particular color choice.  This value represents a color
register number whose contents are to be used in rendering a particular
type of image.  The effect of the pen value is dependent upon the drawing
mode and can be influenced by the pattern variables and the write mask as
described below. Always use the system calls (e.g. [SetAPen()](../Includes_and_Autodocs_2._guide/node0475.html)) to set the
different pens, never store values directly into the pen fields of the
RastPort.


```c
    Colors Repeat Beyond 31.
    ------------------------
    The Amiga 500/2000/3000 (with original chips or ECS) contains only
    32 color registers.  Any range beyond that repeats the colors in
    0-31. For example, pen numbers 32-63 refer to the colors in registers
    0-31 (except when you are using Extra-Half-Brite mode).
```
The graphics library drawing routines support [BitMap](../Libraries_Manual_guide/node032B.html#line74)s up to eight planes
deep allowing for future expansion of the Amiga hardware.

The color in FgPen is used as the primary drawing color for rendering
lines and areas. This pen is used when the drawing mode is [JAM1](../Libraries_Manual_guide/node0351.html#line2) (see the
[next section](../Libraries_Manual_guide/node0351.html) for drawing modes). JAM1 specifies that only one color is to
be "jammed" into the drawing area.

You establish the color for FgPen using the statement:


```c
    SetAPen(&rastPort, newcolor);
```
The color in BgPen is used as the secondary drawing color for rendering
lines and areas.  If you specify that the drawing mode is [JAM2](../Libraries_Manual_guide/node0351.html#line8) (jamming
two colors) and a pattern is being drawn, the primary drawing color
(FgPen) is used where there are 1s in the pattern. The secondary drawing
color (BgPen) is used where there are 0s in the pattern.

You establish the drawing color for BgPen using the statement:


```c
    SetBPen(&rastPort, newcolor);
```
The area outline pen AOlPen is used in two applications: area fill and
flood fill. (See "[Area Fill Operations](../Libraries_Manual_guide/node035C.html)" below.)  In area fill, you can
specify that an area, once filled, can be outlined in this AOlPen color.
In flood fill (in one of its operating modes) you can fill until the
flood-filler hits a pixel of the color specified in this pen variable.

You establish the drawing color for AOlPen using the statement:


```c
    SetOPen(&rastPort, newcolor);
```
