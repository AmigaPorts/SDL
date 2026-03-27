# 6 Blitter Hardware / Copying Arbitrary Regions


One of the most common uses of the blitter is to move arbitrary rectangles
of data from one bitplane to another, or to different positions within a
bitplane. These rectangles are usually on arbitrary bit coordinates, so
 [shifting](../Hardware_Manual_guide/node011F.html)  and  [masking](../Hardware_Manual_guide/node011F.html#line42)  are necessary. There are further complications.
It may take several readings and some experimentation before everything in
this section can be understood.

A source image that spans only two words may, when copied with certain
 [shifts](../Hardware_Manual_guide/node011F.html) , span three words.  Our 23 pixel wide rectangle above, for
instance, when  [shifted](../Hardware_Manual_guide/node011F.html)  12 bits, will span three words. Alternatively, an
image spanning three words may fit in two for certain  [shifts](../Hardware_Manual_guide/node011F.html) .  Under all
such circumstances, the blit size should be set to the larger of the two
values, such that both source and destination will fit within the blit
size.  Proper  [masking](../Hardware_Manual_guide/node011F.html#line42)  should be applied to mask out unwanted data.

Some general guidelines for copying an arbitrary region are as follows.

1. Use the A  [DMA channel](../Hardware_Manual_guide/node011B.html) , disabled, preloaded with all ones and the
   appropriate  [mask](../Hardware_Manual_guide/node011F.html#line42)  and  [shift values](../Hardware_Manual_guide/node011F.html) , to mask the  [cookie-cut](../Hardware_Manual_guide/node011D.html#line83)  function.
   Use the B channel to fetch the source data, the C channel to fetch
   the destination data, and the D channel to write the destination
   data.  Use the  [cookie-cut](../Hardware_Manual_guide/node011D.html#line83)  function $CA.

2. If  [shifting](../Hardware_Manual_guide/node011F.html) , always use ascending mode if bit shifting to the right,
   and use  [descending mode](../Hardware_Manual_guide/node0120.html)  if bit shifting to the left.

   NOTE:
   -----
   These shifts are the shifts of the bit position of the leftmost edge
   within a word, rather than  [absolute shifts](../Hardware_Manual_guide/node011F.html) , as explained previously.

3. If the source and destination overlap, use ascending mode if the
   destination has a lower memory address (is higher on the display) and

```c
    [descending mode](../Hardware_Manual_guide/node0120.html)  otherwise.
```
4. If the source spans more words than the destination, use the same
```c
    [shift](../Hardware_Manual_guide/node011F.html)  value for the A channel as for the source B channel and set the
```
   first and last word  [masks](../Hardware_Manual_guide/node011F.html#line42)  as if they were masking the B source data.

5. If the destination spans more words than the source, use a  [shift](../Hardware_Manual_guide/node011F.html) 
   value of zero for the A channel and set the first and last word  [masks](../Hardware_Manual_guide/node011F.html#line42) 
   as if they were masking the destination D data.

6. If the source and destination span the same number of words, use the
   A channel to  [mask](../Hardware_Manual_guide/node011F.html#line42)  either the source, as in 4, or the destination, as
   in 5.

   Warning:
   --------
   Conditions 2 and 3 can be contradictory if, for instance, you are
   trying to move an image one pixel down and to the right.  In this
   case, we would want to use  [descending mode](../Hardware_Manual_guide/node0120.html)  so our destination does
   not overwrite our source before we use the source, but we would want
   to use ascending mode for the right  [shift](../Hardware_Manual_guide/node011F.html) .  In some situations, it is
   possible to get around general guideline 2 above with clever  [masking](../Hardware_Manual_guide/node011F.html#line42) .
   But occasionally just  [masking](../Hardware_Manual_guide/node011F.html#line42)  the first or last word may not be
   sufficient; it may be necessary to mask more than 16 bits on one or
   the other end. In such a case, a mask can be built in memory for a
   single raster row, and the A  [DMA channel](../Hardware_Manual_guide/node011B.html)  enabled to explicitly fetch
   this mask. By setting the A modulo value to the negative of the width
   of the mask, the mask will be repeatedly fetched for each row.

