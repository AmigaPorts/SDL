---
title: 4 / / Screen Position / Vertical Position
manual: hardware
chapter: hardware
section: 4-screen-position-vertical-position
functions: []
libraries: []
---

# 4 / / Screen Position / Vertical Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can select any position from line 0 to line 262 for the topmost edge
of the sprite. In the examples in this chapter, an NTSC window with
vertical positions from line 44 to line 243 is used. This allows the
normal display height of 200 lines in non-interlaced mode. If you specify
a vertical position (Y value) of less than 44 (i.e., above the top of the
display window) the top edge of the sprite may not appear on screen.

To make a sprite appear in its correct on-screen vertical position, add
the Y value to the desired position. Using the above numbers, add 44 to
the desired Y position. For example, to make the upper leftmost pixel
appear 25 lines below the top edge of the screen, perform this calculation:

 Desired Y position + vertical-offset of the display window = 25 + 44 = 69

Thus, 69 is the Y value you will write into the  [data structure](hardware/4-forming-a-sprite-building-the-data-structure.md) .

