---
title: 6 Blitter Hardware / Descending Mode
manual: hardware
chapter: hardware
section: 6-blitter-hardware-descending-mode
functions: []
libraries: []
---

# 6 Blitter Hardware / Descending Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Our standard memory copy blit works fine if the source does not overlap
the destination.  If we want to move an image one row down (towards
increasing addresses), however, we run into a problem -- we overwrite the
second row before we get a chance to copy it!  The blitter has a special
mode of operation -- descending mode -- that solves this problem nicely.

Descending mode is turned on by setting bit one of  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md)  (defined as
BLITREVERSE). If you use descending mode the address pointers will be
decremented by two (bytes) instead of incremented by two for each word
fetched.  In addition, the modulo values will be subtracted rather than
added.   [Shifts](hardware/6-blitter-hardware-shifts-and-masks.md)  are then towards the left, rather than the right, the
first word  [mask](hardware/6-blitter-hardware-shifts-and-masks.md)  masks the last word in a row (which is still the first
word fetched), and the last word  [mask](hardware/6-blitter-hardware-shifts-and-masks.md)  masks the first word in a row.

Thus, for a standard memory copy, the only difference in blitter setup
(assuming no  [shifting](hardware/6-blitter-hardware-shifts-and-masks.md)  or  [masking](hardware/6-blitter-hardware-shifts-and-masks.md) ) is to initialize the
 [address pointer registers](hardware/6-blitter-hardware-dma-channels.md)  to point to the last word in a block, rather
than the first word.  The  [modulo values](hardware/6-blitter-hardware-dma-channels.md) ,  [blit size](hardware/6-blitter-hardware-dma-channels.md) , and all other
parameters should be set the same.

   NOTE:
   -----
   This differs from predecrement versus postincrement in the 680x0,
   where an address register would be initialized to point to the word
   after the last, rather than the last word.

Descending mode is also necessary for  [area filling](hardware/6-blitter-hardware-area-fill-mode.md) , which will be
covered in a later section.

