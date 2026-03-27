# 30 / / Types of Layers / Super Bitmap Layer


A super bitmap layer is similar to a [smart refresh](../Libraries_Manual_guide/node03E8.html) layer.  It too has a
back-up area for rendering graphics for currently obscured parts of the
display.  Whenever an obscured area is made visible, the corresponding
part of the backup area is copied to the display automatically.

However, it differs from [smart refresh](../Libraries_Manual_guide/node03E8.html) in that:

  * The back-up [BitMap](../Libraries_Manual_guide/node00F1.html#line4) is user-supplied, rather than being allocated

    dynamically by the system.
  * The back-up [BitMap](../Libraries_Manual_guide/node00F1.html#line4) may be as large or larger than the the current

    size of the layer. It may also be larger than the maximum size of the
    layer.
To see a larger portion of a super bitmap on-display, use [SizeLayer()](../Libraries_Manual_guide/node03EF.html#line17).  To
see a different portion of the super bitmap in the layer, use
[ScrollLayer()](../Libraries_Manual_guide/node03EF.html#line17).

When the graphics routines perform drawing commands, part of the drawing
appears in the common [BitMap](../Libraries_Manual_guide/node00F1.html#line4) (the on-display portion). Any drawing outside
the displayed portion itself is rendered into the super bitmap. When the
layer is scrolled or sized, the layer contents are copied into the super
bitmap, the scroll or size positioning is modified, and the appropriate
portions are then copied back into the layer. (Refer to the graphics
library functions [SyncSBitMap()](../Libraries_Manual_guide/node0120.html#line12) and [CopySBitMap()](../Libraries_Manual_guide/node0120.html#line26).

