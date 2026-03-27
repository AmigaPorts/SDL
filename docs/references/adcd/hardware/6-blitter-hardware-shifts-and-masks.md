---
title: 6 Blitter Hardware / Shifts and Masks
manual: hardware
chapter: hardware
section: 6-blitter-hardware-shifts-and-masks
functions: []
libraries: []
---

# 6 Blitter Hardware / Shifts and Masks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Up to now we have dealt with the blitter only in moving words of memory
around and combining them with logic operations.  This is sufficient for
 [moving graphic images](hardware/6-function-generator-designing-the-lf-control-byte-with.md)  around, so long as the images stay in the same
position relative to the beginning of a word.  If our car image has its
leftmost pixel on the second pixel from the left, we can easily draw it on
the screen in any position where the leftmost pixel also starts two pixels
from the beginning of some word.  But often we want to draw that car
shifted left or right by a few pixels. To this end, both the A and B
 [DMA channels](hardware/6-blitter-hardware-dma-channels.md)  have a barrel shifter that can shift an image between 0 and
15 bits.

This shifting operation is completely free; it requires no more time to
execute a blit with shifts than a blit without shifts, as opposed to
shifting with the 680x0.  The shift is normally towards the right. This
shifter allows movement of images on pixel boundaries, even though the
pixels are addressed 16 at a time by each word address of the bitplane
image.

So if the incoming data is shifted to the right, what is shifted in
from the left?  For the first word of the blit, zeros are shifted in; for
each subsequent word of the same blit, the data shifted out from the
previous word is shifted in.

The shift value for the A channel is set with bits 15 through 12 of
 [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md) ; the B shift value is set with bits 15 through 12 of  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md) .
For most operations, the same value will be used for both shifts.  For
shifts of greater than fifteen bits, load the  [address register pointer](hardware/6-blitter-hardware-dma-channels.md) 
of the destination with a higher address; a shift of 100 bits would
require the  [destination pointer](hardware/6-blitter-hardware-dma-channels.md)  to be advanced 100/16 or 6 words (12
bytes), and a right shift of the remaining 4 bits to be used.

As an example, let us say we are doing a blit that is three words wide,
two words high, and we are using a shift of 4 bits.  For simplicity, let
us assume we are doing a straight copy from A to D.  The first word that
will be written to D is the first word fetched from A, shifted right four
bits with zeros shifted in from the left.  The second word will be the
second word fetched from the A, shifted right, with the least significant
(rightmost) four bits of the first word shifted in. Next, we will write
the first word of the second row fetched from A, shifted four bits, with
the least significant four bits of the last word from the first row
shifted in. This would continue until the blit is finished.

On shifted blits, therefore, we only get zeros shifted in for the first
word of the first row. On all other rows the blitter will shift in the
bits that it shifted out of the previous row. For most graphics
applications, this is undesirable.  For this reason, the blitter has the
ability to mask the first and last word of each row coming through the A
 [DMA channel](hardware/6-blitter-hardware-dma-channels.md) .

Thus, it is possible to extract rectangular data from a source whose right
and left edges are between word boundaries. These two registers are called
BLTAFWM and BLTALWM, for blitter A channel first and last word masks.
When not in use, both should be initialized to all ones ($FFFF).

   A note about fonts.
   -------------------
   Text fonts on the Amiga are stored in a packed bitmap.  Individual
   characters from the font are extracted using the blitter, masking out
   unwanted bits.  The character may then be positioned to any pixel
   alignment by shifting it the appropriate amount.

These masks are "anded" with the source data, before any shifts are
applied. Only when there is a 1 bit in the first-word mask will that bit
of source A actually appear in the logic operation. The first word of each
row is anded with BLTAFWM, and the last word is "anded" with BLTALWM.  If
the width of the row is a single word, both masks are applied
simultaneously.

The masks are also useful for extracting a certain range of "columns" from
some bitplane.  Let us say we have, for example, a predrawn rectangle
containing text and graphics that is 23 pixels wide.  The leftmost edge is
the leftmost bit in its bitmap, and the bitmap is two words wide.  We wish
to render this rectangle starting at pixel position 5 into our 320 by 200
screen bitmap, without disturbing anything that lies outside of the
rectangle.



```c
                 |<--------- two word source bitmap -------->|
                 |                                           |
                 |<--- extract a 32-bit image --->|          |
                 |                                |          |
                 |<--- 16-bit word -->|           |          |
                 |____________________|___________|__________|
                 |                                           |
    source       | 00000000  00000000     00000000  00000000 |
    DMA B        | 11111111  11111111     11111111  11111111 |
                 | 10101010  01010101     10101010  01010101 |
                 |___________________________________________|
                       |         |          |         |
                 Source is passed through mask when it is one,
                     outherwise the destination is copied.
                       |         |          |         |
                  _____v_________v____   ___v_________v______
                 |                    | |                    |
    mask on      | 11111111  11111111 | | 11111110  00000000 |
    DMA A        |  first word mask   | |  second word mask  |
                 |____________________| |____________________|
                       |         |          |  ||     |
                       |         |          |  |-     -
                  _____v_________v__________v__v_____________
    final        |                                           |
    destination  | 00000000  00000000     00000000  11111111 |
    DMA D        | 11111111  11111111     11111111  11111111 |
    (points to   | 10101010  01010101     10101010  11111111 |
    same address |___________________________________________|
    as DMA C)                                   ^   ^  ^   ^
                       -         -         -    |   |  |   | <-+
                  _____|_________|_________|____|___|__|___|_  |
    destination  |                                           | |
    before blit  | 00000000  00000000     00000000  00000000 | |
    DMA C        | 11111111  11111111     11111111  11111111 | |
    (to be       | 10101010  01010101     10101010  01010101 | |
    overwritten) |___________________________________________| |
                                                               |
                 Destination does not change where mask is 0 --+


                   Figure 6-4: Extracting a Range of Columns
```
To do this, we point the B  [DMA channel](hardware/6-blitter-hardware-dma-channels.md)  at the bitmap containing the
source image, and the D  [DMA channel](hardware/6-blitter-hardware-dma-channels.md)  at the screen bitmap. We use a shift
value of 5.  We also point the C  [DMA channel](hardware/6-blitter-hardware-dma-channels.md)  at the screen bitmap. We
use a blit width of 2 words. What we need is a simple copy operation,
except we wish to leave the first five bits of the first word, and the
last four bits (2 times 16, less 23, less 5) of the last word alone. The A
 [DMA channel](hardware/6-blitter-hardware-dma-channels.md)  comes to the rescue.  We preload the A  [data register](hardware/6-blitter-hardware-dma-channels.md)  with
$FFFF (all ones), and use a first word mask with the most significant five
bits set to zero ($07FF) and a last word mask with the least significant
four bits set to zero ($FFF0).  We do not enable the A  [DMA channel](hardware/6-blitter-hardware-dma-channels.md) , but
only the B, C, and D channels, since we want to use the A channel as a
simple row mask. We then wish to pass the B (source) data along wherever
the A channel is 1 (for a  [minterm](hardware/6-function-generator-designing-the-lf-control-byte-with.md)  of AB) and pass along the original
destination data (from the C channel) wherever A is 0
                    _
(for a  [minterm](hardware/6-function-generator-designing-the-lf-control-byte-with.md)  of AC),
                                               _
yielding our classic cookie-cut function of AB+AC, or $CA.

   About disabling.
   ----------------
   Even though the A channel is disabled, we use it in our logic
   function and preload the  [data register](hardware/6-blitter-hardware-dma-channels.md) .  Disabling a channel simply
   turns off the memory fetches for that channel; all other operations
   are still performed, only from a constant value stored in the
   channel's  [data register](hardware/6-blitter-hardware-dma-channels.md) .

An alternative but more subtle way of accomplishing the same thing is to
use an A shift of five, a first word mask of all ones, and a last word
mask with the rightmost nine bits set to zero.  All other registers remain
the same.

   Warning:
   --------
   Be sure to load the blitter immediate  [data registers](hardware/6-blitter-hardware-dma-channels.md)  only after
   setting the shift count in  [BLTCON0/BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md) , as loading the
```c
    [data registers](hardware/6-blitter-hardware-dma-channels.md)  first will lead to unpredictable results. For instance,
```
   if the last person left BSHIFT to be "4", and I load BDATA with "1" and
   then change BSHIFT to "2", the resulting BDATA that is used is
   "1<<4", not "1<<2". The act of loading one of the  [data registers](hardware/6-blitter-hardware-dma-channels.md) 
   "draws" the data through the machine and shifts it.

