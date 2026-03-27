---
title: 3 / / Picture Larger / Selecting the Display Window Starting Position
manual: hardware
chapter: hardware
section: 3-picture-larger-selecting-the-display-window-starting
functions: []
libraries: []
---

# 3 / / Picture Larger / Selecting the Display Window Starting Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The display window starting position is the horizontal and vertical
coordinates of the upper left-hand corner of the display window. One
register,  [DIWSTRT](hardware/3-size-display-window-setting-display-window-starting.md) , holds both the horizontal and vertical coordinates,
known as HSTART and VSTART. The eight bits allocated to HSTART are
assigned to the first 256 positions, counting from the leftmost possible
position. Thus, you can start the display window at any pixel position
within this range.



```c
      0                         255                      511 ($1FF)
       __________________________|___________________________
      |                          |                           |
      |                          |                           |
      |<------------------------>|                           |
      |        HSTART of         |                           |
      |  DISPLAY WINDOW occurs   |                           |
      |     is this region       |                           |
      |                          |                           |
      |                          |                           |
      |                          |                           |
      |                          |                           |
      |                          |                           |
      |                          |                           |
      |                          |                           |
      |__________________________|___________________________|

      Figure 3-19: Display Window Horizontal Starting Position
```
The eight bits allocated to VSTART are assigned to the first 256 positions
counting down from the top of the display.

       ______________________________________________________
      |                                  /|\                 |  0
      |                                   |                  |
      |                         VSTART of |                  |
      |                    DISPLAY WINDOW |                  |
      |                         occurs in |                  |
      |                       this region |                  |
      |                                   |                  |
      |                                   |                  |
      |                                  \|/                 |
      |------------------------------------------------------+- 255
      |                                                      |
 262 -+------------------- (NTSC)                            |


```c
      |                                                      |
      |______________________________________________________|  383 ($17F)

       Figure 3-20: Display Window Vertical Starting Position
```
Recall that you select the values for the starting position as if the
display were in low resolution, non-interlaced mode. Keep in mind, though,
that for interlaced mode the display window should be an even number of
lines in height to allow for equal-sized odd and even fields.

To set the display window starting position, write the value for HSTART
into bits 0 through 7 and the value for VSTART into bits 8 through 15 of
 [DIWSTRT](hardware/3-size-display-window-setting-display-window-starting.md) .

