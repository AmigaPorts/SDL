# 27 / / Using the Graphics Drawing Routines / Rectangle-fill Operations


The final fill function, [RectFill()](../Includes_and_Autodocs_2._guide/node046D.html), is for filling rectangular areas.
The form of this function follows:


```c
    RectFill(&rastPort, xmin, ymin, xmax, ymax);
```
As usual, the rastPort argument specifies the [RastPort](../Libraries_Manual_guide/node034A.html) you want to draw
into.  The xmin and ymin arguments specify the upper left corner of the
rectangle to be filled. The xmax and ymax arguments specify the lower
right corner of the rectangle to be filled.  Note that the variable xmax
must be equal to or greater than xmin, and ymax must be equal to or
greater than ymin.

Rectangle-fill uses [FgPen](../Libraries_Manual_guide/node0350.html#line3), [BgPen](../Libraries_Manual_guide/node0350.html#line6), [AOlPen](../Libraries_Manual_guide/node0350.html#line9), [DrawMode](../Libraries_Manual_guide/node0351.html), [AreaPtrn](../Libraries_Manual_guide/node034A.html#line9) and [Mask](../Libraries_Manual_guide/node034F.html) to
fill the area you specify. Remember that the fill can be multicolored as
well as single- or two-colored.  When the DrawMode is [COMPLEMENT](../Libraries_Manual_guide/node0351.html#line17), it
complements all bit planes, rather than only those planes in which the
foreground is non-zero.

