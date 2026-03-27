---
title: 4 Sprite Hardware / Displaying a Sprite
manual: hardware
chapter: hardware
section: 4-sprite-hardware-displaying-a-sprite
functions: []
libraries: []
---

# 4 Sprite Hardware / Displaying a Sprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

After building the  [data structure](hardware/4-forming-a-sprite-building-the-data-structure.md) , you need to tell the system to
display it. This section describes the display of sprites in
 [automatic mode](hardware/4-sprite-hardware-sprite-hardware-details.md)  . In this mode, once the sprite DMA channel begins to
retrieve and display the data, the display continues until the VSTOP
position is reached.  [Manual mode](hardware/4-sprite-hardware-manual-mode.md)  is described later on in this chapter.

The following steps are used in displaying the sprite:

   1. Decide which of the eight sprite DMA channels to use (making certain

```c
      that the chosen channel is available).
```
   2. Set the sprite pointers to tell the system where to find the sprite

      data.
   3. Turn on sprite direct memory access if it is not already on.

   4. For each subsequent display field, during the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md) 

      interval, rewrite the sprite pointers.
   About sprite DMA.
   -----------------
   If sprite DMA is turned off while a sprite is being displayed (that
   is, after VSTART but before VSTOP), the system will continue to
   display the line of sprite data that was most recently fetched. This
   causes a vertical bar to appear on the screen. It is recommended that
   sprite DMA be turned off only during  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  or during some
   portion of the display where you are sure that no sprite is being
   displayed.


```c
     [Selecting a DMA Channel and Setting the Pointers](hardware/4-displaying-sprite-selecting-dma-channel-and-setting.md) 
     [Resetting the Address Pointers](hardware/4-displaying-a-sprite-resetting-the-address-pointers.md) 
     [Sprite Display Example](hardware/hard-examples-sprite-display-asm.md) 
```
