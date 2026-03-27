---
title: 4 / Forming a Sprite / Screen Position
manual: hardware
chapter: hardware
section: 4-forming-a-sprite-screen-position
functions: []
libraries: []
---

# 4 / Forming a Sprite / Screen Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A sprite's screen position is defined as a set of X,Y coordinates.
Position (0,0), where X = 0 and Y = 0, is the upper left-hand corner of
the display. You define a sprite's location by specifying the coordinates
of its upper left-hand pixel. Sprite position is always defined as though
the display modes were low resolution and non-interlaced. The X,Y
coordinate system and definition of a sprite's position are graphically
represented in Figure 4-1. Notice that because of display overscan,
position (0,0) (that is, X = 0, Y = 0) is not normally in a viewable
region of the screen.




```c
       (0,0) __
               \
                \
                 +-----------------------------+
                 |###############|#############|
                 |###############|#############|
                 |###+-----------|---------+###|
                 |###|                     |###|  __ visible screen
                 |###|        Y axis       |###| /     boundaries
                 |###|                     |###|/
                 |###|           |         |###/
                 |###|           |         |##/|
                 |###|           |         |#/#|
                 |----- X axis --+---+     |/##|
                 |###|           |/*\|     |###|
                 |###|           |***|     |###|
                 |###|           |\*/|     |###|
                 |###|           +---+     |###|
                 |###|                     |###|
                 |###|                     |###|
                 |###|                     |###|
                 |###|                     |###|
                 |###+---------------------+###|
                 |#############################|
                 |#############################|
                 +-----------------------------+


          Figure 4-1: Defining Sprite On-screen Position
```
The amount of viewable area is also affected by the size of the
 [playfield display window](hardware/3-forming-basic-playfield-defining-the-size-of-the-display.md)  (defined by the values in  [DDFSTRT](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md) ,  [DDFSTOP](hardware/3-basic-playfield-telling-the-system-how-to-fetch-and.md) ,
 [DIWSTRT](hardware/3-size-display-window-setting-display-window-starting.md) ,  [DIWSTOP](hardware/3-size-display-window-setting-display-window-stopping.md) , etc.). See the "Playfield Hardware" chapter for more
information about  [overscan and display windows](hardware/3-playfield-hardware-bitplanes-and-display-windows-of-all.md) .

 [Horizontal Position](hardware/4-screen-position-horizontal-position.md) 
 [Vertical Position](hardware/4-screen-position-vertical-position.md) 
 [Clipped Sprites](hardware/4-screen-position-clipped-sprites.md) 

