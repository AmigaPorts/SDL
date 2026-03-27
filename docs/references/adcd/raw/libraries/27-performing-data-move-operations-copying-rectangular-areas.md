# 27 / / Performing Data Move Operations / Copying Rectangular Areas


Four routines use the blitter to copy rectangular areas from one section
of a [BitMap](../Libraries_Manual_guide/node032B.html#line74) to another: [BltBitMap()](../Includes_and_Autodocs_2._guide/node041F.html), [BltBitMapRastPort()](../Includes_and_Autodocs_2._guide/node0420.html),
[BltMaskBitMapRastPort()](../Includes_and_Autodocs_2._guide/node0422.html), and [ClipBlit()](../Includes_and_Autodocs_2._guide/node042D.html).  All four of these blitter
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
described above.  [BltBitMap()](../Includes_and_Autodocs_2._guide/node041F.html) is the basic blitter routine, moving data
from one [BitMap](../Libraries_Manual_guide/node032B.html#line74) to another.

[BltBitMap()](../Includes_and_Autodocs_2._guide/node041F.html) allows you to define a rectangle within a source [BitMap](../Libraries_Manual_guide/node032B.html#line74) and
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
32,768.  See the section on "[Determining Chip Versions](../Libraries_Manual_guide/node031D.html)" earlier in this
chapter to find out how to tell if the host system has ECS installed.

The minterm argument determines what logical operation to perform on the
rectangle data as bits are moved (described above).  The mask argument,
normally set to 0xff, specifies which bitplanes will be involved in the
blit operation and which will be ignored.  If a bit is set in the mask
byte, the corresponding bitplane is included.  The tempA argument applies
only to blits that overlap and, if non-NULL, points to Chip memory the
system will use for temporary storage during the blit.

[BltBitMapRastPort()](../Includes_and_Autodocs_2._guide/node0420.html) takes most of the same arguments as [BltBitMap()](../Includes_and_Autodocs_2._guide/node041F.html), but
its destination is a [RastPort](../Libraries_Manual_guide/node034A.html) instead of a [BitMap](../Libraries_Manual_guide/node032B.html#line74).  The syntax for the
function is:


```c
    VOID BltBitMapRastPort(&srcBM, srcX, srcY, &dstRP, dstX, dstY,
             sizeX, sizeY, minterm);
```
The arguments here are the same as for [BltBitMap()](../Includes_and_Autodocs_2._guide/node041F.html) above.  Note that the
[BltBitMapRastPort()](../Includes_and_Autodocs_2._guide/node0420.html) function will respect the [RastPort.Mask](../Libraries_Manual_guide/node034F.html) field.  Only
the planes specified in the Mask will be included in the operation.

A third type of blitter operation is provided by the
[BltMaskBitMapRastPort()](../Includes_and_Autodocs_2._guide/node0422.html) function.  This works the same as
[BltBitMapRastPort()](../Includes_and_Autodocs_2._guide/node0420.html) except that it takes one extra argument, a pointer to
a single bitplane mask of the same height and width as the source.  The
mask acts as a filter for the operation--a blit only occurs where the mask
plane is non-zero.  The syntax for the function is:


```c
    VOID BltMaskBitMapRastPort(&srcBM, srcX, srcY, &dstRP, dstX, dstY,
             sizeX, sizeY, minterm, bltmask);
```
The bltmask argument points to a word-aligned mask bitplane in Chip memory
with the same dimensions as the source bitmap.  Note that this function
ignores the [Mask](../Libraries_Manual_guide/node034F.html) field of the destination [RastPort](../Libraries_Manual_guide/node034A.html).

[ClipBlit()](../Includes_and_Autodocs_2._guide/node042D.html) takes most of the same arguments as the other blitter calls
described above but it works with source and destination [RastPort](../Libraries_Manual_guide/node034A.html)s and
their layers.  Before ClipBlit() moves data, it looks at the area from
which and to which the data is being copied (RastPorts, not [BitMap](../Libraries_Manual_guide/node032B.html#line74)s) and
determines if there are overlapping areas involved.  If so, it splits up
the overall operation into a number of bitmaps to move the data in the way
you request.  To call ClipBlit() use:


```c
    VOID ClipBlit(&srcRP, srcX, srcY, &dstRP, dstX, dstY, XSize, YSize,
                  minterm);
```
Since [ClipBlit()](../Includes_and_Autodocs_2._guide/node042D.html) respects the [Layer](../Libraries_Manual_guide/node03E4.html) of the source and destination
[RastPort](../Libraries_Manual_guide/node034A.html), it is the easiest blitter movement call to use with Intuition
windows.  The following code fragments show how to save and restore an
undo buffer using ClipBlit().


```c
    /* Save work rastport to an undo rastport */
    ClipBlit(&drawRP, 0, 0, &undoRP, 0, 0, areaWidth, areaHeight, 0xC0);

    /* restore undo rastport to work rastport */
    ClipBlit(&undoRP, 0, 0, &drawRP, 0, 0, areaWidth, areaHeight, 0xC0);
```
