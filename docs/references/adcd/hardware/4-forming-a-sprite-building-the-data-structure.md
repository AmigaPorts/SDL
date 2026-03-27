---
title: 4 / Forming a Sprite / Building the Data Structure
manual: hardware
chapter: hardware
section: 4-forming-a-sprite-building-the-data-structure
functions: []
libraries: []
---

# 4 / Forming a Sprite / Building the Data Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

After defining the sprite, you need to build its data structure, which is
a series of 16-bit words in a contiguous memory area. Some of the words
contain position and control information and some contain color
descriptions. To create a sprite's data structure, you need to:

   *  Write the  [horizontal](hardware/4-screen-position-horizontal-position.md)  and  [vertical position](hardware/4-screen-position-vertical-position.md)  of the sprite into

      the first control word.
   *  Write the vertical stopping position into the second control word.

   *  Translate the decimal color numbers 0 - 3  in your sprite grid

```c
      picture into binary color numbers. Use the binary values to build
      color descriptor (data) words and write these words into the data
      structure.
```
   *  Write the control words that indicate the end of the sprite data

      structure.
   Warning:
   --------
   Sprite data, like all other data accessed by the custom chips, must
   be loaded into Chip RAM. Be sure all of your sprite data structures
   are word aligned in Chip Memory.

Table 4-1 shows a sprite data structure with the memory location and
function of each word:


 Memory
 Location   16-bit Word                 Function
 --------   -----------                 --------
   N     Sprite control word 1       Vertical and horizontal start position
   N+1   Sprite control word 2       Vertical stop position
   N+2   Color descriptor low word   Color bits for line 1
   N+3   Color descriptor high word  Color bits for line 1
   N+4   Color descriptor low word   Color bits for line 2
   N+5   Color descriptor high word  Color bits for line 2


                  -
                  -
                  -
         End-of-data words           Two words indicating
                                     the next usage of this sprite


              Table 4-1: Sprite Data Structure
All memory addresses for sprites are word addresses. You will need enough
contiguous memory to provide room for two words for the control
information, two words for each horizontal line in the sprite, and two
end-of-data words.

Because this data structure must be accessible by the special-purpose
chips, you must ensure that this data is located within chip memory.

Figure 4-7 shows how the data structure relates to the sprite.


          <- - - - 16 bits - - - - ->
          ___________________________  __
      |  |                           |   |    Each group of words
         |      VSTART, HSTART       |   |    defines one vertical
      |  |---------------------------|   |    usage of a sprite.
         |    VSTOP, control bits    |   |--- Each one contains the
      |  |___________________________|   |    starting location and
                                         |    physical appearance
      |   ___________________________  - | -  of this sprite image.
         |                           |   |  |
      |  | low word of data, line 1  |   |
         |---------------------------|   |  |
      |  | high word of data, line 1 |   |
         |___________________________|   |  |
      |                                  |
               ------                    |  |
  increasing   ------  data describing   |       Pairs of words
  addresses    ------  central lines     |  |- - containing color


               ------  if this sprite    |       information for
      |        ------                    |  |    pixel lines.
          ___________________________    |
      |  |                           |   |  |
         | low word of data, line 1  |   |
      |  |---------------------------|   |  |
         | high word of data, line 1 |   |
      |  |___________________________| __|  |
                                       - - -
      |   ___________________________
         |                           |        Last word pair contains
      |  |     0000000000000000      |        all zeros if this sprite
         |---------------------------|- - - - processor is to used
      |  |     0000000000000000      |        only once vertically in
     \|/ |___________________________|        the display frame.


            Part of a screen display
            _______________________
           |                       |
           |                       |
           |                       |
           |                       |
           |                       |
           |          HSTART       |
           |                       |
           |            |          |            Each word pair
           |                       |          ___________________
           |  VSTART _ _|  _       |         |                   |
           |             _/_\_  _ _|_ _      | low word of pair  |
           |            |_____| _ _|_ _ <----|-------------------|
           |   VSTOP _ _  \_/      |         | high word of pair |
           |            |     |    |         |___________________|
           |                       |
           |            |<--->|    |          describes one video
           |_______________________|          line of the sprite


                    Figure 4-7: Data Structure Layout
 [Sprite Control Word 1 : SPRxPOS](hardware/4-building-the-data-structure-sprite-control-word-1-sprxpos.md)      [Sprite Color Descriptor Words](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md) 
 [Sprite Control Word 2 : SPRxCTL](hardware/4-building-the-data-structure-sprite-control-word-2-sprxctl.md)      [End-of-data Words](hardware/4-building-the-data-structure-end-of-data-words.md) 

