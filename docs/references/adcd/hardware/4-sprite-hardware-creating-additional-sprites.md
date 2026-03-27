---
title: 4 Sprite Hardware / Creating Additional Sprites
manual: hardware
chapter: hardware
section: 4-sprite-hardware-creating-additional-sprites
functions: []
libraries: []
---

# 4 Sprite Hardware / Creating Additional Sprites

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To use additional sprites, you must create a  [data structure](hardware/4-forming-a-sprite-building-the-data-structure.md)  for each one
and arrange the display as shown in the previous section, naming the
pointers  [SPR1PTH and SPR1PTL](hardware/4-displaying-sprite-selecting-dma-channel-and-setting.md)  for sprite DMA channel 1,
 [SPR2PTH and SPR2PTL](hardware/4-displaying-sprite-selecting-dma-channel-and-setting.md)  for sprite DMA channel 2, and so on.

   About sprite DMA.
   -----------------
   When you enable sprite DMA for one sprite, you enable DMA for all the
   sprites and place them all in  [automatic mode](hardware/4-sprite-hardware-sprite-hardware-details.md) . Thus, you do not need
   to repeat this step when using additional sprite DMA channels.

Once the sprite DMA channels are enabled, all eight sprite pointers must
be initialized to either a real sprite or a safe null sprite. An
uninitialized sprite could cause spurious sprite video to appear.

Remember that some sprites can become unusable when additional DMA cycles
are allocated to displaying the screen, for example when an extra
 [wide display](hardware/3-bitplanes-and-windows-of-all-sizes-maximum-display-window.md)  or  [horizontal scrolling](hardware/3-horiz-scrolling-specifying-data-fetch-in-horizontal.md)  is enabled (see
 [Figure 6-9: DMA Time Slot Allocation](hardware/hard-pics-6-9-pic.md) ).

Also, recall that each pair of sprites takes its color from different
color registers, as shown in Table 4-3.



                Table 4-3: Color Registers for Sprite Pairs


                    Sprite Numbers    Color Registers
                    --------------    ---------------
                       0 and 1            17 - 19
                       2 and 3            21 - 23
                       4 and 5            25 - 27
                       6 and 7            29 - 31
   Warning:
   --------
   Some sprites become unusable when additional DMA cycles are allocated
   to displaying the screen, e.g. when enabling an extra  [wide display](hardware/3-bitplanes-and-windows-of-all-sizes-maximum-display-window.md)  or

```c
    [horizontal scrolling](hardware/3-horiz-scrolling-specifying-data-fetch-in-horizontal.md). (See  [Figure 6-9: DMA Time Slot Allocation](hardware/hard-pics-6-9-pic.md) .)
```
 [Sprite Priority](hardware/4-creating-additional-sprites-sprite-priority.md) 

