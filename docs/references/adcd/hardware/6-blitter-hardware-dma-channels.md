---
title: 6 Blitter Hardware / DMA Channels
manual: hardware
chapter: hardware
section: 6-blitter-hardware-dma-channels
functions: []
libraries: []
---

# 6 Blitter Hardware / DMA Channels

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The blitter has four DMA channels -- three source channels, labeled A, B,
and C, and one destination channel, called D.  Each of these channels has
separate address pointer, modulo and data registers and an enable bit. Two
have  [shift registers](hardware/6-blitter-hardware-shifts-and-masks.md) , and one has a first and last word  [mask register](hardware/6-blitter-hardware-shifts-and-masks.md) .
All four share a single blit size register.

The address pointer registers are each composed of two words, named
BLTxPTH and BLTxPTL.  (Here and later, in referring to a register, any "x"
in the name should be replaced by the channel label, A, B, C, or D.) The
two words of each register are adjacent in the 68000 address space, with
the high address word first, so they can both be written with one 32-bit
write from the processor. The pointer registers should be written with an
address in bytes.  Because the blitter works only on words, the least
significant bit of the address is ignored.  Because only Chip memory is
accessible, some of the most significant bits will be ignored as well.  On
machines with 512 KB of Chip memory, the most significant 13 bits are
ignored.  On machines with more Chip memory, fewer bits will are ignored.
A valid, even, Chip memory address should always be written to these
registers.

   Set unused bits to zero.
   ------------------------
   Be sure to write zeros to all unused bits in the custom chip
   registers. These bits may be used by later versions of the custom
   chips.  Writing non-zero values to these bits may cause unexpected
   results on future machines.

Each of the DMA channels can be independently enabled or disabled.  The
enable bits are bits SRCA, SRCB, SRCC, and DEST in control register zero
( [BLTCON0](hardware/a-register-summary-bltcon0-bltcon1.md) ).

When disabled, no memory cycles will be executed for that channel and, for
a source channel, the constant value stored in the data register of that
channel will be used for each blitter cycle.  For this purpose, each of
the three source channels have preloadable data registers, called BLTxDAT.

Images in memory are usually stored in a linear fashion; each word of data
on a line is located at an address that is one greater than the word on
its left. i.e.  Each line is a "plus one" continuation of the previous
line.



                   __________________________________
                  |    |    |    |    |    |    |    |
                  | 20 | 21 | 22 | 23 | 24 | 25 | 26 |
                  |____|____|____|____|____|____|____|
                  |    |    |    |    |    |    |    |
                  | 27 | 28 | 29 | 30 | 31 | 32 | 33 |
                  |____|____|____|____|____|____|____|
                  |    |    |    |    |    |    |    |
                  | 34 | 35 | 36 | 37 | 38 | 39 | 40 |
                  |____|____|____|____|____|____|____|
                  |    |    |    |    |    |    |    |
                  | 41 | 42 | 43 | 44 | 45 | 46 | 47 |
                  |____|____|____|____|____|____|____|
                  |    |    |    |    |    |    |    |
                  | 48 | 49 | 50 | 51 | 52 | 53 | 54 |
                  |____|____|____|____|____|____|____|
                  |    |    |    |    |    |    |    |
                  | 55 | 56 | 57 | 58 | 59 | 60 | 61 |
                  |____|____|____|____|____|____|____|

               Figure 6-1: How Images are Stored in Memory
The map in Figure 6-1 represents a single bitplane (one bit of color) of
an image at word addresses 20 through 61. Each of these addresses accesses
one word (16 pixels) of a single bitplane. If this image required sixteen
colors, four bitplanes like this would be required in memory, and four
copy (move) operations would be required to completely move the image.

The blitter is very efficient at copying such blocks because it needs to
be told only the starting address (20), the destination address, and the
size of the block (height = 6, width = 7). It will then automatically move
the data, one word at a time, whenever the data bus is available. When the
transfer is complete, the blitter will signal the processor with a  [flag](hardware/6-blitter-hardware-interrupt-flag.md) 
and an interrupt.

   NOTE:
   -----
   This copy (move) operation operates on memory and may or may not
   change the memory currently being used for display.

All data copy blits are performed as rectangles of words, with a given
width and height.  All four DMA channels use a single blit size register,
called BLTSIZE, used for both the width and height.  The width can take a
value of from 1 to 64 words (16 to 1024 bits).  The height can run from 1
to 1024 rows.  The width is stored in the least significant six bits of
the BLTSIZE register.  If a value of zero is stored, a width count of 64
words is used.  This is the only parameter in the blitter that is given in
words.  The height is stored in the upper ten bits of the BLTSIZE
register, with zero representing a height of 1024 rows.  Thus, the largest
blit possible with the current Amiga blitter is 1024 by 1024 pixels.
However,  [shifting](hardware/6-blitter-hardware-shifts-and-masks.md)  and  [masking](hardware/6-blitter-hardware-shifts-and-masks.md)  operations may require an extra word be
fetched for each raster scan line, making the maximum practical horizontal
width 1008 pixels.

   Blitter counting.
   -----------------
   To emphasize the above paragraph:  Blit width is in words with a
   zero representing 64 words.  Blit height is in lines with a zero
   representing 1024 lines.

The blitter also has facilities, called modulos, for accessing images
smaller than the entire bitplane.  Each of the four DMA channels has a
16-bit modulo register called BLTxMOD.  As each word is fetched (or
written) for an enabled channel, the address pointer register is
incremented by two (two bytes, or one word). After each row of the blit is
completed, the signed 16-bit modulo value for that DMA channel is added to
the address pointer.  (A row is defined by the width stored in BLTSIZE.)

   About blitter modulos.
   ----------------------
   The modulo values are in bytes, not words.  Since the blitter can
   only operate on words, the least significant bit is ignored.  The
   value is sign-extended to the full width of the address pointer
   registers.  Negative modulos can be useful in a variety of ways, such
   as repeating a row by setting the modulo to the negative of the width
   of the bitplane.

As an example, suppose we want to operate on a section of a full 320 by
200 pixel bitmap that started at row 13, byte 12 (where both are numbered
from zero) and the section is 10 bytes wide.  We would initialize the
pointer register to the address of the bitplane plus 40 bytes per row
times 13 rows, plus 12 bytes to get to the correct horizontal position. We
would set the width to 5 words (10 bytes). At the end of each row, we
would want to skip over 30 bytes to get to the beginning of the next row,
so we would use a modulo value of 30. In general, the width (in words)
times two plus the modulo value (in bytes) should equal the full width, in
bytes, of the bitplane containing the image.

These calculations are illustrated in Figure 6-1 which shows the required
values used in the blitter registers BLTxMOD and BLTxPTR (BLTxPTH and
BLTxPTL).

   About the blitter and ECS.
   --------------------------
   The blitter size and pointer registers have increased range under the
   Enhanced Chip Set (ECS). With the original version of the Amiga's
   custom chips, blits were limited to 1008 by 1024 pixels.  With the
   ECS version of the custom chips, up to  [32K by 32K pixel blits](hardware/c-ecs-hardware-and-the-graphics-library-big-blits.md)  are
   possible.  Refer to Appendix C for more information on ECS and the
   blitter registers.


   <Mem_Addr> = Address (0,0)


```c
         \
          \
           \              BYTE (COLUMN) NUMBER
            \
             \  0        10        20        30       39
              \ |         |         |         |        |
               +----------------------------------------+ - -
              0|········································|    |
              1|········································|
              2|········································|    |
              3|········································|
              4|········································|    |
              5|········································|
              6|········································|    |
              7|········································|
              8|········································|    |
              9|········································|
         ROW 10|········································|    |
      NUMBER 11|········································|
             12|········································|    |- - window
             13|············##########··················|         bitmap
             14|············##########··················|    |
             15|· skip left ##########··· skip right ···|
             16|<---------->##########<---------------->|    |
             17| = 12 bytes ##########··· = 18 bytes ···|
             18|············##########··················|    |
             19|·················\······················|
             20|··················\·····················|    |
              -|···················\····················|
              -|····················\···················|    |
              -|·····················\··················|
              -|······················\················|    |
               +-----------------------\------------\---+ - -
                                        \            \
                                         \            \
                                  image to manipulate  \
                                                        \
                                                      one byte
      BLTxPTR = <Mem_Addr> + (40*13) + 12
              = <Mem_Addr> + 532

      BLTxMOD = 12 + 18
              = 30 bytes


              Figure 6-2: BLTxPTR and BLTxMOD calculations
```
   NOTE:
   -----
   The blitter can be used to process linear rather than rectangular
   regions by setting the horizontal or vertical count in BLTSIZE to 1.

Because each DMA channel has its own modulo register, data can be moved
among bitplanes of different widths.  This is most useful when moving
small images into larger screen bitplanes.

