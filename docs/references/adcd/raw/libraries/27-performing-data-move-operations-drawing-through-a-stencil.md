# 27 / / Performing Data Move Operations / Drawing through a Stencil


The routine [BltPattern()](../Includes_and_Autodocs_2._guide/node0423.html) allows you to change only a very selective
portion of a drawing area. Basically, this routine lets you define a
rectangular region to be affected by a drawing operation and a mask of the
same size that further defines which pixels within the rectangle will be
affected.

The figure below shows an example of what you can do with [BltPattern()](../Includes_and_Autodocs_2._guide/node0423.html).




```c
                   · = 0 bits    o & # = 1 bits


         Mask contains                   Drawing area contains:

         · · o · o · ·                       · · · · · · ·
         · · o · o · ·                       · # # # # # ·
         · · o · o · ·                       # · · · · · ·
         · · o · o · ·                       · # # # # # ·
         · · o · o · ·                       · · · · · · #
         · · o · o · ·                       · # # # # # ·
         · · o · o · ·                       · · · · · · ·

                       \                   /
                        \                 /
                         \               /

                           · · o · o · ·
                           · # o # o # ·
                           # · o · o · ·
                           · # o # o # ·
                           · · o · o · #
                           · # o # o # ·
                           · · o · o · ·

                      Result of BitPattern():


         Figure 27-17: Example of Drawing Through a Stencil
```
In the resulting drawing, the lighter squares show where the target
drawing area has been affected.  Exactly what goes into the drawing area
when the mask has 1's is determined by your [RastPort](../Libraries_Manual_guide/node034A.html)'s [FgPen](../Libraries_Manual_guide/node0350.html#line3), [BgPen](../Libraries_Manual_guide/node0350.html#line6),
[DrawMode](../Libraries_Manual_guide/node0351.html) and [AreaPtrn](../Libraries_Manual_guide/node034A.html#line9) fields.

You call [BltPattern()](../Includes_and_Autodocs_2._guide/node0423.html) with:


```c
    BltPattern(&rastport, mask, xl, yl, maxx, maxy, bytecnt)
```
The &rastport argument specifies the [RastPort](../Libraries_Manual_guide/node034A.html) to use.  The operation will
be confined to a rectangular area within the RastPort specified by xl and
yl (upper right corner of the rectangle) and maxx and maxy (lower right
corner of the rectangle).

The mask is a pointer to the mask to use.  This can be NULL, in which case
a simple rectangular region is modified.  Or it can be set to the address
of a byte pattern which allows any arbitrary shape within the rectangle to
be defined.  The bytecount is the number of bytes per row for the mask (it
must be an even number of bytes).

The mask parameter is a rectangularly organized, contiguously stored
pattern.  This means that the pattern is stored in sequential memory
locations stored as (maxy - yl + 1) rows of bytecnt bytes per row.  These
patterns must obey the same rules as [BitMap](../Libraries_Manual_guide/node032B.html#line74)s.  This means that they must
consist of an even number of bytes per row and must be stored in memory
beginning at a legal word address. (The mask for [BltPattern()](../Includes_and_Autodocs_2._guide/node0423.html) does not
have to be in Chip RAM, though.)

