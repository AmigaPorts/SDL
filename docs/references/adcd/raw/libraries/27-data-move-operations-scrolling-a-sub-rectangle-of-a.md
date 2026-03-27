# 27 / / Data Move Operations / Scrolling a Sub-rectangle of a Raster


You can scroll a sub-rectangle of a raster in any direction--up, down,
left, right, or diagonally. To perform a scroll, you use the
[ScrollRaster()](../Includes_and_Autodocs_2._guide/node0473.html) routine and specify a dx and dy (delta-x, delta-y) by which
the rectangle image should be moved relative to the (0,0) location.

As a result of this operation, the data within the rectangle will become
physically smaller by the size of delta-x and delta-y, and the area
vacated by the data when it has been cropped and moved is filled with the
background color (color in [BgPen](../Libraries_Manual_guide/node0350.html#line6)). [ScrollRaster()](../Includes_and_Autodocs_2._guide/node0473.html) is affected by the [Mask](../Libraries_Manual_guide/node034F.html)
setting.

Here is the syntax of the [ScrollRaster()](../Includes_and_Autodocs_2._guide/node0473.html) function:


```c
    ScrollRaster(&rastPort, dx, dy, xmin, ymin, xmax, ymax);
```
The &rastPort argument is a pointer to a [RastPort](../Libraries_Manual_guide/node034A.html).  The dx and dy
arguments are the distances (positive, 0, or negative) to move the
rectangle.  The outer bounds of the sub-rectangle are defined by the xmin,
xmax, ymin and ymax arguments.

Here are some examples that scroll a sub-rectangle:


```c
    /* scroll up 2 */
    ScrollRaster(&rastPort, 0, 2, 10, 10, 50, 50);

    /* scroll right 1 */
    ScrollRaster(&rastPort, -1, 0, 10, 10, 50, 50);
```
When scrolling a Simple Refresh window (or other layered [RastPort](../Libraries_Manual_guide/node034A.html)),
[ScrollRaster()](../Includes_and_Autodocs_2._guide/node0473.html) scrolls the appropriate existing damage region.  Refer to
the "[Intuition Windows](../Libraries_Manual_guide/node0117.html)" chapter for an explanation of [Simple Refresh](../Libraries_Manual_guide/node011A.html)
windows and [damage regions](../Libraries_Manual_guide/node0118.html).

When scrolling a SuperBitMap window [ScrollRaster()](../Includes_and_Autodocs_2._guide/node0473.html) requires a properly
initialized TmpRas.  The TmpRas must be initialized to the size of one
bitplane with a width and height the same as the SuperBitMap, using the
technique described in the "[Area-Fill Information](../Libraries_Manual_guide/node034D.html)" section above.

If you are using a SuperBitMap [Layer](../Libraries_Manual_guide/node03E4.html), it is possible that the information
in the [BitMap](../Libraries_Manual_guide/node032B.html#line74) is not fully reflected in the layer and vice-versa.  Two
graphics calls, [CopySBitMap()](../Libraries_Manual_guide/node0120.html#line26) and [SyncSBitMap()](../Libraries_Manual_guide/node0120.html#line12), remedy these situations.
Again, refer to the "[Intuition Windows](../Libraries_Manual_guide/node011F.html)" chapter for more on this.

