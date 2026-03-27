---
title: 6 Blitter Hardware / Area Fill Mode
manual: hardware
chapter: hardware
section: 6-blitter-hardware-area-fill-mode
functions: []
libraries: []
---

# 6 Blitter Hardware / Area Fill Mode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In addition to copying data, the blitter can simultaneously perform a fill
operation during the copy.  The fill operation has only one restriction --
the area to fill must be defined first by drawing untextured lines with
only one bit set per horizontal row.  A special  [line draw mode](hardware/6-blitter-hardware-line-mode.md)  is
available for this operation.  Use a standard copy blit (or any other
blit, as area fills take place after all  [shifts](hardware/6-blitter-hardware-shifts-and-masks.md) ,  [masks](hardware/6-blitter-hardware-shifts-and-masks.md)  and logical
combination of sources).   [Descending mode](hardware/6-blitter-hardware-descending-mode.md)  must be used. Set either the
inclusive-fill-enable bit (FILL_OR, or bit 3) or the exclusive-fill-enable
bit (FILL_XOR, or bit 4) in  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md) . The inclusive fill mode fills
between lines, leaving the lines intact. The exclusive fill mode fills
between lines, leaving the lines bordering the right edge of filled
regions but deleting the lines bordering the left edge. Exclusive fill
yields filled shapes one pixel narrower than the same pattern filled with
inclusive fill.

For instance, the pattern:


    00100100-00011000
filled with inclusive fill, yields:


    00111100-00011000
with exclusive fill, the result would be


    00011100-00001000
(Of course, fills are always done on full 16-bit words.)

There is another bit (FILL_CARRYIN or bit 3 in  [BLTCON1](hardware/a-register-summary-bltcon0-bltcon1.md) ) that forces the
area "outside" the lines be filled; for the above example, with inclusive
fill, the output would be


    11100111-11111111
with exclusive fill, the output would be



    11100011-11110111


             before                          after
     ______________________          ______________________
    |                      |        |                      |
    |                      |        |                      |
    |                      |        |                      |
    |   1   1      1   1   |        |   11111      11111   |
    |    1  1       1  1   |        |    1111       1111   |
    |     1 1        1 1   |        |     111        111   |
    |      11         11   |        |      11         11   |
    |     1 1        1 1   |        |     111        111   |
    |    1  1       1  1   |        |    1111       1111   |
    |   1   1      1   1   |        |   11111      11111   |
    |                      |        |                      |
    |                      |        |                      |
    |______________________|        |______________________|

           Figure 6-5: Use of the FCI Bit - Bit Is a 0
If the FCI bit is a 1 instead of a 0, the area outside the lines is filled
with 1s and the area inside the lines is left with 0s in between.




             before                          after
     ______________________          ______________________
    |                      |        |                      |
    |                      |        |                      |
    |                      |        |                      |
    |   1   1      1   1   |        | 111   1111111   11   |
    |    1  1       1  1   |        | 1111  11111111  11   |
    |     1 1        1 1   |        | 11111 111111111 11   |
    |      11         11   |        | 111111111111111111   |
    |     1 1        1 1   |        | 11111 111111111 11   |
    |    1  1       1  1   |        | 1111  11111111  11   |
    |   1   1      1   1   |        | 111   1111111   11   |
    |                      |        |                      |
    |                      |        |                      |
    |______________________|        |______________________|

           Figure 6-6: Use of the FCI Bit - Bit Is a 1
If you wish to produce very sharp, single-point vertices, exclusive-fill
enable must be used. Figure 6-7 shows how a single-point vertex is
produced using exclusive-fill enable.




             before                   after exclusive fill
     ______________________          ______________________
    |                      |        |                      |
    |                      |        |                      |
    |                      |        |                      |
    |   1   1      1   1   |        |    1111       1111   |
    |    1  1       1  1   |        |     111        111   |
    |     1 1        1 1   |        |      11         11   |
    |      11         11   |        |       1          1   |
    |     1 1        1 1   |        |      11         11   |
    |    1  1       1  1   |        |     111        111   |
    |   1   1      1   1   |        |    1111       1111   |
    |                      |        |                      |
    |                      |        |                      |
    |______________________|        |______________________|

             Figure 6-7: Single-Point Vertex Example
The blitter uses the fill carry-in bit as the starting fill state
beginning at the rightmost edge of each line.  For each "1" bit in the
source area, the blitter flips the fill state, either filling or not
filling the space with ones.  This continues for each line until the left
edge of the blit is reached, at which point the filling stops.

