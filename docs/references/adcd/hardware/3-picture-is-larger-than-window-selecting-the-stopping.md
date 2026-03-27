---
title: 3 / / Picture is Larger than Window / Selecting the Stopping Position
manual: hardware
chapter: hardware
section: 3-picture-is-larger-than-window-selecting-the-stopping
functions: []
libraries: []
---

# 3 / / Picture is Larger than Window / Selecting the Stopping Position

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The stopping position for the display window is the horizontal and
vertical coordinates of the lower right-hand corner of the display window.
One register,  [DIWSTOP](hardware/3-size-display-window-setting-display-window-stopping.md) , contains both coordinates, known as HSTOP and
VSTOP.

See the notes in the "Forming a Basic Playfield" section for instructions
on setting these registers.



```c
      0                         255                      511 ($1FF)
       __________________________|___________________________
      |                          |                           |
      |                          |                           |
      |                          |<------------------------->|
      |                          |        HSTOP of           |
      |                          |   DISPLAY WINDOW occurs   |
      |                          |      is this region       |
      |                          |                           |
      |                          |                           |
      |                          |                           |
      |                          |                           |
      |                          |                           |
      |                          |                           |
      |                          |                           |
      |__________________________|___________________________|

      Figure 3-21: Display Window Horizontal Stopping Position
```
Select a value that represents the correct position in low resolution,
non-interlaced mode.

       ______________________________________________________
      |                                                      |  0
      |                                                      |
      |                                                      |
      |------------------------------------------------------+- 128
      |                             /|\                      |
      |                              |                       |
      |                              | VSTOP of              |
      |                              | DISPLAY WINDOW        |
      |                              | occurs in             |
      |                              | this region           |
 262 -+------------------- (NTSC)    |                       |


```c
      |                              |                       |
      |                              |                       |
      |                             \|/                      |  383 ($17F)
       ------------------------------------------------------

       Figure 3-22: Display Window Vertical Stopping Position
```
To set the display window stopping position, write HSTOP into bits 0
through 7 and VSTOP into bits 8 through 15 of  [DIWSTOP](hardware/3-size-display-window-setting-display-window-stopping.md) .

