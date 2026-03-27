---
title: 4 / Displaying Sprite / Selecting DMA Channel and Setting Pointers
manual: hardware
chapter: hardware
section: 4-displaying-sprite-selecting-dma-channel-and-setting
functions: []
libraries: []
---

# 4 / Displaying Sprite / Selecting DMA Channel and Setting Pointers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In deciding which DMA channel to use, you should take into consideration
the colors assigned to the sprite and the  [sprites video priority](hardware/4-creating-additional-sprites-sprite-priority.md) .

The sprite DMA channel uses two pointers to read in sprite  [data](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md)  and
 [control words](hardware/4-forming-a-sprite-building-the-data-structure.md) . During the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  interval before the first
display of the sprite, you need to write the sprite's memory address into
these pointers. The pointers for each sprite are called SPRxPTH and
SPRxPTL, where "x" is the number of the sprite DMA channel. SPRxPTH
contains the high three bits of the memory address of the first word in
the sprite and SPRxPTL contains the low sixteen bits. The least
significant bit of SPRxPTL is ignored, as sprite data must be word
aligned. Thus, only fifteen bits of SPRxPTL are used. As usual, you can
write a long word into SPRxPTH.

In the following example the processor initializes the data pointers for
sprite 0. Normally, this is done by the Copper. The sprite is at address
$20000.


```c
     MOVE.L  #$20000,SPR0PTH+CUSTOM  ;Write $20000 to sprite 0 pointer...
```
These pointers are dynamic; they are incremented by the sprite DMA channel
to point first to the  [control words](hardware/4-forming-a-sprite-building-the-data-structure.md) , then to the  [data words](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md) , and
finally to the  [end-of-data words](hardware/4-building-the-data-structure-end-of-data-words.md) . After reading in the sprite control
information and storing it in other registers, they proceed to read in the
 [color descriptor words](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md) . The  [color descriptor words](hardware/4-building-the-data-structure-sprite-color-descriptor-words.md)  are stored in
sprite data registers, which are used by the sprite DMA channel to display
the data on screen. For more information about how the sprite DMA channels
handle the display, see the  [Hardware Details](hardware/4-sprite-hardware-sprite-hardware-details.md)  section below.

