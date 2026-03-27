---
title: 3 / Advanced Screen Programming / Double Buffering
manual: libraries
chapter: libraries
section: 3-advanced-screen-programming-double-buffering
functions: [MakeScreen, RethinkDisplay, WaitTOF]
libraries: [graphics.library, intuition.library]
---

# 3 / Advanced Screen Programming / Double Buffering

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Double buffering of an Intuition screen involves the swapping of bitmaps
of the screen, then updating the copper list to install the changes.  The
trick is that after installing the bitmaps to the screen the display is
not updated to access these new bitmaps until the program explicitly
updates the copper list.  Any rendering performed before the copper list
is updated will be rendered into the off-display bitmaps, appearing on the
screen in completed form when the copper list is updated.

First, install the alternate bitmaps into the screen.


```c
    /* switch the bitmap so that we are drawing into the correct place */
    screen->RastPort.BitMap          = myBitMaps[toggleFrame];
    screen->ViewPort.RasInfo->BitMap = myBitMaps[toggleFrame];
```
Rendering may then take place into the off screen bitmaps by drawing into
[screen->RastPort](libraries/3-screen-data-structures-the-intuition-screen-data-structure.md).

The copper list of the screen is updated by calling [MakeScreen()](libraries/3-screen-functions-that-integrate-intuition-and-graphics.md). This
call refreshes the copper list, but does not install it into the system.
Call [RethinkDisplay()](libraries/3-screen-functions-that-integrate-intuition-and-graphics.md) to install the new copper list so that the data is
visible.


```c
    /* update the physical display to match the newly drawn bitmap. */
    MakeScreen(screen); /* Tell intuition to do its stuff.          */
    RethinkDisplay();   /* Intuition compatible MrgCop & LoadView   */
                        /*               it also does a WaitTOF().  */
```
Note that it is possible for the user to force the updating of the
screen's copper list by dragging or depth-arranging the screen. This may
cause information to be displayed before it is complete.

A complete example of double buffering a screen follows.


```c
     [doublebuffer.c](libraries/lib-examples-doublebuffer-c.md) 
```

---

## See Also

- [MakeScreen — intuition.library](../autodocs/intuition.library.md#makescreen)
- [RethinkDisplay — intuition.library](../autodocs/intuition.library.md#rethinkdisplay)
- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
