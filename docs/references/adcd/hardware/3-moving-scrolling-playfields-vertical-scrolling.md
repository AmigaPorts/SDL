---
title: 3 / Moving (Scrolling) Playfields / Vertical Scrolling
manual: hardware
chapter: hardware
section: 3-moving-scrolling-playfields-vertical-scrolling
functions: []
libraries: []
---

# 3 / Moving (Scrolling) Playfields / Vertical Scrolling

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can scroll a playfield upward or downward in the window. Each time you
display the playfield, the bitplane pointers start at a progressively
higher or lower place in the big picture in memory. As the value of the
pointer increases, more of the lower part of the picture is shown and the
picture appears to scroll upward. As the value of the pointer decreases,
more of the upper part is shown and the picture scrolls downward. On an
NTSC system, with a display that has 200 vertical lines, each step can be
as little as 1/200th of the screen. In interlaced mode each step could be
1/400th of the screen if clever manipulation of the pointers is used, but
it is recommended that scrolling be done two lines at a time to maintain
the odd/even field relationship. Using a PAL system with 256 lines on the
display, the step can be 1/256th of a screen, or 1/512th of a screen in
interlace.


```c
     [Figure 3-23: Vertical Scrolling](hardware/hard-pics-3-23-pic.md) 
```
To set up a playfield for vertical scrolling, you need to form bitplanes
tall enough to allow for the amount of scrolling you want, write software
to calculate the bitplane pointers for the scrolling you want, and allow
for the Copper to use the resultant pointers.

Assume you wish to scroll a playfield upward one line at a time. To
accomplish this, before each field is displayed, the bitplane pointers
have to increase by enough to ensure that the pointers begin one line
lower each time. For a normal-sized, low resolution display in which the
modulo is 0, the pointers would be incremented by 40 bytes each time.

