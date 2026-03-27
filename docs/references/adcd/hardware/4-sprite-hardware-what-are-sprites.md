---
title: 4 Sprite Hardware / What are Sprites?
manual: hardware
chapter: hardware
section: 4-sprite-hardware-what-are-sprites
functions: []
libraries: []
---

# 4 Sprite Hardware / What are Sprites?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Sprites are graphic objects that are created and moved independently of
the playfield display and independently of each other. Together with
playfields, sprites form the graphics display of the Amiga.  You can
create more complex  [animation](hardware/6-function-generator-designing-the-lf-control-byte-with.md)  effects by using the blitter, which is
described in the chapter called "Blitter Hardware." Sprites are produced
on-screen by eight special-purpose sprite  [DMA channels](hardware/4-displaying-sprite-selecting-dma-channel-and-setting.md) . Basic sprites
are 16 pixels wide and any number of lines high. You can choose from three
colors for a sprite's pixels, and a pixel may also be transparent, showing
any object behind the sprite. For larger or more complex objects, or for
more color choices, you can  [combine sprites](hardware/4-sprite-hardware-attached-sprites.md) .

Sprite DMA channels can be  [reused](hardware/4-sprite-hardware-reusing-sprite-dma-channels.md)  several times within the same display
field. Thus, you are not limited to having only eight sprites on the
screen at the same time.

