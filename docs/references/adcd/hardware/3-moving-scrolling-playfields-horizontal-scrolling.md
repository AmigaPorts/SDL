---
title: 3 / Moving (Scrolling) Playfields / Horizontal Scrolling
manual: hardware
chapter: hardware
section: 3-moving-scrolling-playfields-horizontal-scrolling
functions: []
libraries: []
---

# 3 / Moving (Scrolling) Playfields / Horizontal Scrolling

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You can scroll playfields horizontally from left to right or right to left
on the screen. You control the speed of scrolling by specifying the amount
of delay in pixels. Delay means that an extra word of data is fetched but
not immediately displayed. The extra word is placed just to the left of
the window's leftmost edge and before normal data fetch. As the display
shifts to the right, the bits in this extra word appear on-screen at the
left-hand side of the window as bits on the right-hand side disappear
off-screen. For each pixel of delay, the on-screen data shifts one pixel
to the right each display field. The greater the delay, the greater the
speed of scrolling. You can have up to 15 pixels of delay. In high
resolution mode, scrolling is in increments of 2 pixels. Figure 3-24 shows
how the delay and extra data fetch combine to cause the scrolling effect.


```c
     [Figure 3-24: Horizontal Scrolling](hardware/hard-pics-3-24-pic.md) 
```
   NOTE: Fetching an extra word for scrolling will disable some  [sprites](hardware/4-sprite-hardware-creating-additional-sprites.md) .

To set up a playfield for horizontal scrolling, you need to:

   *  Define bitplanes wide enough to allow for the scrolling you need.
   *  Set the data-fetch registers to correctly place each horizontal
      line, including the extra word, on the screen.
   *  Set the delay bits.
   *  Set the modulo so that the bitplane pointers begin at the correct
      word for each line.
   *  Write  [Copper instructions](hardware/2-coprocessor-hardware-putting-together-a-copper.md)  to handle the changes during the

```c
       [vertical blanking](hardware/7-setting-and-clearing-bits-vertical-blanking-interrupt.md)  interval.
```
 [Specifying Data Fetch in Horizontal Scrolling](hardware/3-horiz-scrolling-specifying-data-fetch-in-horizontal.md) 
 [Specifying the Modulo in Horizontal Scrolling](hardware/3-horiz-scrolling-specifying-the-modulo-in-horizontal.md) 
 [Specifying Amount of Delay](hardware/3-horizontal-scrolling-specifying-amount-of-delay.md) 

