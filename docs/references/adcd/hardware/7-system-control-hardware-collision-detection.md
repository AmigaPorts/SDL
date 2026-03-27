---
title: 7 System Control Hardware / Collision Detection
manual: hardware
chapter: hardware
section: 7-system-control-hardware-collision-detection
functions: []
libraries: []
---

# 7 System Control Hardware / Collision Detection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can use the hardware to detect collisions between one  [sprite group](hardware/7-video-priorities-how-sprites-are-grouped.md) 
and another  [sprite group](hardware/7-video-priorities-how-sprites-are-grouped.md) , any  [sprite group](hardware/7-video-priorities-how-sprites-are-grouped.md)  and either of the
playfields, the two playfields, or any combination of these items.

The first kind of collision is typically used in a game operation to
determine if a missile has collided with a moving player. The second kind
of collision is typically used to keep a moving object within specified
on-screen boundaries. The third kind of collision detection allows you to
define sections of playfield as individual objects, which you may move
using the blitter. This is called playfield animation. If one playfield is
defined as the backdrop or playing area and the other playfield is used to
define objects (in addition to the sprites), you can sense collisions
between the playfield-objects and the sprites or between the
playfield-objects and the other playfield.

 [How Collisions are Determined](hardware/7-collision-detection-how-collisions-are-determined.md) 
 [How To Interpret the Collision Data](hardware/7-collision-detection-how-to-interpret-the-collision-data.md) 
 [How Collision Detection is Controlled](hardware/7-collision-detection-how-collision-detection-is-controlled.md) 

