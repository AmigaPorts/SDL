# 27 / Display Routines and Structures / Loading and Displaying the View


To display the [View](../Libraries_Manual_guide/node032B.html#line51), you need to load it using [LoadView()](../Includes_and_Autodocs_2._guide/node0459.html) and turn on the
direct memory access (DMA). A typical call is shown below.


```c
    LoadView(&view);
```
The &view argument is the address of the [View](../Libraries_Manual_guide/node032B.html#line51) structure defined in the
[example above](../Libraries_Manual_guide/node032C.html).

There are two macros, defined in <graphics/[gfxmacros.h](../Includes_and_Autodocs_2._guide/node00B6.html#line22)>, that control
display DMA: ON_DISPLAY and OFF_DISPLAY. They simply turn the display DMA
control bit in the DMA control register on or off.

If you are drawing to the display area and do not want the user to see
intermediate steps in the drawing, you can turn off the display.  Because
OFF_DISPLAY shuts down the display DMA and possibly speeds up other system
operations, it can be used to provide additional memory cycles to the
blitter or the 68000.  The distribution of system DMA, however, allows
four-channel sound, disk read/write, and a sixteen-color, low-resolution
display (or four-color, high-resolution display) to operate at the same
time with no slowdown (7.1 megahertz effective rate) in the operation of
the 68000.  Using OFF_DISPLAY in a multitasking environment may, however,
be an unfriendly thing to do to the other running processes.  Use
OFF_DISPLAY with discretion.

 [A Custom ViewPort Example](../Libraries_Manual_guide/node059D.html)    [Exiting Gracefully](../Libraries_Manual_guide/node0334.html) 

