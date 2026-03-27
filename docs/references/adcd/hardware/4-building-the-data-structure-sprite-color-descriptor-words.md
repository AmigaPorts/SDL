---
title: 4 / / Building the Data Structure / Sprite Color Descriptor Words
manual: hardware
chapter: hardware
section: 4-building-the-data-structure-sprite-color-descriptor-words
functions: []
libraries: []
---

# 4 / / Building the Data Structure / Sprite Color Descriptor Words

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

It takes two color descriptor (data) words to describe each horizontal
line of a sprite; the high order word and the low order word. To calculate
how many color descriptor words you need, multiply the height of the
sprite in lines by 2. The bits in the high order color descriptor word
contribute the leftmost digit of the binary color selector number for each
pixel; the low order word contributes the rightmost digit.

To form the color descriptor words, you first need to form a picture of
the sprite, showing the color of each pixel as a number from 0 - 3. Each
number represents one of the colors in the sprite's  [color registers](hardware/4-sprite-hardware-summary-of-sprite-color-registers.md) . For
example, here is the spaceship sprite again:




                        0000122332210000
                        0001223333221000
                        0012223333222100
                        0001223333221000
                        0000122332210000
Next, you translate each of the numbers in this picture into a binary
number. The first line in binary is shown below. The binary numbers are
represented vertically with the low digit in the top line and the high
digit right below it. This is how the two color descriptor words for each
sprite line are written in memory.


          0 0 0 0 1 0 0 1 1 0 0 1 0 0 0 0    <- Low Sprite Word

          0 0 0 0 0 1 1 1 1 1 1 0 0 0 0 0    <- High Sprite Word
The first line above becomes the color descriptor low word for line 1 of
the sprite. The second line becomes the color descriptor high word. In
this fashion, you translate each line in the sprite into binary 0s and 1s.
See  [Figure 4-7](hardware/4-forming-a-sprite-building-the-data-structure.md) .

Each of the binary numbers formed by the combination of the two data words
for each line refers to a specific  [color register](hardware/4-sprite-hardware-summary-of-sprite-color-registers.md)  in that particular
sprite channel's segment of the color table. Sprite channel 0, for
example, takes its colors from registers 17 - 19. The binary numbers
corresponding to the  [color registers](hardware/4-sprite-hardware-summary-of-sprite-color-registers.md)  for sprite  [DMA channel](hardware/4-displaying-sprite-selecting-dma-channel-and-setting.md) 0 are shown
in Table 4-2.




               Binary Number        Color Register Number
               -------------        ---------------------
                    00                   Transparent
                    01                       17
                    10                       18
                    11                       19


                  Table 4-2: Sprite Color Registers
Recall that binary 00 always means transparent and never refers to a color
except background.

