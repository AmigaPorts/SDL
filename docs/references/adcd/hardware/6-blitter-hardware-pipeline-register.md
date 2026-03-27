---
title: 6 Blitter Hardware / Pipeline Register
manual: hardware
chapter: hardware
section: 6-blitter-hardware-pipeline-register
functions: []
libraries: []
---

# 6 Blitter Hardware / Pipeline Register

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The blitter performs many operations in each cycle --  [shifting](hardware/6-blitter-hardware-shifts-and-masks.md)  and
 [masking](hardware/6-blitter-hardware-shifts-and-masks.md)  source words, logical combination of sources, and  [area fill](hardware/6-blitter-hardware-area-fill-mode.md) 
and zero detect on the output.  To enable so many things to take place so
quickly, the blitter is pipelined. This means that rather than performing
all of the above operations in one blitter cycle, the operations are
spread over two blitter cycles. (Here "cycle" is used very loosely for
simplicity.) To clarify this, the blitter can be imagined as two chips
connected in series. Every cycle, a new set of source operations come in,
and the first chip performs its operations on the data.  It then passes
the half-processed data to the second chip to be finished during the next
cycle, when the first chip will be busy at work on the next set of data.
Each set of data takes two "cycles" to get through the two chips,
overlapped so a set of data can be pumped through each cycle.

What all this means is that the first two sets of sources are fetched
before the first destination is written.  This allows you to  [shift](hardware/6-blitter-hardware-shifts-and-masks.md)  a
bitmap up to one word to the right using ascending mode, for instance,
even though normally parts of the destination would be overwritten before
they were fetched.


```c
    USE Code
       in        Active
    [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md)     Channels             Cycle Sequence
```
   ---------    --------             --------------


       F        A B C D     A0 B0 C0 -  A1 B1 C1 D0 A2 B2 C2 D1 D2
       E        A B C       A0 B0 C0 A1 B1 C1 A2 B2 C2
       D        A B   D     A0 B0 -  A1 B1 D0 A2 B2 D1 -  D2
       C        A B         A0 B0 -  A1 B1 -  A2 B2
       B        A   C D     A0 C0 -  A1 C1 D0 A2 C2 D1 -  D2
       A        A   C       A0 C0 A1 C1 A2 C2
       9        A     D     A0 -  A1 D0 A2 D1 -  D2
       8        A           A0 -  A1 -  A2
       7          B C D     B0 C0 -  -  B1 C1 D0 -  B2 C2 D1 -  D2
       6          B C       B0 C0 -  B1 C1 -  B2 C2
       5          B   D     B0 -  -  B1 D0 -  B2 D1 -  D2
       4          B         B0 -  -  B1 -  -  B2
       3            C D     C0 -  -  C1 D0 -  C2 D1 -  D2
       2            C       C0 -  C1 -  C2
       1              D     D0 -  D1 -  D2
       0         none       -  -  -  -


       Table 6-2: Typical Blitter Cycle Sequence
Here are a few caveats to keep in mind about Table 6-2.

*  No fill.
*  No competing bus activity.
*  Three-word blit.
*  Typical operation involves fetching all sources twice before the
   first destination becomes available. This is due to internal
   pipelining. Care must be taken with overlapping source and
   destination regions.

   Warning:
   --------
   This Table is only meant to be an illustration of the typical order
   of blitter cycles on the bus. Bus cycles are dynamically allocated
   based on blitter operating mode; competing bus activity from
   processor, bitplanes, and other  [DMA channels](hardware/6-blitter-hardware-dma-channels.md) ; and other factors.
   Amiga, Inc. does not guarantee the accuracy of or future
   adherence to this chart. We reserve the right to make product
   improvements or design changes in this area without notice.

