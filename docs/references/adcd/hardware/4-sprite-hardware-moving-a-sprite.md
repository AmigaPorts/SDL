---
title: 4 Sprite Hardware / Moving a Sprite
manual: hardware
chapter: hardware
section: 4-sprite-hardware-moving-a-sprite
functions: []
libraries: []
---

# 4 Sprite Hardware / Moving a Sprite

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A sprite generated in  [automatic mode](hardware/4-sprite-hardware-sprite-hardware-details.md)  can be moved by specifying a
different position in the  [data structure](hardware/4-forming-a-sprite-building-the-data-structure.md) . For each display field, the
data is reread and the sprite redrawn. Therefore, if you change the
position data before the sprite is redrawn, it will appear in a new
position and will seem to be moving.

You must take care that you are not moving the sprite (that is, changing
 [control word](hardware/4-forming-a-sprite-building-the-data-structure.md)  data) at the same time that the system is using that data
to find out where to display the object. If you do so, the system might
find the start position for one field and the stop position for the
following field as it retrieves data for display. This would cause a
"glitch" and would mess up the screen. Therefore, you should change the
content of the  [control words](hardware/4-forming-a-sprite-building-the-data-structure.md)  only during a time when the system is not
trying to read them. Usually, the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  period is a safe
time, so moving the sprites becomes part of the  [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  tasks
and is handled by the Copper as shown in the example below.

As sprites move about on the screen, they can collide with each other or
with either of the two playfields. You can use the hardware to detect
these collisions and exploit this capability for special effects. In
addition, you can use collision detection to keep a moving object within
specified on-screen boundaries.  [Collision Detection](hardware/7-system-control-hardware-collision-detection.md)  is described in
Chapter 7, "System Control Hardware."


```c
     [sprite_move.asm](hardware/hard-examples-sprite-move-asm.md) 
```
