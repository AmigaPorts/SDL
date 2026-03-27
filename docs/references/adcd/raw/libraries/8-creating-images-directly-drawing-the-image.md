# 8 / Creating Images / Directly Drawing the Image


As noted above, you use the [DrawImage()](../Includes_and_Autodocs_2._guide/node0210.html) call to directly draw an image
into a screen or window [RastPort](../Libraries_Manual_guide/node034A.html).


```c
    void DrawImage( struct RastPort *rp, struct Image *image,
                    long leftOffset, long topOffset );
```
The rp argument is a pointer to the [RastPort](../Libraries_Manual_guide/node034A.html) into which the image should
be drawn.  This RastPort may come from a Window or Screen structure.

The image argument is a pointer to the list of [Image](../Libraries_Manual_guide/node01BA.html) structures that are
to be rendered.  The list may contain a single Image structure.

The leftOffset and topOffset arguments are the external component, or the
base position, for this list of images.  The [LeftEdge](../Libraries_Manual_guide/node01BA.html#line17) and [TopEdge](../Libraries_Manual_guide/node01BA.html#line17) values
of each [Image](../Libraries_Manual_guide/node01BA.html) structure are added to these values to determine the final
position of each image.

Images may also be indirectly drawn by attaching them to gadgets, menus or
requesters when they are initialized.

