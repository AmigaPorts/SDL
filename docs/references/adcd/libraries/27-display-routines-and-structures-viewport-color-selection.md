---
title: 27 / Display Routines and Structures / Viewport Color Selection
manual: libraries
chapter: libraries
section: 27-display-routines-and-structures-viewport-color-selection
functions: []
libraries: []
---

# 27 / Display Routines and Structures / Viewport Color Selection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The maximum number of colors that a [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) can display is determined by
the depth of the [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) that the ViewPort displays. The depth is specified
when the BitMap is initialized. See the section below called
"[Preparing the BitMap Structure](libraries/27-forming-a-basic-display-preparing-the-bitmap-structure.md)."

Depth determines the number of bitplanes used to define the colors of the
rectangular image you are trying to build (the raster image) and the
number of different colors that can be displayed at the same time within a
[ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md). For any single pixel, the system can display any one of 4,096
possible colors.

The following table shows depth values and the corresponding number of
possible colors for each value.




```c
    Table 27-1: Depth Values and Number of Colors in the ViewPort


          Colors    Depth Value
          ------    -----------
              2          1
              4          2
              8          3         (Note 1)
             16          4         (Notes 1,2)
             32          5         (Notes 1,2,3)
             16          6         (Notes 1,4)
             64          6         (Notes 1,2,3,5)
          4,096          6         (Notes 1,2,3,6)

        Notes:
        1. Not available for [SUPERHIRES](libraries/27-display-routines-and-structures-viewport-display-modes.md).
        2. Single-playfield mode only - [DUALPF](libraries/27-display-routines-and-structures-viewport-display-modes.md) not one of the
           [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)'s attributes.
        3. Low-resolution mode only - neither [HIRES](libraries/27-display-routines-and-structures-viewport-display-modes.md) nor
           [SUPERHIRES](libraries/27-display-routines-and-structures-viewport-display-modes.md) one of the ViewPort attributes.
        4. Dual Playfield mode - [DUALPF](libraries/27-display-routines-and-structures-viewport-display-modes.md) is an attribute of this
           ViewPort.  Up to eight colors (in three planes) for
           each playfield.
        5. Extra-Half-Brite mode - [EXTRA_HALFBRITE](libraries/27-display-routines-and-structures-viewport-display-modes.md) is an
           attribute of this ViewPort.
        6. Hold-And-Modify mode only - [HAM](libraries/27-display-routines-and-structures-viewport-display-modes.md) is an attribute of
           this ViewPort.
```
The color palette used by a [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) is specified in a [ColorMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md). See the
section called "[Preparing the ColorMap](libraries/27-forming-a-basic-display-preparing-the-colormap-structure.md)" for more information.

Depending on whether single- or dual-playfield mode is used, the system
will use different color register groupings for interpreting the on-screen
colors. The table below details how the depth and the different [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md)
modes affect the registers the system uses.




```c
      Table 27-2: Color Registers Used in Single-playfield Mode


                        Color
           Depth   Registers Used
           -----   --------------
             1          0,1
             2          0-3
             3          0-7
             4          0-15
             5          0-31
             6          0-31       (if [EXTRA_HALFBRITE](libraries/27-display-routines-and-structures-viewport-display-modes.md) is an
                                    attribute of this [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).)

             6          0-15       (if [HAM](libraries/27-display-routines-and-structures-viewport-display-modes.md) is an attribute of
                                    this [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).)
```
The following table shows the five possible combinations when [DUALPF](libraries/27-display-routines-and-structures-viewport-display-modes.md) is an
attribute of the [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md).




        Table 27-3: Color Register Used in Dual-playfield Mode
	   Depth       Color	   Depth       Color

```c
           (PF-1)    Registers     (PF-2)    Registers
           ------    ---------     ------    ---------
             1          0,1          1          8,9
             2          0-3          1          8,9
             2          0-3          2          8-11
             3          0-7          2          8-11
             3          0-7          3          8-15
```
