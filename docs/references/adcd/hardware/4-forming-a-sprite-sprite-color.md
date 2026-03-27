---
title: 4 / Forming a Sprite / Sprite Color
manual: hardware
chapter: hardware
section: 4-forming-a-sprite-sprite-color
functions: []
libraries: []
---

# 4 / Forming a Sprite / Sprite Color

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When sprites are used individually (that is, not attached as described in
the  [Attached Sprites](hardware/4-sprite-hardware-attached-sprites.md)  section), each pixel can be one of three colors
or transparent.  Color selection in similar to the method used for
playfield colors. Figure 4-5 shows how the color of each pixel in a sprite
is determined.

                                                 high-order word of
                                                  sprite data line
   _______________________________
  |            _|#|_              |    _ _0 0 0 0 0 1 1 1 0 1 1 1 0 0 0 0
  |          _|o|#|o|_            |   |
  |_ _ _ _ _|o|o|#|o|o|_ _ _ _ _ _|       |
  |_|_|_|_|#|#|#|_|#|#|#|_|_|_|_|_|- -|   |
  |    |    |o|o|#|o|o|           |       |
  |    |      |o|#|o|             |   |_ _|_0 0 0 0 0 1 1 1 0 1 1 1 0 0 0 0
  |____|________|#|_______________|       |
       |                                  | |      low-order word of
       |                                  | |      sprite data line
                                          | |
  transparent                             | |


                 Forms a binary code,
                   used as the color  --> 0 0
                 choice from a group
                  of color registers.


                   Figure 4-5: Sprite Color Definition
The 0s and 1s in the two  [data words](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md)  that define each line of a sprite in
the  [data structure](hardware/4-forming-a-sprite-building-the-data-structure.md)  form a binary number. This binary number points to
one of the four  [color registers](hardware/4-sprite-hardware-summary-of-sprite-color-registers.md)  assigned to that particular sprite
 [DMA channel](hardware/4-displaying-sprite-selecting-dma-channel-and-setting.md). The eight sprites use system color registers 16 - 31. For
purposes of color selection, the eight sprites are organized into pairs
and each pair uses four of the  [color registers](hardware/4-sprite-hardware-summary-of-sprite-color-registers.md)  as shown in Figure 4-6.

   About sprite  [color registers](hardware/4-sprite-hardware-summary-of-sprite-color-registers.md) .
   -------------------------------
   The color value of the first register in each group of four registers
   is ignored by sprites. When the sprite bits select this register, the
   "transparent" value is used.




                 00  Unused
                 01  Unused
                       ·
                       ·
                       ·         _
                 16  Unused   00  |
                 17  Color 1  01  |
                 18  Color 2  10  |-- Sprites 0 and 1
                 19  Color 3  11 _|
                 20  Unused   00  |
                 21  Color 1  01  |
                 22  Color 2  10  |-- Sprites 2 and 3
                 23  Color 3  11 _|
                 24  Unused   00  |
                 25  Color 1  01  |
                 26  Color 2  10  |-- Sprites 4 and 5
                 27  Color 3  11 _|
                 28  Unused   00  |
                 29  Color 1  01  |
                 30  Color 2  10  |-- Sprites 6 and 7
                 31  Color 3  11 _|


               Figure 4-6: Color Register Assignments
If you require certain colors in a sprite, you will want to load the
sprite's  [color registers](hardware/4-sprite-hardware-summary-of-sprite-color-registers.md)  with those colors. The "Playfield Hardware"
chapter contains instructions on loading  [color registers](hardware/3-bitplanes-and-color-the-color-table.md) .

The binary number 00 is special in this color scheme. A pixel whose value
is 00 becomes transparent and shows the color of any other sprite or play-
field that has lower video priority. An object with low priority appears
"behind" an object with higher priority. Each sprite has a fixed video
priority with respect to all the other sprites. You can vary the priority
between sprites and playfields. (See Chapter 7, "System Control Hardware,"
for more information about  [sprite priority](hardware/7-system-control-hardware-video-priorities.md) .)

