---
title: 4 Sprite Hardware / Sprite Hardware Details
manual: hardware
chapter: hardware
section: 4-sprite-hardware-sprite-hardware-details
functions: []
libraries: []
---

# 4 Sprite Hardware / Sprite Hardware Details

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Sprites are produced by the circuitry shown in Figure 4-13. This figure
shows in block form how a pair of  [data words](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md)  becomes a set of pixels
displayed on the screen.


```c
     [Figure 4-13: Sprite Control Circuitry](hardware/hard-pics-4-13-pic.md) 
```
The circuitry elements for sprite display are explained below.

*  Sprite data registers.
   ----------------------
   The registers  [SPRxDATA and SPRxDATB](hardware/4-summary-of-sprite-registers-data-registers.md)  hold the bit patterns that
   describe one horizontal line of a sprite for each of the eight
   sprites. A line is 16 pixels wide, and each line is defined by two
   words to provide selection of three colors and transparent.

*  Parallel-to-serial converters.
   ------------------------------
   Each of the 16 bits of the sprite data bit pattern is individually
   sent to the color select circuitry at the time that the pixel
   associated with that bit is being displayed on-screen.

   Immediately after the data is transferred from the sprite data
   registers, each parallel-to-serial converter begins shifting the bits
   out of the converter, most significant (leftmost) bit first. The
   shift occurs once during each low resolution pixel time and continues
   until all 16 bits have been transferred to the display circuitry. The
   shifting and data output does not begin again until the next time
   this converter is loaded from the data registers.

   Because the video image is produced by an electron beam that is being
   swept from left to right on the screen, the bit image of the data
   corresponds exactly to the image that actually appears on the screen
   (most significant data on the left).

*  Sprite serial video data.
   -------------------------
   Sprite data goes to the  [priority circuit](hardware/7-video-priorities-setting-the-priority-control-register.md) to establish the priority
   between sprites and playfields.

*  Sprite position registers.
   --------------------------
   These registers, called  [SPRxPOS](hardware/4-control-registers-spr0pos.md) , contain the horizontal position
   value (X value) and vertical position value (Y value) for each of the
   eight sprites.

*  Sprite control registers.
   -------------------------
   These registers, called  [SPRxCTL](hardware/4-control-registers-spr0ctl.md) , contain the stopping position for
   each of the eight sprites and whether or not a sprite is  [attached](hardware/4-sprite-hardware-attached-sprites.md).

*  Beam counter.
   -------------
   The  [beam counter](hardware/7-system-control-hardware-beam-position-detection.md)  tells the system the current location of the video
   beam that is producing the picture.

*  Comparator.
   -----------
   This device compares the value of the beam counter to the Y value in
   the position register  [SPRxPOS](hardware/4-control-registers-spr0pos.md) . If the beam has reached the position
   at which the leftmost upper pixel of the sprite is to appear, the
   comparator issues a load signal to the serial-to-parallel converter
   and the sprite display begins.

Figure 4-13 shows the following:

*  Writing to the sprite control registers disables the horizontal
   comparator circuitry. This prevents the system from sending any
   output from the data registers to the serial converter or to the
   screen.

*  Writing to the sprite A data register enables the horizontal
   comparator. This enables output to the screen when the horizontal
   position of the video beam equals the horizontal value in the
   position register.

*  If the comparator is enabled, the sprite data will be sent to the
   display, with the leftmost pixel of the sprite data placed at the
   position defined in the horizontal part of  [SPRxPOS](hardware/4-control-registers-spr0pos.md) .

*  As long as the comparator remains enabled, the current contents of
   the sprite data register will be output at the selected horizontal
   position on a video line.

*  The data in the sprite data registers does not change. It is either
   rewritten by the user or modified under DMA control.

The components described above produce the automatic DMA display as
follows: When the sprites are in DMA mode, the 18-bit sprite pointer
register (composed of  [SPRxPTH and SPRxPTL](hardware/4-displaying-sprite-selecting-dma-channel-and-setting.md) ) is used to read the first two
words from the sprite  [data structure](hardware/4-forming-a-sprite-building-the-data-structure.md) . These words contain the starting
and stopping position of the sprite. Next, the pointers write these words
into  [SPRxPOS](hardware/4-control-registers-spr0pos.md)  and  [SPRxCTL](hardware/4-control-registers-spr0ctl.md) . After this write, the value in the pointers
points to the address of the first  [data word](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md)  (low word of data for line
1 of the sprite.)

Writing into the  [SPRxCTL](hardware/4-control-registers-spr0ctl.md)  register disabled the sprite. Now the sprite
DMA channel will wait until the vertical beam counter value is the same as
the data in the VSTART (Y value) part of  [SPRxPOS](hardware/4-control-registers-spr0pos.md) . When these values
match, the system enables the sprite data access.

The sprite DMA channel examines the contents of VSTOP (from  [SPRxCTL](hardware/4-control-registers-spr0ctl.md) ,
which is the location of the line after the last line of the sprite) and
VSTART (from  [SPRxPOS](hardware/4-control-registers-spr0pos.md) ) to see how many lines of sprite data are to be
fetched. Two words are fetched per line of sprite height, and these words
are written into the sprite data registers. The first word is stored in
 [SPRxDATA](hardware/4-sprite-hardware-sprite-hardware-details.md)  and the second word in  [SPRxDATB](hardware/4-sprite-hardware-sprite-hardware-details.md) .

The fetch and store for each horizontal scan line occurs during a
horizontal blanking interval, far to the left of the start of the screen
display. This arms the sprite horizontal comparators and allows them to
start the output of the sprite data to the screen when the horizontal beam
count value matches the value stored in the HSTART (X value) part of
 [SPRxPOS](hardware/4-control-registers-spr0pos.md) .

If the count of VSTOP - VSTART equals zero, no sprite output occurs. The
next data word pair will be fetched, but it will not be stored into the
sprite data registers. It will instead become the next pair of data words
for  [SPRxPOS](hardware/4-control-registers-spr0pos.md)  and  [SPRxCTL](hardware/4-control-registers-spr0ctl.md) .

When a sprite is used only once within a single display field, the final
pair of data words, which follow the sprite  [color descriptor words](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md) , is
loaded automatically as the next contents of the  [SPRxPOS](hardware/4-control-registers-spr0pos.md)  and  [SPRxCTL](hardware/4-control-registers-spr0ctl.md) 
registers. To stop the sprite after that first data set, the pair of words
should contain all zeros.

Thus, if you have formed a sprite pattern in memory, this same pattern
will be produced as pixels automatically under DMA control one line at a
time.

