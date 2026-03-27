---
title: 3 / Forming Basic Playfield / Defining the Size of the Display Window
manual: hardware
chapter: hardware
section: 3-forming-basic-playfield-defining-the-size-of-the-display
functions: []
libraries: []
---

# 3 / Forming Basic Playfield / Defining the Size of the Display Window

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

After you have completely defined the playfield, you need to define the
size of the display window, which is the actual size of the on-screen
display. Adjustment of display window size affects the entire display
area, including the border and the  [sprites](hardware/4-forming-a-sprite-screen-position.md) , not just the playfield. You
cannot display objects outside of the defined display window. Also, the
size of the border around the playfield depends on the size of the display
window.

The basic playfield described in this section is the same size as the
screen display area and also the same size as the display window. This is
not always the case; often the display window is smaller than the actual
"big picture" of the playfield as defined in memory (the raster).

A display window that is smaller than the playfield allows you to
displaysome segment of a large playfield or  [scroll the playfield](hardware/3-playfield-hardware-moving-scrolling-playfields.md)  through
the window. You can also define display windows larger than the basic
playfield.  These larger playfields and different-sized display windows
are described in the section below called
 [Bitplanes and Display Windows of All Sizes](hardware/3-playfield-hardware-bitplanes-and-display-windows-of-all.md) .

You define the size of the display window by specifying the vertical and
horizontal positions at which the window starts and stops and writing
these positions to the display window registers. The resolution of
vertical start and stop is one scan line. The resolution of horizontal
start and stop is one low resolution pixel. Each position on the screen
defines the horizontal and vertical position of some pixel, and this
position is specified by the x and y coordinates of the pixel. This
document shows the x and y coordinates in this form:  (x,y).

Although the coordinates begin at (0,0) in the upper left-hand corner of
the screen, the first horizontal position normally used is $81 and the
first vertical position is $2C. The horizontal and vertical starting
positions are the same both for NTSC and for PAL.

The hardware allows you to specify a starting position before ($81,$2C),
but part of the display may not be visible. The difference between the
absolute starting position of (0,0) and the normal starting position of
($81,$2C) is the result of the way many video display monitors are
designed.

To overcome the distortion that can occur at the extreme edges of the
screen, the scanning beam sweeps over a larger area than the front face of
the screen can display. A starting position of ($81,$2C) centers a normal
size display, leaving a border of eight low resolution pixels around the
display window. Figure 3-9 shows the relationship between the normal
display window, the visible screen area, and the area actually covered by
the scanning beam.


  ($81,$2C) __


```c
              \
       (0,0) __\
               \\
                \\
                 +\----------------------------+
                 |#\###########################|
                 |##\##########################|
                 |###+---------------------+###|
                 |###|  _ _ _ _ _ _ _ _ _  |###|  __ visible screen
                 |###| |   |             | |###| /     boundaries
                 |###|     |               |###|/
                 |###| |----- 320 -------| |###/
                 |###|     |               |##/|
                 |###| |   |             | |#/#|
                 |###|     |               |/##|
                 |###| |                 | |###|
                 |###|    200              |###|
                 |###| |                 | |###|
                 |###|     |               |###|
                 |###| |   |             | |###|
                 |###|     |               |###|
                 |###| |_ _|_ _ _ _ _ _ _| |###|
                 |###|  \               /  |###|
                 |###+---\-------------/---+###|
                 |########\###########/########|
                 |#########\#########/#########|
                 +----------\-------/----------+
                             \     /
                              \   /
                          display window
                 starting and stopping positions


          Figure 3-9: Positioning the On-screen Display
```
 [Setting the Display Window Starting Position](hardware/3-size-display-window-setting-display-window-starting.md) 
 [Setting the Display Window Stopping Position](hardware/3-size-display-window-setting-display-window-stopping.md) 

