---
title: 4 Sprite Hardware / Attached Sprites
manual: hardware
chapter: hardware
section: 4-sprite-hardware-attached-sprites
functions: []
libraries: []
---

# 4 Sprite Hardware / Attached Sprites

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can create sprites that have fifteen possible color choices (plus
transparent) instead of three (plus transparent), by "attaching" two
sprites. To create attached sprites, you must:

   *  Use two channels per sprite, creating two sprites of the same

      size and located at the same position.
   *  Set a bit called  [ATTACH](hardware/4-control-registers-spr0ctl.md)  in the  [second sprite control word](hardware/4-building-the-data-structure-sprite-control-word-2-sprxctl.md) .

The fifteen colors are selected from the full range of  [color registers](hardware/4-sprite-hardware-summary-of-sprite-color-registers.md) 
available to sprites -- registers 17 through 31. The extra color choices
are possible because each pixel contains four bits instead of only two as
in the normal, unattached sprite. Each sprite in the attached pair
contributes two bits to the binary color selector number. For example, if
you are using sprite  [DMA channels](hardware/4-displaying-sprite-selecting-dma-channel-and-setting.md)  0 and 1, the high and low order
 [color descriptor words](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md)  for line 1 in both  [data structures](hardware/4-forming-a-sprite-building-the-data-structure.md)  are combined
into line 1 of the attached object.

Sprites can be attached in the following combinations:


                       Sprite 1 to sprite 0
                       Sprite 3 to sprite 2
                       Sprite 5 to sprite 4
                       Sprite 7 to sprite 6
Any or all of these attachments can be active during the same display
field. As an example, assume that you wish to have more colors in the
spaceship sprite and you are using sprite  [DMA channels](hardware/4-displaying-sprite-selecting-dma-channel-and-setting.md)  0 and 1. There
are five colors plus transparent in this sprite.




                         0000154444510000
                         0001564444651000
                         0015676446765100
                         0001564444651000
                         0000154444510000
The first line in this sprite requires the four  [data words](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md)  shown in
Table 4-4 to form the correct binary color selector numbers.


```c
        Table 4-4:  [Data Words](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md)  for First Line of Spaceship Sprite


                           Pixel Number
                           ------------

           15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
```
   ----------------------------------------------------------------------
   Line 1   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   Line 2   0   0   0   0   0   1   1   1   1   1   1   0   0   0   0   0
   Line 3   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   Line 4   0   0   0   0   1   1   0   0   0   0   1   1   0   0   0   0


The highest numbered sprite (number 1, in this example) contributes the
highest order bits (leftmost) in the binary number. The high order
 [data word](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md)  in each sprite contributes the leftmost digit. Therefore, the
lines above are written to the sprite  [data structures](hardware/4-forming-a-sprite-building-the-data-structure.md)  as follows:


        Line 1    Sprite 1 high order word for sprite line 1
        Line 2    Sprite 1 low order word for sprite line 1
        Line 3    Sprite 0 high order word for sprite line 1
        Line 4    Sprite 0 low order word for sprite line 1
See  [Figure 4-7](hardware/4-forming-a-sprite-building-the-data-structure.md)  for the order these words are stored in memory. Remember
that this data is contained in two sprite structures.

The binary numbers 0 through 15 select registers 17 through 31 as shown in
Table 4-5.




```c
          Table 4-5: Color Registers in Attached Sprites


            Decimal        Binary     Color Register
            Number         Number         Number
            -------        ------     --------------
               0            0000            16 *
               1            0001            17
               2            0010            18
               3            0011            19
               4            0100            20
               5            0101            21
               6            0110            22
               7            0111            23
               8            1000            24
               9            1001            25
              10            1010            26
              11            1011            27
              12            1100            28
              13            1101            29
              14            1110            30
              15            1111            31


              * Unused; yields transparent pixel.
```
Attachment is in effect only when the  [ATTACH](hardware/4-control-registers-spr0ctl.md)  bit, bit 7 in sprite
 [control word 2](hardware/4-building-the-data-structure-sprite-control-word-2-sprxctl.md) , is set to 1 in the  [data structure](hardware/4-forming-a-sprite-building-the-data-structure.md)  for the odd-numbered
sprite. So, in this example, you set bit 7 in sprite  [control word 2](hardware/4-building-the-data-structure-sprite-control-word-2-sprxctl.md)  in
the  [data structure](hardware/4-forming-a-sprite-building-the-data-structure.md)  for sprite 1.

When the sprites are moved, the Copper list must keep them both at exactly
the same position relative to each other. If they are not kept together on
the screen, their pixels will change color. Each sprite will revert to
three colors plus transparent, but the colors may be different than if
they were ordinary, unattached sprites. The color selection for the lower
numbered sprite will be from color registers 17-19. The color selection
for the higher numbered sprite will be from color registers 20, 24, and 28.

The following  [data structure](hardware/4-forming-a-sprite-building-the-data-structure.md)  is for the six-color spaceship made with two
attached sprites.

SPRITE0:
```c
        DC.W    $6D60,$7200     ;VSTART = 65, HSTART = 128
        DC.W    $0C30,$0000     ;First  [color descriptor word](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md) 
        DC.W    $1818,$0420
        DC.W    $342C,$0E70
        DC.W    $1818,$0420
        DC.W    $0C30,$0000
        DC.W    $0000,$0000     ;End of sprite 0
```
SPRITE1:

```c
        DC.W    $6D60,$7280     ;Same as sprite 0 except  [attach](hardware/4-control-registers-spr0ctl.md)  bit on
        DC.W    $07E0,$0000     ;First descriptor word for sprite 1
        DC.W    $0FF0,$0000
        DC.W    $1FF8,$0000
        DC.W    $0FF0,$0000
        DC.W    $07E0,$0000
        DC.W    $0000,$0000     ;End of sprite 1
```
