---
title: C / ECS Hardware and Graphics Library / Display Window Specification
manual: hardware
chapter: hardware
section: c-ecs-hardware-and-graphics-library-display-window
functions: [MakeVPort, MrgCop]
libraries: [graphics.library]
---

# C / ECS Hardware and Graphics Library / Display Window Specification

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The new graphics.library and the ECS provide a more powerful display
window specification.  The registers DIWSTRT and DIWSTOP control the
display window size and position:

   DIWSTRT   W   A D     Display Window Start (upper left  vert-hor pos)
   DIWSTOP   W   A D     Display Window Stop  (lower right vert-hor pos)


         Bit   15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
         Use   V7 V6 V5 V4 V3 V2 V1 V0 H7 H6 H5 H4 H3 H2 H1 H0
The way these two registers work has changed.  DIWSTRT used to be
vertically restricted to the upper 2/3 of the display (V8=0), and
horizontally restricted to the left 3/4 of the display (H8=0). DIWSTOP
used to be vertically restricted to the lower 1/2 of the display and
horizontally restricted to the right 1/4 of the display (H8=1).

The V36 graphics.library now supports explicit display window start and
stop positions within a larger and more useful range of values, via
control of the the new DIWHIGH register in the ViewPort copper lists:

   DIWHIGH   W   A D     Display Window upper bits for  start,stop


```c
           Bit     Use
           ---     ---
           15       0
           14       0
           13       H8      Horizontal stop, most significant bit.
           12       0
           11       0
           10       V10 \
            9       V9   }  Vertical stop, most significant 3 bits.
            8       V8  /
            7       0
            6       -
            5       H8      Horizontal start, most significant bit.
            4       0
            3       0
            2       V10 \
            1       V9   }  Vertical stop, most significant 3 bits.
            0       V8  /
```
This is an added register for the ECS chips, and allows larger start and
stop ranges.  If it is not written, the old scheme for DIWSTRT and DIWSTOP
described above holds.  If this register is written last in a sequence of
setting the display window, it sets direct start and stop positions
anywhere on the screen.

   A note on ECS compatibility.
   ----------------------------
   With the enhanced Denise chip present, the graphics.library will set
   up copperlists using the new, explicit display window controls.
   Programs which consistently call MakeVPort(), MrgCop() and Loadview()
   when changing the vertical position of their ViewPort (DxOffset) will
   continue to behave normally.

   Programs which failed to call MakeVPort() when moving the ViewPort
   vertically may not be displayed correctly on a system with ECS.

---

## See Also

- [MakeVPort — graphics.library](../autodocs/graphics.library.md#makevport)
- [MrgCop — graphics.library](../autodocs/graphics.library.md#mrgcop)
