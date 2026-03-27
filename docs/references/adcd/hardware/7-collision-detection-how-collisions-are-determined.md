---
title: 7 / Collision Detection / How Collisions are Determined
manual: hardware
chapter: hardware
section: 7-collision-detection-how-collisions-are-determined
functions: []
libraries: []
---

# 7 / Collision Detection / How Collisions are Determined

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The video output is formed when the input data from all of the bitplanes
and the sprites is combined into a common data stream for the display. For
each of the pixel positions on the screen, the color of the highest
priority object is displayed. Collisions are detected when two or more
objects attempt to overlap in the same pixel position. This will set a bit
in the  [collision data register](hardware/7-collision-detection-how-to-interpret-the-collision-data.md) .

