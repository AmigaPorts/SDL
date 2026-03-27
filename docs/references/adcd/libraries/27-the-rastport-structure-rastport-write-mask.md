---
title: 27 / / The RastPort Structure / RastPort Write Mask
manual: libraries
chapter: libraries
section: 27-the-rastport-structure-rastport-write-mask
functions: []
libraries: []
---

# 27 / / The RastPort Structure / RastPort Write Mask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The write mask is a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) variable that determines which of the
bitplanes are currently writable. For most applications, this variable is
set to all bits on.  This means that all bitplanes defined in the [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md)
are affected by a graphics writing operation.  You can selectively disable
one or more bitplanes by simply specifying a 0 bit in that specific
position in the control byte.  For example:


```c
    #include <graphics/gfxmacros.h>

    SetWrMsk(&rastPort, 0xFB);    /* disable bitplane 2 */
```
A useful application for the [Mask](libraries/27-drawing-routines-the-rastport-structure.md) field is to set or clear plane 6 while
in the Extra-Half-Brite display mode to create shadow effects.  For
example:



```c
    SetWrMsk(&rastPort, 0xE0);          /* Disable planes 1 through 5. */

    SetAPen(&rastPort, 0);           /* Clear the Extra-Half-Brite bit */
    RectFill(&rastPort, 20, 20, 40, 30);    /*   in the old rectangle. */

    SetAPen(&rastPort, 32);            /* Set the Extra-Half-Brite bit */
    RectFill(&rastPort, 30, 25, 50, 35);    /*   in the new rectangle. */

    SetWrMsk(&rastPort, -1);                  /* Re-enable all planes. */
```
