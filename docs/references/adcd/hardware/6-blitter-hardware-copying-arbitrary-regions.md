---
title: 6 Blitter Hardware / Copying Arbitrary Regions
manual: hardware
chapter: hardware
section: 6-blitter-hardware-copying-arbitrary-regions
functions: []
libraries: []
---

# 6 Blitter Hardware / Copying Arbitrary Regions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One of the most common uses of the blitter is to move arbitrary rectangles
of data from one bitplane to another, or to different positions within a
bitplane. These rectangles are usually on arbitrary bit coordinates, so
 [shifting](hardware/6-blitter-hardware-shifts-and-masks.md)  and  [masking](hardware/6-blitter-hardware-shifts-and-masks.md)  are necessary. There are further complications.
It may take several readings and some experimentation before everything in
this section can be understood.

A source image that spans only two words may, when copied with certain
 [shifts](hardware/6-blitter-hardware-shifts-and-masks.md) , span three words.  Our 23 pixel wide rectangle above, for
instance, when  [shifted](hardware/6-blitter-hardware-shifts-and-masks.md)  12 bits, will span three words. Alternatively, an
image spanning three words may fit in two for certain  [shifts](hardware/6-blitter-hardware-shifts-and-masks.md) .  Under all
such circumstances, the blit size should be set to the larger of the two
values, such that both source and destination will fit within the blit
size.  Proper  [masking](hardware/6-blitter-hardware-shifts-and-masks.md)  should be applied to mask out unwanted data.

Some general guidelines for copying an arbitrary region are as follows.

1. Use the A  [DMA channel](hardware/6-blitter-hardware-dma-channels.md) , disabled, preloaded with all ones and the
   appropriate  [mask](hardware/6-blitter-hardware-shifts-and-masks.md)  and  [shift values](hardware/6-blitter-hardware-shifts-and-masks.md) , to mask the  [cookie-cut](hardware/6-function-generator-designing-the-lf-control-byte-with.md)  function.
   Use the B channel to fetch the source data, the C channel to fetch
   the destination data, and the D channel to write the destination
   data.  Use the  [cookie-cut](hardware/6-function-generator-designing-the-lf-control-byte-with.md)  function $CA.

2. If  [shifting](hardware/6-blitter-hardware-shifts-and-masks.md) , always use ascending mode if bit shifting to the right,
   and use  [descending mode](hardware/6-blitter-hardware-descending-mode.md)  if bit shifting to the left.

   NOTE:
   -----
   These shifts are the shifts of the bit position of the leftmost edge
   within a word, rather than  [absolute shifts](hardware/6-blitter-hardware-shifts-and-masks.md) , as explained previously.

3. If the source and destination overlap, use ascending mode if the
   destination has a lower memory address (is higher on the display) and

```c
    [descending mode](hardware/6-blitter-hardware-descending-mode.md)  otherwise.
```
4. If the source spans more words than the destination, use the same
```c
    [shift](hardware/6-blitter-hardware-shifts-and-masks.md)  value for the A channel as for the source B channel and set the
```
   first and last word  [masks](hardware/6-blitter-hardware-shifts-and-masks.md)  as if they were masking the B source data.

5. If the destination spans more words than the source, use a  [shift](hardware/6-blitter-hardware-shifts-and-masks.md) 
   value of zero for the A channel and set the first and last word  [masks](hardware/6-blitter-hardware-shifts-and-masks.md) 
   as if they were masking the destination D data.

6. If the source and destination span the same number of words, use the
   A channel to  [mask](hardware/6-blitter-hardware-shifts-and-masks.md)  either the source, as in 4, or the destination, as
   in 5.

   Warning:
   --------
   Conditions 2 and 3 can be contradictory if, for instance, you are
   trying to move an image one pixel down and to the right.  In this
   case, we would want to use  [descending mode](hardware/6-blitter-hardware-descending-mode.md)  so our destination does
   not overwrite our source before we use the source, but we would want
   to use ascending mode for the right  [shift](hardware/6-blitter-hardware-shifts-and-masks.md) .  In some situations, it is
   possible to get around general guideline 2 above with clever  [masking](hardware/6-blitter-hardware-shifts-and-masks.md) .
   But occasionally just  [masking](hardware/6-blitter-hardware-shifts-and-masks.md)  the first or last word may not be
   sufficient; it may be necessary to mask more than 16 bits on one or
   the other end. In such a case, a mask can be built in memory for a
   single raster row, and the A  [DMA channel](hardware/6-blitter-hardware-dma-channels.md)  enabled to explicitly fetch
   this mask. By setting the A modulo value to the negative of the width
   of the mask, the mask will be repeatedly fetched for each row.

