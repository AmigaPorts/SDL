---
title: 3 / / Correct Coloring / A Playfield of Three or More Colors
manual: hardware
chapter: hardware
section: 3-correct-coloring-a-playfield-of-three-or-more-colors
functions: []
libraries: []
---

# 3 / / Correct Coloring / A Playfield of Three or More Colors

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For three or more colors, you need more than one bitplane. The task here
is to define each bitplane in such a way that when they are combined for
display, each pixel contains the correct combination of bits. This is a
little more complicated than a playfield of one bitplane. The following
examples show a four-color playfield, but the basic idea and procedures
are the same for playfields containing up to 32 colors.

Figure 3-8 shows two bitplanes forming a four-color playfield:




```c
        Image in                          Results in a display
       bitplane 2            _____          similar to this:
                            |     |
            +---------------- 0 1 | Color 1 -------+
            |               |___ _|                |
            |                   |                  |
            |                   |                  |
          +---+               +---+                |
     0 0 0|0 0|0 0 0     0 0 0|1 1|0 0 0          ***
          |   |               |   |               ***
     0 0 0|0 0|0 0 0     0 0 0|1 1|0 0 0          ***
          |   |               |   |               ***
     0 0 0|0 0|0 0 0     0 0 0|1 1|0 0 0          ***
          +---+               +---+               ***
     1 1 1 0 0 1 1 1     1 1 1 0 0 1 1 1    ······   ······
                                            ······   ······
     1 1 1 0 0 1 1 1     1 1 1 0 0 1 1 1    ······  \······
          +---+               +---+               ···\
     0 0 0|1 1|0 0 0     0 0 0|1 1|0 0 0          ··· \
          |   |               |   |               ···  \
     0 0 0|1 1|0 0 0     0 0 0|1 1|0 0 0          ···   \__   Color 00
          |   |               |   |               ···       (background)
     0 0 0|1 1|0 0 0     0 0 0|1 1|0 0 0          ···
          +---+               +---+                |
            |                   |                  |
            |                ___|_                 |
            |               |     |                |
            +---------------- 1 1 | Color 3 -------+
                            |_____|


                 Figure 3-8: Combining Bitplanes
```
You place the correct "1"s and "0"s in both bitplanes to give each pixel
in the picture above the correct color.

In a single playfield you can combine up to five bitplanes in this way.
Using five bitplanes allows a choice of 32 different colors for any single
pixel. The playfield  [color selection charts](hardware/3-playfield-hardware-summary-of-color-selection-registers.md)  at the end of this chapter
summarize the bit combinations for playfields made from four and five
bitplanes.

