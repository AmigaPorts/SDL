---
title: 28 / / Detecting Gel Collisions / VSprite BorderLine
manual: libraries
chapter: libraries
section: 28-detecting-gel-collisions-vsprite-borderline
functions: [InitMasks]
libraries: [graphics.library]
---

# 28 / / Detecting Gel Collisions / VSprite BorderLine

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For faster collision detection, the system uses the [BorderLine](autodocs-2.0/includes-graphics-gels-h.md) member of
the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure. BorderLine specifies the location of the horizontal
logical-OR combination of all of the bits of the object.  It may be
compared to taking the whole object's shadow/collision mask and squishing
it down into a single horizontal line.  You provide the system with a
place to store this line.  The size of the data area you allocate must be
at least as large as the image width.

In other words, if it takes three 16-bit words to hold one line of a GEL,
then you must reserve three words for the [BorderLine](autodocs-2.0/includes-graphics-gels-h.md).  In the VSprite
examples, the routine [makeVSprite()](libraries/lib-examples-animtools-c.md) correctly allocates and initializes
the collision mask and borderline.  For example:


```c
    WORD myBorderLineData[3];  /* reserve space for BorderLine */
                               /* for this Bob */

    myVSprite.BorderLine = myBorderLineData;  /* tell the system */
                                              /* where it is */
```
Here is a sample of an object and its [BorderLine](autodocs-2.0/includes-graphics-gels-h.md) image:


              011000001100    Object
              001100011000
              001100011000
              000110110000
              000010100000

              011110111100    BorderLine image
Using this squished image, the system can quickly determine if the image
is touching the left or rightmost boundary of the drawing area.

To establish default [BorderLine](autodocs-2.0/includes-graphics-gels-h.md) and [CollMask](libraries/28-detecting-gel-collisions-vsprite-collision-mask.md) data, call the [InitMasks()](libraries/28-graphics-sprites-bobs-and-animation-function-reference.md)
function.

---

## See Also

- [InitMasks — graphics.library](../autodocs/graphics.library.md#initmasks)
