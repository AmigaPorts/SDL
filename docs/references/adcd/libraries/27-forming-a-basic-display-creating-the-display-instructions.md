---
title: 27 / / Forming a Basic Display / Creating the Display Instructions
manual: libraries
chapter: libraries
section: 27-forming-a-basic-display-creating-the-display-instructions
functions: [MakeVPort, MrgCop]
libraries: [graphics.library]
---

# 27 / / Forming a Basic Display / Creating the Display Instructions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Now that you have initialized the system data structures, you can request
that the system prepare a set of display instructions for the Copper using
these structures as input data. During the one or more blank vertical
lines that precede each [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md), the Copper is busy changing the
characteristics of the display hardware to match the characteristics you
expect for this ViewPort. This may include a change in display resolution,
a change in the colors to be used, or other user-defined modifications to
system registers.

Here is the code that creates the display instructions:


```c
    /*  Construct preliminary Copper instruction list.  */
    MakeVPort( &view, &viewPort );
```
In this line of code, &view is the address of the [View](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure and
&viewPort is the address of the first [ViewPort](libraries/27-display-routines-and-structures-viewport-display-memory.md) structure. Using these
structures, the system has enough information to build the instruction
stream that defines your display.

[MakeVPort()](autodocs-2.0/graphics-library-makevport.md) creates a special set of instructions that controls the
appearance of the display. If you are using animation, the graphics
animation routines create a special set of instructions to control the
hardware sprites and the system color registers. In addition, the advanced
user can create special instructions (called user Copper instructions) to
change system operations based on the position of the video beam on the
screen.

All of these special instructions must be merged together before the
system can use them to produce the display you have designed. This is done
by the system routine [MrgCop()](autodocs-2.0/graphics-library-mrgcop.md) (which stands for "Merge Coprocessor
Instructions").  Here is a typical call:


```c
    /* Merge preliminary lists into a real Copper list in the view
       structure.                                                  */
    MrgCop( &view );
```

---

## See Also

- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
