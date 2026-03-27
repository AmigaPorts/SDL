---
title: 27 / / Performing Data Move Operations / Copying Rectangular Areas
manual: libraries
chapter: libraries
section: 27-performing-data-move-operations-copying-rectangular-areas
functions: [BltBitMap, BltBitMapRastPort, BltMaskBitMapRastPort, ClipBlit]
libraries: [graphics.library]
---

# 27 / / Performing Data Move Operations / Copying Rectangular Areas

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Four routines use the blitter to copy rectangular areas from one section
of a [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) to another: [BltBitMap()](autodocs-2.0/graphics-library-bltbitmap.md), [BltBitMapRastPort()](autodocs-2.0/graphics-library-bltbitmaprastport.md),
[BltMaskBitMapRastPort()](autodocs-2.0/graphics-library-bltmaskbitmaprastport.md), and [ClipBlit()](autodocs-2.0/graphics-library-clipblit.md).  All four of these blitter
routines take a special argument called a minterm.

The minterm variable is an unsigned byte value which represents an action
to be performed during the move.  Since all the blitter routines uses the
hardware blitter to move the data, they can take advantage of the
blitter's ability to logically combine or change the data as the move is
made.  The most common operation is a direct copy from source area to
destination, which uses a minterm set to hex value C0.

You can determine how to set the minterm variable by using the logic
equations shown in the following tables.  B represents data from the
source rectangle and C represents data in the destination area.




             Table 27-7: Minterm Logic Equations


            Leftmost 4 Bits    Logic Term Included
             of MinTermin         Final Output
             ------------         ------------
                  8                    BC  "B AND C"
                                        _
                  4                    BC  "B AND NOT C"
                                       _
                  2                    BC  "NOT B AND C"
                                       __
                  1                    BC  "NOT B AND NOT C"
You can combine values to select the logic terms.  For instance a minterm
value of 0xC0 selects the first two logic terms in the table above.  These
logic terms specify that in the final destination area you will have data
that occurs in source B only.  Thus, C0 means a direct copy.  The logic
equation for this is:

```c
          _         _
    BC + BC = B(C + C) = B
```
Logic equations may be used to decide on a number of different ways of
moving the data.  For your convenience, a few of the most common ones are
listed below.




```c
    Table 27-8: Some Common MinTerm Values to Use for Copying


    MinTerm
     Value        Logic Operation Performed During Copy
     -----        -------------------------------------
      30       Replace destination area with inverted source B.

      50       Replace destination area with an inverted version
               of itself.

      60       Put B where C is not, put C where B is not (cookie cut).

      80       Only put bits into destination where there is a bit in
               the same position for both source and destination (sieve
               operation).

      C0       Plain vanilla copy from source B to destination C.
```
The graphics library blitter routines all accept a minterm argument as
described above.  [BltBitMap()](autodocs-2.0/graphics-library-bltbitmap.md) is the basic blitter routine, moving data
from one [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) to another.

[BltBitMap()](autodocs-2.0/graphics-library-bltbitmap.md) allows you to define a rectangle within a source [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) and
copy it to a destination area of the same size in another (or even the
same) BitMap.  This routine is used by the graphics library itself for
rendering.  BltBitMap() returns the number of planes actually involved in
the blit.  The syntax for the function is:


```c
    ULONG planes;

    planes = BltBitMap(&srcBM, srcX, srcY, &dstBM, dstX, dstY,
                 sizeX, sizeY, minterm, mask, tempA);
```
The source bitmap is specified by the &srcBM argument.  The position of
the source area within the bitmap is specified by srcX and srcY.  The
destination bitmap is specified by the &dstBM argument.  The position of
the destination area within the bitmap is specified by dstX and dstY.

The dimensions (in pixels) of the area to be moved is indicated by the
sizeX and sizeY arguments.  With the original custom chip set, the blitter
size limits are 992 x 1024.  With ECS the blitter size limits are 32,736 x
32,768.  See the section on "[Determining Chip Versions](libraries/27-about-ecs-determining-chip-versions.md)" earlier in this
chapter to find out how to tell if the host system has ECS installed.

The minterm argument determines what logical operation to perform on the
rectangle data as bits are moved (described above).  The mask argument,
normally set to 0xff, specifies which bitplanes will be involved in the
blit operation and which will be ignored.  If a bit is set in the mask
byte, the corresponding bitplane is included.  The tempA argument applies
only to blits that overlap and, if non-NULL, points to Chip memory the
system will use for temporary storage during the blit.

[BltBitMapRastPort()](autodocs-2.0/graphics-library-bltbitmaprastport.md) takes most of the same arguments as [BltBitMap()](autodocs-2.0/graphics-library-bltbitmap.md), but
its destination is a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) instead of a [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md).  The syntax for the
function is:


```c
    VOID BltBitMapRastPort(&srcBM, srcX, srcY, &dstRP, dstX, dstY,
             sizeX, sizeY, minterm);
```
The arguments here are the same as for [BltBitMap()](autodocs-2.0/graphics-library-bltbitmap.md) above.  Note that the
[BltBitMapRastPort()](autodocs-2.0/graphics-library-bltbitmaprastport.md) function will respect the [RastPort.Mask](libraries/27-the-rastport-structure-rastport-write-mask.md) field.  Only
the planes specified in the Mask will be included in the operation.

A third type of blitter operation is provided by the
[BltMaskBitMapRastPort()](autodocs-2.0/graphics-library-bltmaskbitmaprastport.md) function.  This works the same as
[BltBitMapRastPort()](autodocs-2.0/graphics-library-bltbitmaprastport.md) except that it takes one extra argument, a pointer to
a single bitplane mask of the same height and width as the source.  The
mask acts as a filter for the operation--a blit only occurs where the mask
plane is non-zero.  The syntax for the function is:


```c
    VOID BltMaskBitMapRastPort(&srcBM, srcX, srcY, &dstRP, dstX, dstY,
             sizeX, sizeY, minterm, bltmask);
```
The bltmask argument points to a word-aligned mask bitplane in Chip memory
with the same dimensions as the source bitmap.  Note that this function
ignores the [Mask](libraries/27-the-rastport-structure-rastport-write-mask.md) field of the destination [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).

[ClipBlit()](autodocs-2.0/graphics-library-clipblit.md) takes most of the same arguments as the other blitter calls
described above but it works with source and destination [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)s and
their layers.  Before ClipBlit() moves data, it looks at the area from
which and to which the data is being copied (RastPorts, not [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md)s) and
determines if there are overlapping areas involved.  If so, it splits up
the overall operation into a number of bitmaps to move the data in the way
you request.  To call ClipBlit() use:


```c
    VOID ClipBlit(&srcRP, srcX, srcY, &dstRP, dstX, dstY, XSize, YSize,
                  minterm);
```
Since [ClipBlit()](autodocs-2.0/graphics-library-clipblit.md) respects the [Layer](libraries/30-layers-the-layer-structure.md) of the source and destination
[RastPort](libraries/27-drawing-routines-the-rastport-structure.md), it is the easiest blitter movement call to use with Intuition
windows.  The following code fragments show how to save and restore an
undo buffer using ClipBlit().


```c
    /* Save work rastport to an undo rastport */
    ClipBlit(&drawRP, 0, 0, &undoRP, 0, 0, areaWidth, areaHeight, 0xC0);

    /* restore undo rastport to work rastport */
    ClipBlit(&undoRP, 0, 0, &drawRP, 0, 0, areaWidth, areaHeight, 0xC0);
```

---

## See Also

- [BltBitMap — graphics.library](../autodocs/graphics.library.md#bltbitmap)
- [BltBitMapRastPort — graphics.library](../autodocs/graphics.library.md#bltbitmaprastport)
- [BltMaskBitMapRastPort — graphics.library](../autodocs/graphics.library.md#bltmaskbitmaprastport)
- [ClipBlit — graphics.library](../autodocs/graphics.library.md#clipblit)
